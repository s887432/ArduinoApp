#include <SPI.h>
#include "RF24.h"

RF24 radio(7, 8); // using pin 7 for the CE pin, and pin 8 for the CSN pin

const byte address[] = "1Node";
const byte pipe = 1;

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
  radio.openReadingPipe(pipe, address);
  radio.setPALevel(RF24_PA_MAX);
  radio.setDataRate(RF24_2MBPS);
  radio.startListening();
  Serial.println("nRF24L01 is ready");

} // setup

void loop() {
  if( radio.available(&pipe) ) {
    char msg[32];
    radio.read(&msg, sizeof(msg));
    Serial.println(msg);
  }
} // loop
