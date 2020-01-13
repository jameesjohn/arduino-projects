// Include the liquid crystal library.
#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 10, 9, 8, 7);

void setup() {
  // put your setup code here, to run once:
//  lcd.begin(20, 4);
//  lcd.home();
//  lcd.print("James John James John James John James");

  printDots();
}

void loop() {
  // put your main code here, to run repeatedly:

}

void printDots() {
  byte noOfDots = 3;
  for(int i = 1; i <= noOfDots; i++) {
    switch(i) {
      case 1: 
        lcd.print("initializing.");
        delay(200);
        lcd.clear();
        break;
      case 2: 
        lcd.print("initializing..");
        delay(200);
        lcd.clear();
        break;
      case 3: 
        lcd.print("initializing...");
        delay(200);
        break;
    }
    if(i == 3) {
      lcd.clear();
      lcd.print("initializing");
      delay(50);
      lcd.clear();
      i = 0;
    }
  }
}

/*
 * Available methods in LCD. 
 * clear -- Remove items from the screen
 * noDisplay -- Shut down screen.
 * blink -- Used to make screen blink
 * noCursor -- Doesn't show a cursor on the screen
 * cursor -- !noCursor
 * scrollDisplayLeft
 * scrollDisplayRight
 * leftToRight -- 
 * rightToLeft -- change text orientation to arabic-like.
 * autoScroll -- Scroll the message automatically.
 * setRowOffset
 * setCursor
 */
