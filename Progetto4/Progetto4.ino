const int greenLedPin = 9;
const int redLedPin = 11;
const int blueLedPin = 10;

const int redSensorPin = A0;
const int greenSensorPin = A2;
const int blueSensorPin = A1;

int redValue = 0;
int greenValue = 0;
int blueValue = 0;

int redSensorValue = 0;
int greenSensorValue = 0;
int blueSensorValue = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(greenLedPin, OUTPUT);
  pinMode(redLedPin, OUTPUT);
  pinMode(blueLedPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  redSensorValue = analogRead(redSensorPin); //valore da 0 a 1023
  delay(5);     //delay per dare il tempo al ADC converter di lavorare correttamente
  greenSensorValue = analogRead(greenSensorPin);
  delay(5);
  blueSensorValue = analogRead(blueSensorPin);
  delay(5);

  redValue = redSensorValue/4;
  greenValue = greenSensorValue/4;
  blueValue = blueSensorValue/4;

  Serial.print("Mapped Sensor Values \t red: ");
  Serial.print(redValue);
  Serial.print("\t green: ");
  Serial.print(greenValue);
  Serial.print("\t blue: ");
  Serial.println(blueValue);

  analogWrite(redLedPin,redValue); //PWM da 0 a 255
  analogWrite(greenLedPin,greenValue);
  analogWrite(blueLedPin,blueValue);
  delay(5);
}
