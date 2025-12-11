#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2); 

const int ldrPin = A2; // LDR signal input pin
int prevState = HIGH;
unsigned long startTime = 0;
unsigned long duration = 0;

String currentSymbol = "";
String decodedText = "";

// Timing thresholds
const unsigned long dotMax = 250;       // <=250ms = dot
const unsigned long dashMin = 251;      // >=251ms = dash
const unsigned long dashMax = 700;      // <=700ms = dash
const unsigned long letterGap = 450;    // gap between letters
const unsigned long wordGap = 1050;     // gap between words

char decodeMorse(String m) {
  if (m==".-") return 'A';
  if (m=="-...") return 'B';
  if (m=="-.-.") return 'C';
  if (m=="-..") return 'D';
  if (m==".") return 'E';
  if (m=="..-.") return 'F';
  if (m=="--.") return 'G';
  if (m=="....") return 'H';
  if (m=="..") return 'I';
  if (m==".---") return 'J';
  if (m=="-.-") return 'K';
  if (m==".-..") return 'L';
  if (m=="--") return 'M';
  if (m=="-.") return 'N';
  if (m=="---") return 'O';
  if (m==".--.") return 'P';
  if (m=="--.-") return 'Q';
  if (m==".-.") return 'R';
  if (m=="...") return 'S';
  if (m=="-") return 'T';
  if (m=="..-") return 'U';
  if (m=="...-") return 'V';
  if (m==".--") return 'W';
  if (m=="-..-") return 'X';
  if (m=="-.--") return 'Y';
  if (m=="--..") return 'Z';
  if (m=="-----") return '0';
  if (m==".----") return '1';
  if (m=="..---") return '2';
  if (m=="...--") return '3';
  if (m=="....-") return '4';
  if (m==".....") return '5';
  if (m=="-....") return '6';
  if (m=="--...") return '7';
  if (m=="---..") return '8';
  if (m=="----.") return '9';
  return '?';
}

void setup() {
  lcd.init();
  lcd.backlight();
  pinMode(ldrPin, INPUT);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Morse Receiver");
  delay(1000);
  lcd.clear();
}

void loop() {
  int sensorValue = analogRead(ldrPin);
  int state = (sensorValue < 512) ? LOW : HIGH; // Light ON when LDR value drops
  unsigned long currentTime = millis();

  if(state != prevState) {
    if(state == LOW) {
      // Light ON
      duration = currentTime - startTime;
      if(duration > letterGap && currentSymbol.length()>0) {
        char letter = decodeMorse(currentSymbol);
        decodedText += letter;
        currentSymbol = "";
        updateLCD();
      }
      if(duration > wordGap) {
        decodedText += ' ';
        updateLCD();
      }
      startTime = currentTime;
    } else {
      // Light OFF
      duration = currentTime - startTime;
      if(duration <= dotMax) currentSymbol += ".";
      else if(duration >= dashMin && duration <= dashMax) currentSymbol += "-";
      startTime = currentTime;
    }
    prevState = state;
  }
}

void updateLCD() {
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Decoded:");
  lcd.setCursor(0,1);
  lcd.print(decodedText);
}
