#include <Servo.h>

Servo myServo;
const int potPin = A0;
int valPotenziometro;
int angle;

void setup() {
  // put your setup code here, to run once:
  myServo.attach(9);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  valPotenziometro = analogRead(potPin);

  Serial.print("potVal: ");
  Serial.print(valPotenziometro);

  angle = map(valPotenziometro,0,1023,0,179);   //scalatura
  Serial.print(", angle: ");
  Serial.println(angle);

  myServo.write(angle);
  delay(50);
}
