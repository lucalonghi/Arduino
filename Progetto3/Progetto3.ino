const int sensorPin = A0;
float baselineTemp = 20.0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  for(int pinNumber = 2; pinNumber<5; pinNumber++)
  {
    pinMode(pinNumber,OUTPUT);
    digitalWrite(pinNumber, LOW);
  }
  pinMode(6, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int sensorVal = analogRead(sensorPin);

 Serial.print("Ambient Temp Value : ");
 Serial.print(baselineTemp);
 
  Serial.print(",   Sensor Value : ");
  Serial.print(sensorVal);

  float voltage = (sensorVal / 1024.0) * 5.0;

  Serial.print(",   Volts: ");
  Serial.print(voltage);

  float temp = (voltage - 0.5) * 100.0;
  Serial.print(",   Degrees: ");
  Serial.println(temp);

  if(temp < baselineTemp + 1)
  {
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  }
  else if (temp >= baselineTemp +1 && temp < baselineTemp +2)
  {
     digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  }
  else if (temp >= baselineTemp +2 && temp < baselineTemp +3)
  {
     digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
  }
  else if (temp >= baselineTemp +3)
  {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
  }
  if (digitalRead(6) == HIGH)
  {
    baselineTemp = temp;
  }
  delay(100);
}
