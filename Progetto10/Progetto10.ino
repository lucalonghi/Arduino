const int controlPin1 = 2;
const int controlPin2 = 3;
const int enablePin = 9;
const int directionSwitchPin = 5;
const int onOffSwitchStateSwitchPin = 4;
const int potPin = A0;

int onOffSwitchState = 0;
int previousOnOffSwitchState = 0;
int directionSwitchState = 0;
int previousDirectionSwitchState = 0;

bool motorEnabled = 0;
int motorSpeed = 0;
bool motorDirection = 1;

void setup() {
  // put your setup code here, to run once:
  pinMode(directionSwitchPin, INPUT);
  pinMode(onOffSwitchStateSwitchPin, INPUT);
  pinMode(controlPin1, OUTPUT);
  pinMode(controlPin2, OUTPUT);
  pinMode(enablePin, OUTPUT);

  digitalWrite(enablePin, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  onOffSwitchState = digitalRead(onOffSwitchStateSwitchPin);
  delay(5);
  directionSwitchState = digitalRead(directionSwitchPin);
  motorSpeed = analogRead(potPin)/4; //uguale a fare int outputpwm = map(valPot,0,1023,50,255);

  if ((onOffSwitchState != previousOnOffSwitchState) && (onOffSwitchState == HIGH))
  {
    motorEnabled = !motorEnabled;
  }

  if ((directionSwitchState != previousDirectionSwitchState) && (directionSwitchState == HIGH))
  {
    motorDirection = !motorDirection;
  }

  if (motorDirection == true)
  {
    digitalWrite(controlPin1, HIGH);
    digitalWrite(controlPin2, LOW);
  }
  else
  {
    digitalWrite(controlPin1, LOW);
    digitalWrite(controlPin2, HIGH);
  }

  if (motorEnabled == true)
  {
    analogWrite(enablePin, motorSpeed);
  }
  else
  {
    analogWrite(enablePin,0);
  }

  previousOnOffSwitchState = onOffSwitchState;
  previousDirectionSwitchState = directionSwitchState;
}
