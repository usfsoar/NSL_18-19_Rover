#include "xbee.h"
#include <Arduino.h>

char xbee::readInput(){
    if (Serial.available() > 0) {
        c = Serial.read();
        return c;
    }else{
      return '0';
    }
}
