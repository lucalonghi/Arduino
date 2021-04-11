const int switchPin = 2;
const int motorPin = 9;
const int potPin = A0;
int switchState = 0;
int valPot;


void setup() {
  // put your setup code here, to run once:
  pinMode(switchPin,INPUT);
  pinMode(motorPin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  switchState = digitalRead(switchPin);
  valPot = analogRead(potPin);
  int outputpwm = map(valPot,0,1023,50,255);
  /*
  if (switchState == HIGH)
  {
    digitalWrite(motorPin, HIGH);  
  }
  else
  {
    digitalWrite(motorPin, LOW);
  }
  */
   if (switchState == HIGH)
  {
    analogWrite(motorPin, outputpwm);  
  }
  else
  {
    analogWrite(motorPin, 0);  
  }
}
