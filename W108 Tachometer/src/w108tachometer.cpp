/*
Basic Tachometer for a classic Mercedes-Benz. A work in progress. 
*/

#include <Arduino.h>
#include <util/atomic.h>


int ledPin = 13;
int count = 0;
const byte interruptPin = 3;
volatile unsigned int pulse;
volatile byte state = RISING;


void setup()
{
  Serial.begin(9600);
  pinMode(interruptPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interruptPin), count, CHANGE);  
}





void loop() {
  pulse = 0;
  digitalWrite(ledPin, state);
  delay(1000);
  Serial.print("Pulses per second: ");
  Serial.println(pulse);
}

void count1() {
        pulse++;
        
    }
