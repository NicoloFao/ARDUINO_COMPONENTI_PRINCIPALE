

#include "max6675.h"

unsigned long old_millis=0;
unsigned long delta=600;
int minuti=1;
int thermoDO = 6;
int thermoCS = 5;
int thermoCLK = 4;

MAX6675 thermocouple(thermoCLK, thermoCS, thermoDO);
int vccPin = 3;
int gndPin = 2;
  
void setup()
{
  Serial.begin(9600);
  pinMode(vccPin, OUTPUT); digitalWrite(vccPin, HIGH);
  pinMode(gndPin, OUTPUT); digitalWrite(gndPin, LOW);
  
  Serial.println("MAX6675 test");

  delay(500);
}

void loop()
{
  unsigned long now=millis();

  if(now>=old_millis+delta)
  {
  Serial.print(minuti);
  Serial.print(",");
  Serial.println(thermocouple.readCelsius());
  old_millis=now;
  minuti=minuti+1;
  }
  delay(1);
  
  // Serial.print("C = "); 
  // millis() ;
  // Serial.println(thermocouple.readCelsius());
   //delay(1000);
}
