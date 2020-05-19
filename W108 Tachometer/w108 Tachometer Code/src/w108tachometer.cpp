/*
Basic Tachometer for a classic Mercedes-Benz
*/

#include <Arduino.h>

unsigned long start;
unsigned long elapsed;
unsigned long RPM;
int PPR = 3 ; //2800 cm³ straight-six M130 engine has 3 pulses per revolution
int pin = 3; //attach interupt for atmega328p / atmega32u4



// pulsein() looks like it is the best to read the pulses created from the - terminal on the coil. For each PPR, it should go from 0V to 3V
// thanks to the optocoupler smoothing out the voltage and hopefully creating a nice square wave in the process. 

void setup()
{
  Serial.begin(115200);
  pinMode(pin, INPUT);
  start = micros();

}

void rpmCalc() {
  
  duration = pulseIn(Pin, HIGH)
  RPM = 

}

void loop()
{

  Serial.print(int(RPM));
  Serial.print(" RPM is ");

  Serial.println(elapsed);
  delay(50);

  
  
}
