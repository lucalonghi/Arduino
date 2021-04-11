int sensorValue;
int sensorHigh = 0;
int sensorLow = 1023;

int potValue;

void setup() {
  // put your setup code here, to run once:

   pinMode(LED_BUILTIN, OUTPUT);
   digitalWrite(LED_BUILTIN,HIGH);

   
   while(millis() < 5000){    //primi 5 sec di esecuzione
      sensorValue=analogRead(A0);
      if (sensorValue > sensorHigh){
        sensorHigh=sensorValue;
      }
      if (sensorValue < sensorLow){
        sensorLow=sensorValue;
      }
   }

   digitalWrite(LED_BUILTIN,LOW);
   Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  sensorValue=analogRead(A0);
  potValue=analogRead(A2);
  
  int range=map(potValue,0,1023,100,4000);
  int pitch=map(sensorValue,sensorLow,sensorHigh,50,range);

  tone(8,pitch,50);   //pin, valore frequenza, durata suono

  Serial.print("SensorLow= ");
  Serial.print(sensorLow);
  Serial.print(" SensorHigh= ");
  Serial.print(sensorHigh);
  Serial.print(" SensorValue= ");
  Serial.print(sensorValue);
  Serial.print(" Pitch= ");
  Serial.println(pitch);

  delay(100);
}
