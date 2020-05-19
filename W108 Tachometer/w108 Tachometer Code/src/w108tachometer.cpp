/*
Basic Tachometer for a classic Mercedes-Benz
*/

#include <Arduino.h>

volatile bool newPulse = false;
volatile unsigned long lastPulseTime;
volatile unsigned long lastPulseInterval;
unsigned long RPM;
int pin = 3;



// pulsein() looks like it is the best to read the pulses created from the - terminal on the coil. 
// the pulses go from 0v to 14v before it hits the circuit, with 0v being points closed and 14v open. 
// thanks to the optocoupler smoothing out the voltage and hopefully creating a nice square wave in the process so 0v - 3v 

void setup()
{
  Serial.begin(9600);
  pinMode(pin, INPUT);
  start = millis();

}

// the maths part. For each revolution of the crank, there are 3 pulses. Using miliseconds it should be something like
// record the last seen pulse
// record the next seen pulse
// divide those by 1000 (we are using miliseconds)
// duration = (last_measure_time - first_measure_time) / 1000.0
// RPS = pulse_round / period
// RPM = RPS * 60000



void rpmtrigger()
{
 unsigned long now = millis();
 unsigned long pulseInterval = now - lastPulseTime;
 if (pulseInterval > 1000UL)  // minimum pulse interval
 {
    lastPulseTime = now;
    lastPulseInterval = pulseInterval;
    newPulse = true;
 }
}

void loop()
{
 if (newPulse)
 {
    rpm = 60000000UL/lastPulseInterval;
    newPulse = false;
 }
 else
 {
   rpm = 0;
 }
 Serial.print(rpm);
 delay(200);
}
