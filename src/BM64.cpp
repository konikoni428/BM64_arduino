#include "BM64.h"

USE_DEBUG

void BM64::getStatus(){
    sendCommand(BM64_GET_UART_VERSION_CMD, 0x00);
}

void BM64::linkBack(){
    sendCommand(0x17, 0x00);
}

void BM64::getPhoneName1(){
    sendCommand(0x16, 0x00, 0x00);
}
void BM64::getPhoneName2(){
    sendCommand(0x16, 0x01, 0x00);
}

void BM64::getSongName(uint8_t link_index){
    uint8_t opCode = 0x0B;
    uint8_t params [22] = {link_index, 0x20, 0x00, 0x00, 0x11, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x07};
    sendCommand(opCode, params, 23, true);
}

void BM64::getArtistName(uint8_t link_index){
    uint8_t opCode = 0x0B;
    uint8_t params [22] = {link_index, 0x20, 0x00, 0x00, 0x11, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x07};
    sendCommand(opCode, params, 23, true);
}

void BM64::musicControl(BM64_music_control_act act){
    sendCommand(BM64_MUSIC_CONTROL_CMD, 0, act);
}

void BM64::generateTone(uint8_t param){
    sendCommand(BM64_BTM_UTILITY_FUNCTION_CMD, 0x02, param);
}

void BM64::mmiAction(BM64_mmi_cmd act){
    sendCommand(BM64_MMI_CMD, 0, act);
}

void BM64::powerOn(){
    digitalWrite(_txInd, HIGH);
    delay(400);
    mmiAction(BM64_MMI_POWERON_BUTTON_PRESS);
    mmiAction(BM64_MMI_POWERON_BUTTON_RELEASE);
}

void BM64::powerOff(){
    mmiAction(BM64_MMI_DISCONNECT_ALL_LINK);
    mmiAction(BM64_MMI_POWEROFF_BT);
    // mmiAction(BM64_MMI_POWEROFF_BUTTON_PRESS);
    // mmiAction(BM64_MMI_POWEROFF_BUTTON_RELEASE);
}

void BM64::setCallback(BM64_callback callback){
    _callback = callback;
}

void BM64::makeCall(const char *number, uint8_t len){
    sendCommand(BM64_MAKE_CALL_CMD, 0, (uint8_t*)number, len);
}

void BM64::makeCall(String *number){
    const char *c_number = number->c_str();
    makeCall(c_number, number->length() + 1);
}

BM64_call_status BM64::getCallStatus(){
    return _call_status;
}

void BM64::run(){
    if(_serial.available() > 0){
        if ( _serialGetByte() != 0xAA ) {return;}

        DPRINTLN("[Received]");
        DPRINTLN("AA found");
        
        // Skip first length byte (should be zero)
        if ( _serialGetByte() != 0 ) {return;}
        uint8_t len = _serialGetByte();


        DPRINT("len found: ");
        DPRINTLN(len, HEX);

        uint8_t eventCode = _serialGetByte();

        uint8_t *cmd = (uint8_t *)malloc(sizeof(uint8_t) * (len - 1));
        BM64_event_t event = {(BM64_EVENT)eventCode, cmd, len - 1};

        // Get parameter data
        for(int i=0; i<len-1; i++){
            event.parameter[i] = _serialGetByte();
        }

        DPRINT("event found: ");
        DPRINTLN(eventCode, HEX);

        for(int i=0; i<event.param_len; i++){
            DPRINT(event.parameter[i], HEX);
            DPRINT(" ");
        }
        DPRINTLN("");

        uint8_t v_checksum = _serialGetByte();

        DPRINT("Checksum: ");
        DPRINTLN(v_checksum, HEX);

        uint8_t sum = len + eventCode + v_checksum;
        for(int i=0; i < event.param_len; i++){
            sum += event.parameter[i];
        }
        if(sum == 0){
            DPRINTLN("Checksum OK");
            handleEvent(&event);
        }else{
            DPRINTLN("Checksum Failed");
        }
        free(event.parameter);
    }
}

void BM64::handleEvent(BM64_event_t *event){
    switch (event->event_code)
    {
    case BM64_EVENT_ACK:
        DPRINTLN("Ack Event");
        _prev_ack_op_code = event->parameter[0];
        break;
    case BM64_EVENT_CALL_STATUS:
        DPRINTLN("Call Status Event");
        DPRINT("Call Status: ");
        DPRINTLN(event->parameter[1]);
        _call_status = (BM64_call_status)event->parameter[1];
        break;
    default:
        break;
    }

    if(event->event_code != BM64_EVENT_ACK){
        // Send ACK
        _callback(event);
        sendCommand(BM64_MCU_SEND_EVENT_ACK_CMD, (uint8_t *)&event->event_code, 2, false);
    }
}

bool BM64::checkAck(uint8_t opCode){
    DPRINT("opCode: ");
    DPRINTLN(opCode, HEX);
    DPRINT("prevAck: ");
    DPRINTLN(_prev_ack_op_code);
    if(_prev_ack_op_code == opCode){
        _prev_ack_op_code = -1;
        return true;
    }else{
        return false;
    }
}

void BM64::sendCommand(uint8_t opCode, uint8_t *parameter, uint8_t len, bool isCheckAck){
    uint8_t command[len+4];
    digitalWrite(_txInd, HIGH);
    _buildCommand(command, opCode, parameter, len);
    DPRINTLN("[Send]");
    for(int i=0; i<len+4; i++){
        DPRINT(command[i], HEX);
        DPRINT(" ");
    }
    DPRINTLN("");
    delay(2);
    _serial.write(command, len+4);
    delay(1);
    digitalWrite(_txInd, LOW);
    unsigned long time = millis();
    if(isCheckAck){
        while(!checkAck(opCode) && abs(millis() - time) < 200){ 
            run();
        }
    }

}

void BM64::sendCommand(uint8_t opCode, uint8_t parameter){
    sendCommand(opCode, &parameter, 2);
}

void BM64::sendCommand(uint8_t opCode, int link_index, uint8_t parameter){
    uint8_t params[2] = {link_index, parameter};
    sendCommand(opCode, params, 3);
}

void BM64::sendCommand(uint8_t opCode, int link_index, uint8_t *parameter, uint8_t len){
    uint8_t param[len+1];
    param[0] = link_index;
    memcpy(&param[1], parameter, len);
    sendCommand(opCode, param, len+1);
}

uint8_t* BM64::_buildCommand(uint8_t* command, uint8_t opCode, uint8_t* parameter, uint8_t length){
    uint8_t init[4] = {0xAA, 0x00, length, opCode};
    memcpy(command, init, 4);
    memcpy(&command[4], parameter, length);
    command[length + 3] = _checksum(&command[2], length+1);

    return command;
}

uint8_t BM64::_checksum(uint8_t *start, uint8_t len){
    uint8_t checksum = 0;
    for(int i=0; i<len; i++){
        checksum += start[i];
    }
    checksum = ~checksum + 1;
    return checksum;
}

uint8_t BM64::_serialGetByte(){
    while(!_serial.available());
    uint8_t byte = _serial.read();
    return byte;
}
