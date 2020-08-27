/*
Basic Tachometer for a classic Mercedes-Benz.
This tests that a pulse is being generated and that it can be read 
*/

#include <Arduino.h>


int ledPin = 9;
const byte interruptPin = 3;
volatile unsigned int pulse;
volatile byte state = RISING; // The negative side of the coil remains high, each pulse will increase this value


void setup()
{
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(interruptPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interruptPin), count1, RISING);  
}


void loop()
{
  pulse = 0;
  digitalWrite(ledPin, state);
  delay(1000);
  Serial.print("Pulses per second: ");
  Serial.println(pulse * 60);
}

void count1()
{
  state = !state;
  pulse++;
}