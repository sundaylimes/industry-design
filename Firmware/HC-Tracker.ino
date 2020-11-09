// This code was developed by Robert Fogg
// 11/7/2020 for Fall 2020 Practicum design project PSU ECE411
// Code is for the "Tracker" piece of the electronic hot/cold game
// transmits and times return to calculate time of flight for radio signals
// on 2.4GHz via NRF24L01, on data return calculates approximate distance
// by subtracting delay then dividing travel time by speed of light
// then dividing distance in half as travel to and from the "Tag" will be
// measured.

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(7, 8); // CE, CSN

const byte address[][6] = {"00001","00002"};
const int myID = 909;
int long xMitTime = 0;
int long RcvTime = 0;
int rcvdID = 0;
int trvlTime = 0;
int tagDist = 0;

void setup() {
  Serial.begin(9600);
  radio.begin();                                // turn on radio
  radio.openWritingPipe(address[1]);            // write address 00002
  radio.openReadingPipe(1, address[0]);         // read address 00001
  radio.setPALevel(RF24_PA_MIN);                // set Antenna power level
}

void loop() {
  delay(5);
  radio.stopListening();
  radio.write(&myID, sizeof(myID));
  xMitTime = micros();

  delay(1);
  radio.startListening();
  while (radio.available()) {
    radio.read(&rcvdID, sizeof(rcvdID));
    if (rcvdID == myID) {
      RcvTime = micros();
      trvlTime = RcvTime - xMitTime;
//    tagDist = (trvlTime * 299) / 2;                 // calculates feet of travel 
      tagDist = trvlTime;
      Serial.println(tagDist);
    }
  }
}
