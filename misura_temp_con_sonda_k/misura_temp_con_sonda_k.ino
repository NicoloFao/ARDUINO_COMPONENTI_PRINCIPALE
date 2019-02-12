#include "max6675.h"

unsigned long old_millis=0;
unsigned long delta=600;
int minuti=1;
int thermoDO = 6;
int thermoCS = 5;
int thermoCLK = 4;
float valoretermocoppia=0;

MAX6675 thermocouple(thermoCLK, thermoCS, thermoDO);
int vccPin = 3;
int gndPin = 2;

  
void setup()
{
  Serial.begin(9600);
  pinMode(vccPin, OUTPUT); digitalWrite(vccPin, HIGH);
  pinMode(gndPin, OUTPUT); digitalWrite(gndPin, LOW);
  pinMode(8,OUTPUT);
    pinMode(10,OUTPUT);
  
  Serial.println("MAX6675 test");

  delay(500);
}

void loop()
{
  unsigned long now=millis();

  if(now>=old_millis+delta)
  {
  //digitalWrite (8,HIGH);
 // delay(10);
 // digitalWrite(8,LOW); 
  Serial.print(minuti);
  Serial.print(",");
  Serial.println(thermocouple.readCelsius());
  valoretermocoppia=thermocouple.readCelsius();
  old_millis=now;
  minuti=minuti+1;
  if(valoretermocoppia>=28)
  {
  digitalWrite (8,HIGH);
  }

  if(valoretermocoppia<=27)
  {
    digitalWrite(8,LOW);
  }
  if((valoretermocoppia>=27)&&(valoretermocoppia<=28))
  {
     digitalWrite (10,HIGH);
  }
  else(digitalWrite (10,LOW));
 
  
  }
  delay(1000);
  // Serial.print("C = "); 
  // millis() ;
  // Serial.println(thermocouple.readCelsius());
  //delay(1000);
}
