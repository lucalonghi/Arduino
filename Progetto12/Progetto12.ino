#include <Servo.h>

Servo myServo;

const int piezo = A0;
const int switchPin = 8;
const int yellowLed = 3;
const int greenLed = 4;
const int redLed = 5;

int knockVal;
int switchVal;

const int quietKnock = 6;
const int loudKnock = 100;

boolean locked = false;
int numberOfKnocks = 0;

unsigned long previousKnockTime = 0;

void setup() {
  // put your setup code here, to run once:
  myServo.attach(9);
  pinMode(yellowLed,OUTPUT);
  pinMode(greenLed,OUTPUT);
  pinMode(redLed,OUTPUT);
  Serial.begin(9600);

  digitalWrite(greenLed,HIGH);
  myServo.write(0);
  Serial.println("The box is unlocked!");
}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned long currentTime = millis();
  const int maxTime = 7000; 
  
  if (locked == false){
    switchVal = digitalRead(switchPin);
    if (switchVal == HIGH){
      locked = true;
      digitalWrite(greenLed,LOW);
      digitalWrite(redLed,HIGH);
      myServo.write(90);
      Serial.println("The box is locked!");
      delay(1000);
    }
  }
   if (locked == true){
    knockVal = analogRead(piezo);
    if(numberOfKnocks < 3 && knockVal > 0){
      if(checkForKnocks(knockVal) == true){
        if ((numberOfKnocks >= 1 && ((currentTime - previousKnockTime) < maxTime))||(numberOfKnocks == 0)){
          numberOfKnocks++;
          previousKnockTime = currentTime;
          Serial.println("*******************************");
        }else{
          numberOfKnocks=0;
        }
        delay(5);
      }
      Serial.print(3-numberOfKnocks);
      Serial.println(" more knocks to go");
    }
    if(numberOfKnocks >= 3){
      locked = false;
      myServo.write(0);
      delay(20);
      digitalWrite(greenLed,HIGH);
      digitalWrite(redLed,LOW);
      Serial.println("The box is unlocked!");
      numberOfKnocks=0;
    }
   }
}

boolean checkForKnocks (int value){
  if(value > quietKnock && value < loudKnock){
    digitalWrite(yellowLed,HIGH);
    Serial.print("Valid knock of value ");
    Serial.println(value);
    delay(50);
    digitalWrite(yellowLed,LOW);
 
    return true;
  }else{
    Serial.print("bad knock value ");
    Serial.println(value);

    return false;
  }
}
