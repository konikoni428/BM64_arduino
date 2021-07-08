#ifndef BM64_h
#define BM64_h
#include "BM64_enum.h"
#include <Arduino.h>
#include "BM64_Debug.h"

typedef struct {
    BM64_EVENT event_code;
    uint8_t *parameter;
    int param_len;
} BM64_event_t;

typedef void (*BM64_callback)(BM64_event_t *event);

class BM64 {
public:
    BM64(Stream &serial, int txInd) : _serial(serial), _txInd(txInd) {
        pinMode(txInd, OUTPUT);
    };
    void getStatus();
    void linkBack();
    void getPhoneName1();
    void getPhoneName2();
    void getSongName(uint8_t link_index);
    void getArtistName(uint8_t link_index);
    void musicControl(BM64_music_control_act act);
    void generateTone(uint8_t param);
    void mmiAction(BM64_mmi_cmd act);
    void powerOn();
    void powerOff();
    void makeCall(String *number);
    void makeCall(const char *number, uint8_t len);
    BM64_call_status getCallStatus();
    void run();
    void setCallback(BM64_callback callback);
private:
    // Stream *_swSerial;
    Stream &_serial;
    int _txInd;
    uint8_t _prev_ack_op_code = -1;
    BM64_callback _callback;
    BM64_call_status _call_status = IDLE;
    void handleEvent(BM64_event_t *event);
    uint8_t* _buildCommand(uint8_t* command, uint8_t opCode, uint8_t* parameter, uint8_t len);
    uint8_t _checksum(uint8_t* start, uint8_t len);
    uint8_t _serialGetByte();
    bool checkAck(uint8_t opCode);
    void sendCommand(uint8_t opCode, uint8_t *parameter, uint8_t len, bool isCheckAck = true);
    void sendCommand(uint8_t opCode, uint8_t parameter);
    void sendCommand(uint8_t opCode, int link_index, uint8_t parameter);
    void sendCommand(uint8_t opCode, int link_index, uint8_t *parameter, uint8_t len);
};

#endif
