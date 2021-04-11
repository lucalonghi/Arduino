const int switchpin=8;

unsigned long previousTime=0;

int switchstate=0;
int prevSwitchState=0;

int led=2;

long interval = 600000;
void setup() {
  // put your setup code here, to run once:
  for (int x=2; x<8; x++)
  {
    pinMode(x,OUTPUT);  
  }
  pinMode(switchpin,INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned long currentTime = millis();

  if (currentTime - previousTime > interval)
  {
    previousTime = currentTime;  
    
    if(led==8)
    {
      led=2;
      for (int x=2; x<8; x++)
      {
        digitalWrite(x,LOW); 
      }
    }
    digitalWrite(led,HIGH);
    led++;
  }

  switchstate = digitalRead(switchpin);

  if (switchstate != prevSwitchState)
  {
    for (int x=2; x<8; x++)
    {
      digitalWrite(x,LOW); 
    }
    led=2;
    previousTime = currentTime;
  }

  prevSwitchState = switchstate;
}
