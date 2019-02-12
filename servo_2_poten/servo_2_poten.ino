
#include <Servo.h>

Servo myservo1;
Servo myservo2;// Crea l'oggetto servo
int triggerPin = A0; // Pin analogico per il potenziometro
 int posizione;
  int posizionet;

void setup() 
{ 
  myservo1.attach(9); // Attacca l'oggetto servo al pin 9
  myservo2.attach(10); 
  pinMode(triggerPin,INPUT); // Imposto il potenziometro come input
}

void loop() 
{ 
 posizione = analogRead(triggerPin); // Leggo il potenziometro
 posizione = map(posizione,0,1023,0,180);
 myservo1.write(posizione);


  posizionet = analogRead(triggerPin);
 posizionet = map(posizionet,0,1023,180,0);// Faccio muovere il servo
 myservo2.write(posizionet);
}


