void setup() {
  // put your setup code here, to run once:
  pinMode(2,INPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
}

int buttonstate = 0;

void loop() {
  // put your main code here, to run repeatedly:

  buttonstate = digitalRead(2);
  
  if (buttonstate == LOW)
  {
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(LED_BUILTIN, HIGH);
    delay(250);
    digitalWrite(LED_BUILTIN, LOW);
    delay(250);
  }
  else
  {
    digitalWrite(3, LOW);
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
    digitalWrite(LED_BUILTIN, HIGH);
    delay(250);
    digitalWrite(4, LOW);
    digitalWrite(5, HIGH);
    delay(250);
  }
}
