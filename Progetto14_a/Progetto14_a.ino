int senddata;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  senddata = 0;
  if (Serial.available() > 0) {
    // read the incoming byte:
    senddata = Serial.read();
  }
  if (senddata){    //modicica per tenere delay(1) e mandare i dati quando processing li richiede
    Serial.write(analogRead(A0)/4);   // si possono scrivere sulla seriale solo valori tra 0 e 255
  }
  delay(1);   
}
