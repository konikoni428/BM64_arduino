#include "BM64.h"
#include <SoftwareSerial.h>

#define RX_PIN 5
#define TX_PIN 6
#define TX_IND 7

SoftwareSerial swSerial(RX_PIN, TX_PIN);
BM64 bm64(swSerial, TX_IND);

void onEventCallback(BM64_event_t *event){
    // handle event
    switch(event->event_code)
    {
    case BM64_EVENT_CALL_STATUS:
        if(event->parameter[1] == INCOMING_CALL){
            // Incoming Call
        }else if(event->parameter[1] == IDLE){
            // End call event
        }
        break;
    case BM64_EVENT_DEVICE_STATE:
        if(event->parameter[0] == 0x00){
            // Power Off Event
        }else if(event->parameter[0] == 0x02){
            // Power On Event
        }
        break;
    }
}


void setup() {
    swSerial.begin(9600);
    bm64.setCallback(onEventCallback);
}

void loop() {
    //Check UART Event
    bm64.run();
}
