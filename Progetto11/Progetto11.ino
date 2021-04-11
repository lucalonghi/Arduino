#include <LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2); //setup dei pin di controllo del lcd

const int switchPin = 6;
int switchState = 0;
int previousSwitchState = 0;
int reply;

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,2);
  pinMode(switchPin, INPUT);
  lcd.print("Interroga"); //scrive interroga sulla prima riga partendo da coordinata 0,0

  lcd.setCursor(0,1); //porta il cursore all'inizio della seconda riga
  lcd.print("la sfera!");
}

void loop() {
  // put your main code here, to run repeatedly:
  switchState = digitalRead(switchPin);

  if (switchState != previousSwitchState)
  {
    if(switchState == LOW)
    {
      reply = random(8);

      lcd.clear();  //pulisce lcd
      lcd.setCursor(0,0);
      lcd.print("La sfera dice:");
      lcd.setCursor(0,1);

      switch(reply){
        case 0:
        lcd.print("Si");
        break;
        case 1:
        lcd.print("Probabile");
        break;
        case 2:
        lcd.print("Certo");
        break;
        case 3:
        lcd.print("Bene");
        break;
        case 4:
        lcd.print("Forse");
        break;
        case 5:
        lcd.print("Chiedi ancora");
        break;
        case 6:
        lcd.print("Improbabile");
        break;
        case 7:
        lcd.print("No");
        break;
      }
    }  
  }
  previousSwitchState = switchState;
}
