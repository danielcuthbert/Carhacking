/*
Basic Tachometer for a classic Mercedes-Benz
*/



unsigned long start;
unsigned long elapsed;
unsigned long RPM;
int numOfCyl = 6 ; //2800 cm³ straight-six M130 engine
int pin = 3; //attach interupt for atmega328p / atmega32u4



void setup()
{
  Serial.begin(115200);
  pinMode(pin, INPUT);
  digitalWrite(pin, HIGH);
  attachInterrupt(digitalPinToInterrupt(pin), speedCalc, FALLING);
  start = micros();

}

void speedCalc() {
  elapsed = micros() - start;
  start = micros();

  //RPM = ((120 * (1000000 / elapsed)) / numOfCyl); //MS to RPM +-30RPM Res
  RPM = ((12*(10,000,000/elapsed)) /numOfCyl); //uS  +- 3RPM resolution

}

void loop()
{

  Serial.print(int(RPM));
  Serial.print(" RPM is ");

  Serial.println(elapsed);
  Serial.println(" ms/rev      ");
  delay(50);

  if ((micros()-start) >= 500000){
      RPM=0;//if RPM times out then RPM = 0
  }

  
}
