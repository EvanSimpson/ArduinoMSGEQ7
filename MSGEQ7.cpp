#include "Arduino.h"
#include "MSGEQ7.h"

MSGEQ7::MSGEQ7(int strobePin, int resetPin, int readPin) {
    _strobePin = strobePin;
    _resetPin = resetPin;
    _readPin = readPin;
}

void MSGEQ7::advanceStrobe() {
  digitalWrite(_strobePin, HIGH);
  delayMicroseconds(18); // Strobe pulse width
  digitalWrite(_strobePin, LOW);
  position++;
  delayMicroseconds(36); // to allow the output to settle
}

void MSGEQ7::reset() {
  digitalWrite(_resetPin, LOW);
  digitalWrite(_resetPin, HIGH);
  delayMicroseconds(1);
  digitalWrite(_resetPin, LOW);
  position = -1;
  delayMicroseconds(72);
}

void MSGEQ7::begin(){
  pinMode(_strobePin, OUTPUT);
  pinMode(_resetPin, OUTPUT);
  pinMode(_readPin, INPUT);
  reset();
}

void MSGEQ7::readAll(int *cdata) {
  for (int i=0; i<7; i++) {
    cdata[i] = readBand(i);
  }
}

int MSGEQ7::readBand(int band) {
  if ( band > 6 || band < 0 ) {
    return 0;
  }
  if ( band < position ) {
    reset();
  }
  while ( band != position ) {
    advanceStrobe();
    delayMicroseconds(36); // Strobe 2 strobe delay
  }
  int data = analogRead(_readPin);
  delayMicroseconds(18);
  return data;
}
