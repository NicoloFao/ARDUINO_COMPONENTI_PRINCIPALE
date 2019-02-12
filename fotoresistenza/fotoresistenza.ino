int LDRpin=A0;
int LEDpin=9;
int ledCalibration=4;
int max_value=0;
int min_value=9000;

void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  pinMode(LEDpin,OUTPUT);
  pinMode(ledCalibration,OUTPUT);
  //accendo led
  digitalWrite(ledCalibration,HIGH);

  unsigned long start=millis();
  while(millis()-start<5000)
  {
    int value=analogRead(LDRpin);
    if(value<min_value)min_value=value;
     if(value>max_value)max_value=value;
     delay(100);
  }

}

void loop() {
  
  int sensorValue = analogRead(A0);
int ledValue=map(sensorValue,min_value,max_value,0,255);

Serial.println(LEDpin,ledValue);



   Serial.println(sensorValue);
   Serial.println(", ");
   Serial.println(ledValue);
   Serial.println(", ");
   Serial.println(min_value);
   Serial.println(", ");
   Serial.println(max_value);
  
  delay(100);      
}
