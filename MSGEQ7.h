// Arduino MSGEQ7 Library
// Simple library for reading analog values from an MSGEQ7

#ifndef MSGEQ7_h
#define MSGEQ7_h

#include "Arduino.h"

class MSGEQ7 {
  public:
    MSGEQ7(int strobePin, int resetPin, int readPin);
    void begin();
    void readAll(int *cdata);
    int readBand(int band);
  private:
    void reset();
    void advanceStrobe();
    int _strobePin;
    int _resetPin;
    int _readPin;
    int position;
};

#endif
