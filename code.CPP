#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int i = 0;
void setup()
{
lcd.begin(0, 0);
Serial.begin(9600);
//This is just here to make it look cooler
//Code looking setup things
lcd.print("-init ARD-LCD");
Serial.println("-init ARD-LCD");
delay(1000);
lcd.clear();
delay(500);
lcd.print("-seq SETUP");
Serial.println("-seq SETUP");
delay(1000);
lcd.clear();
delay(500);
lcd.print("-STARTUP");
Serial.println("-STARTUP");
delay(1000);
lcd.clear();
delay(250);
//Loading screen
lcd.print('/');
delay(500);
lcd.clear();
lcd.print('-');
delay(500);
lcd.clear();
lcd.print('|');
delay(500);
lcd.clear();
lcd.print('-');
delay(500);
lcd.clear();
//LCD read
lcd.print("ARD-LCD: ready");
delay(500);
Serial.println("-init Serial-CommandPro");
delay(500);
Serial.println("ET: 3 sec");
delay(3000);
Serial.println("Serial-CommandPro: <<Finished>>");
lcd.clear();
lcd.print("*Ready for use*");
Serial.println("Await instructions...");
delay(1500);
lcd.clear();
Serial.println("Enter message and press enter");
lcd.print("**SEE TERMINAL**");
}
void loop() {
  //This took me two weeks
  if (Serial.available() > 0) {
    lcd.clear();
    String Message = Serial.readString();//Reads your message
    Serial.println(">>Printing:" + Message);//Reads back your message
    lcd.print(Message);//Displays message
    delay(4500);//If you don't know what this, I will be sad
    Serial.println("<<Enter Next Message>>");//Lets you know it's ready for the next message
  }
}
