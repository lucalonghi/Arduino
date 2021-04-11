void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  Serial.write(analogRead(A0)/4);   // si possono scrivere sulla seriale solo valori tra 0 e 255

  delay(100);   //non delay(1); altrimenti spediamo il valore troppo velocemente il buffer si riempie e vediamo la variazione dopo molto tempo
}
