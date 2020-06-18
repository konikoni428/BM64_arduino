#include "BM64.h"
#include <SoftwareSerial.h>

#define RX_PIN 5
#define TX_PIN 6
#define TX_IND 7

SoftwareSerial swSerial(RX_PIN, TX_PIN);
BM64 bm64(swSerial, TX_IND);

void onEventCallback(BM64_event_t *event){
    // handle Event
    Serial.print("[EVENT]: ");
    Serial.println(event->event_code, HEX);

    for(int i=0; i<event->param_len; i++){
        Serial.print(event->parameter[i], HEX);
        Serial.print(" ");
    }
    Serial.println("");
}


void setup() {
    Serial.begin(115200);
    swSerial.begin(9600);
    bm64.setCallback(onEventCallback);
}

void loop() {
    //Check UART Event
    bm64.run();
    if (Serial.available() > 0)
    {
    // read the incoming byte:
    char c = Serial.read();
    switch (c)
    {
        case 'a':
            bm64.getStatus();
            break;
        case 'b':
            // Other Action, Please see BM64_Debug.h
            bm64.musicControl(MUSIC_CONTROL_PLAY);
            break;
        case 'c':
            // Other Action, Please see BM64_Debug.h
            bm64.musicControl(MUSIC_CONTROL_NEXT);
            break;
        case 'd':
            bm64.generateTone(0x07);
            break;
        case 'e':
            // Other Action, Please see BM64_Debug.h
            bm64.mmiAction(BM64_MMI_ACCEPT_CALL);
            break;
        case 'f':
            // Other Action, Please see BM64_Debug.h
            bm64.mmiAction(BM64_MMI_MUTE_MIC);
            break;
        case 'g':
            bm64.powerOff();
            break;
        case 'h':
            bm64.powerOn();
            break;
        case 'i':
            String number_s = "1234567890";
            bm64.makeCall(&number_s);
            break;
        case 'j':
            char number_c[10] = {'1', '2', '3', '4', '5', '6', '7', '8', '9', '0'};
            int len = 10;
            bm64.makeCall(number_c, len);
            break;
        }
    }
}