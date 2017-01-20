# Arduino MSGEQ7 Library

A simple library that allows reading all 7 filter values into an array or just reading a single frequency band at a time.

## Example Usage

```c
#include <MSGEQ7.h>

#define strobePin 8
#define resetPin 9
#define analogPin 14

int bandValues[7];

MSGEQ7 audio(strobePin, resetPin, analogPin);

void setup() {
  Serial.begin(9600);
  audio.begin();
}

void loop() {
  audio.readAll(bandValues);
  for (int i=0; i<7; i++) {
    Serial.print(bandValues[i]);
    Serial.print("\t");
  }
  Serial.println();
}
```
