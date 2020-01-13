/*
 * Creating a counter with seven segment display, using a push button.
 * @Author James John James
 */

 // Pin definition section
 #define a 13
 #define b 12
 #define c 11
 #define d 10
 #define e 9
 #define f 8
 #define g 7
 #define th 6
 #define hn 5
 #define tn 4
 #define un 3
 #define btn 2
 
//  Numbers to be displayed on the screen
 char unit = 0;
 char tens = 0;
 char hundred = 0;
 char thousand = 0;
 
 const byte del = 5;
 unsigned long delTimer = 0;
 unsigned long delTime = 500;
 unsigned int counter = 0;
void setup() {
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(f, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(th, OUTPUT);
  pinMode(hn, OUTPUT);
  pinMode(tn, OUTPUT);
  pinMode(un, OUTPUT);
  pinMode(btn, INPUT);

  offPin(a);
  offPin(b);
  offPin(c);
  offPin(d);
  offPin(e);
  offPin(f);
  offPin(g);
  offPin(th);
  offPin(hn);
  offPin(tn);
  offPin(un);

  delay(1000);
  delTimer = millis();
}

void offPin(byte pin) {
  digitalWrite(pin, LOW);
}

void onPin(byte pin) {
  digitalWrite(pin, HIGH);
}

void display(int count) {
  if(count < 10000 && count >= 1000) {
    thousand = (count/1000)%10;  
    hundred = (count/100) % 10; 
    tens = (count/10) % 10;  
    unit = count%10; 
  }
  if(count < 1000 && count >= 100) {
    hundred = (count/100) % 10; 
    tens = (count/10) % 10;  
    unit = count%10;   
  }
  if(count < 100 && count >= 10) {
    tens = (count/10) % 10;
    unit = count%10;    
  }
  if(count < 10) {
    unit = count%10;   
  }

  showNumber(unit, un);
  showNumber(tens, tn);
  showNumber(hundred, hn);
  showNumber(thousand, th);
}

void showNumber(byte number, byte location) {
  switch(number) {
    case 0:
      offPin(g);
      onPin(a);
      onPin(b);
      onPin(c);
      onPin(d);
      onPin(e);
      onPin(f);
      
      break;
    case 1:
      offPin(g);
      offPin(a);
      onPin(b);
      onPin(c);
      offPin(d);
      offPin(e);
      offPin(f);
      
      break;
    case 2: 
      onPin(a);
      onPin(b);
      offPin(c);
      onPin(d);
      onPin(e);
      offPin(f);
      onPin(g);
      
      break;
    case 3: 
      onPin(a);
      onPin(b);
      onPin(c);
      onPin(d);
      offPin(e);
      offPin(f);
      onPin(g);
      
      break;
    case 4: 
      offPin(a);
      onPin(b);
      onPin(c);
      offPin(d);
      offPin(e);
      onPin(f);
      onPin(g);
      
      break;
    case 5: 
      onPin(a);
      offPin(b);
      onPin(c);
      onPin(d);
      offPin(e);
      onPin(f);
      onPin(g);
      
      break;
    case 6: 
      onPin(a);
      offPin(b);
      onPin(c);
      onPin(d);
      onPin(e);
      onPin(f);
      onPin(g);
      
      break;
    case 7: 
      onPin(a);
      onPin(b);
      onPin(c);
      offPin(d);
      offPin(e);
      onPin(f);
      offPin(g);
      
      break;
    case 8: 
      onPin(a);
      onPin(b);
      onPin(c);
      onPin(d);
      onPin(e);
      onPin(f);
      onPin(g);
      
      break;
    case 9: 
      onPin(a);
      onPin(b);
      onPin(c);
      onPin(d);
      offPin(e);
      onPin(f);
      onPin(g);
      
      break;

    default: 
      offPin(g);
      onPin(a);
      onPin(b);
      onPin(c);
      onPin(d);
      onPin(e);
      onPin(f);
      
      break;
  }

  offPin(location);
  delay(del);
  onPin(location);
}

void loop() {
  // put your main code here, to run repeatedly:
  if((digitalRead(btn) == LOW) && ((millis() - delTimer) >= delTime)) {
    counter += 1;
    delTimer = millis();
  }
  display(counter);

}
