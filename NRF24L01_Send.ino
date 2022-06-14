#include <SPI.h>
#include "RF24.h"

RF24 radio(7, 8); // using pin 7 for the CE pin, and pin 8 for the CSN pin

const byte address[] = "1Node";
const char msg[] = "Hello World!!!";

void setup() {

  Serial.begin(115200);
  while (!Serial) {
    // some boards need to wait to ensure access to serial over USB
  }

  // initialize the transceiver on the SPI bus
  if (!radio.begin()) {
    Serial.println(F("radio hardware is not responding!!"));
    while (1) {} // hold in infinite loop
  }

  radio.setChannel(83);
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MAX);
  radio.setDataRate(RF24_2MBPS);
  radio.stopListening();

} // setup

void loop() {
  radio.write(&msg, sizeof(msg));
  delay(1000);
} // loop
