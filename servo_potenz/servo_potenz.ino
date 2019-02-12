
#include <Servo.h>
Servo myservo; // Crea l'oggetto servo
int triggerPin = A0; // Pin analogico per il potenziometro

void setup() 
{ 
  myservo.attach(9); // Attacca l'oggetto servo al pin 9
  pinMode(triggerPin,INPUT); // Imposto il potenziometro come input
}

void loop() 
{ 
  int posizione = analogRead(triggerPin); // Leggo il potenziometro
  int gradi = calcolaRotazione(posizione); // Converto in gradi
  myservo.write(gradi); // Faccio muovere il servo
}

int calcolaRotazione(int posToDeg)
{
  // Converte la lettura del potenziometro (da 0 a 1023) in gradi
  return (map(posToDeg,0,1023,0,180));
}
