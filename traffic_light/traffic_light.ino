const byte RouteA_R = 2;
const byte RouteA_Y = 3;
const byte RouteA_G = 4;
const byte RouteB_R = 5;
const byte RouteB_Y = 6;
const byte RouteB_G = 7;
const byte RouteC_R = 8;
const byte RouteC_Y = 9;
const byte RouteC_G = 10;
const byte RouteD_R = 11;
const byte RouteD_Y = 12;
const byte RouteD_G = 13;

byte routeSelector = 0;
byte lightSelector = 0;
unsigned long lightTimer = 0;
unsigned long yellowDelay = 2000;
unsigned long greenDelay = 4000;
unsigned long nextDelay = 500;

void setup() {
  // put your setup code here, to run once:
  pinMode(RouteA_R, OUTPUT);
  pinMode(RouteA_Y, OUTPUT);
  pinMode(RouteA_G, OUTPUT);

  pinMode(RouteB_R, OUTPUT);
  pinMode(RouteB_Y, OUTPUT);
  pinMode(RouteB_G, OUTPUT);

  pinMode(RouteC_R, OUTPUT);
  pinMode(RouteC_Y, OUTPUT);
  pinMode(RouteC_G, OUTPUT);

  pinMode(RouteD_R, OUTPUT);
  pinMode(RouteD_Y, OUTPUT);
  pinMode(RouteD_G, OUTPUT);

  digitalWrite(RouteA_R, HIGH);
  digitalWrite(RouteB_R, HIGH);
  digitalWrite(RouteC_R, HIGH);
  digitalWrite(RouteD_R, HIGH);
  
  lightTimer = millis();
  delay(500);
}

void loop() {
  // put your main code here, to run repeatedly:
  changeLight();
  trafficControl();
}

void trafficControl() {
  switch(routeSelector) {
    case 0: 
      switch(lightSelector) {
        case 0:
          digitalWrite(RouteA_R, LOW);
          digitalWrite(RouteA_Y, HIGH);
          break;
        case 1: 
          digitalWrite(RouteA_Y, LOW);
          digitalWrite(RouteA_G, HIGH);
          break;
        case 2: 
          digitalWrite(RouteA_G, LOW);
          digitalWrite(RouteA_Y, HIGH);
          break;
        case 3: 
          digitalWrite(RouteA_Y, LOW);
          digitalWrite(RouteA_R, HIGH);
          break;
      }
      break;
    case 1:
      switch(lightSelector) {
        case 0:
          digitalWrite(RouteB_R, LOW);
          digitalWrite(RouteB_Y, HIGH);
          break;
        case 1: 
          digitalWrite(RouteB_Y, LOW);
          digitalWrite(RouteB_G, HIGH);
          break;
        case 2: 
          digitalWrite(RouteB_G, LOW);
          digitalWrite(RouteB_Y, HIGH);
          break;
        case 3: 
          digitalWrite(RouteB_Y, LOW);
          digitalWrite(RouteB_R, HIGH);
          break;
      }
      break;
    case 2:
      switch(lightSelector) {
        case 0:
          digitalWrite(RouteC_R, LOW);
          digitalWrite(RouteC_Y, HIGH);
          break;
        case 1: 
          digitalWrite(RouteC_Y, LOW);
          digitalWrite(RouteC_G, HIGH);
          break;
        case 2: 
          digitalWrite(RouteC_G, LOW);
          digitalWrite(RouteC_Y, HIGH);
          break;
        case 3: 
          digitalWrite(RouteC_Y, LOW);
          digitalWrite(RouteC_R, HIGH);
          break;
      }
      break;
    case 3:
      switch(lightSelector) {
        case 0:
          digitalWrite(RouteD_R, LOW);
          digitalWrite(RouteD_Y, HIGH);
          break;
        case 1: 
          digitalWrite(RouteD_Y, LOW);
          digitalWrite(RouteD_G, HIGH);
          break;
        case 2: 
          digitalWrite(RouteD_G, LOW);
          digitalWrite(RouteD_Y, HIGH);
          break;
        case 3: 
          digitalWrite(RouteD_Y, LOW);
          digitalWrite(RouteD_R, HIGH);
          break;
      }
      break;
  }
  
}

void changeLight() {
  if(((millis() - lightTimer) >= yellowDelay) && (lightSelector == 0)) {
    lightSelector = 1;
    lightTimer = millis();
  }
  if(((millis() - lightTimer) >= greenDelay) && (lightSelector == 1)) {
    lightSelector = 2;
    lightTimer = millis();
  }
  if(((millis() - lightTimer) >= greenDelay) && (lightSelector == 2)) {
    lightSelector = 3;
    lightTimer = millis();
  }
  if(((millis() - lightTimer) >= nextDelay) && (lightSelector == 3)) {
    lightSelector = 0;
    routeSelector++;
    if (routeSelector >= 4) {
      routeSelector = 0;
    }
    lightTimer = millis();
  }
}

