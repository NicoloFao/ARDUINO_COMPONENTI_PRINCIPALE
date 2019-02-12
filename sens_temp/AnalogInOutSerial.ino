
const int analogInPin = A0; 
const int analogOutPin = 9; 

int sensorValue = 0;        
int outputValue = 0; 
unsigned long T ;

void setup()
{
  

  Serial.begin(9600);
}

void loop() {
  T=millis();
 
  sensorValue = analogRead(analogInPin);
  
  outputValue = map(sensorValue, 0, 1023, 0, 255);

  analogWrite(analogOutPin, outputValue);

 
  Serial.print("T = ");
  Serial.print(T);
  Serial.print(",sensor=  ");
    Serial.print(sensorValue);
  Serial.print(",output=  ");
  Serial.println(outputValue);


  delay(2);
}
