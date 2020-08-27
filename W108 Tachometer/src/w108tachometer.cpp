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

/*
The pulse variable is a 16-bit int and the 8-bit processor won’t be able to read in a single CPU cycle.
That in itself is not an issue, until interrupts come into the picture. So this means there is a possibility 
that the pulse bump interrupt will occur right in the middle of the CPU reading the current value in loop(), 
and we will end up writing/reading half of the previous value, and half the new value.

So to solve this, we use atomic (we hope)
*/
  ATOMIC_BLOCK(ATOMIC_RESTORESTATE) {
  pulse = 0;
  digitalWrite(ledPin, state);
  delay(1000);
  Serial.print("Pulses per second: ");
  Serial.println(pulse);
  }

}

void count1() {
        pulse++;
        
    }
