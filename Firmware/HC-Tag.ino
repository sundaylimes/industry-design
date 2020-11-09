// This code was developed by Robert Fogg
// 11/7/2020 for Fall 2020 Practicum design project PSU ECE411
// Code is for the "Tag" piece of the electronic hot/cold game
// receives code and then return transmits to "ping back" data
// to calculate the time of flight for radio signals
// uses 2.4GHz via NRF24L01.

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(7, 8); // CE, CSN

const byte address[][6] = {"00001","00002"};
int rcvdID = 0;

void setup() {
  Serial.begin(9600);
  radio.begin();                                // turn on radio
  radio.openReadingPipe(0, address[1]);         // read address 00002
  radio.openWritingPipe(address[0]);            // write address 00001
  radio.setPALevel(RF24_PA_MIN);                // set Antenna power level
}

void loop() {
  delay (5);
  radio.startListening();
  if (radio.available()) {
    while (radio.available()) {
      radio.read(&rcvdID, sizeof(rcvdID));
    }
    delay (1000);
    radio.stopListening();
    radio.write(&rcvdID, sizeof(rcvdID));      
    }
    Serial.println(rcvdID);
}
