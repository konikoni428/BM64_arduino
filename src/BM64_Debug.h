#ifndef BM64_Debug_h_
#define BM64_Debug_h_

// #define BM64_DEBUG // Switch debug output on and off by commentout 

#ifdef BM64_DEBUG
#include <SoftwareSerial.h>
#define USE_DEBUG       extern SoftwareSerial _swSerial;
#define DPRINT(...)     _swSerial.print(__VA_ARGS__)
#define DPRINTLN(...)   _swSerial.println(__VA_ARGS__)
#else
#define USE_DEBUG 
#define DPRINT(...)
#define DPRINTLN(...)
#endif

#endif