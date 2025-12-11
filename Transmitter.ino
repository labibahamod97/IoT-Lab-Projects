const int ledPin = 13;  // LED বা Relay control pin

// Morse code dictionary
String morseCode(char c) {
  switch (toupper(c)) {
    case 'A': return ".-";
    case 'B': return "-...";
    case 'C': return "-.-.";
    case 'D': return "-..";
    case 'E': return ".";
    case 'F': return "..-.";
    case 'G': return "--.";
    case 'H': return "....";
    case 'I': return "..";
    case 'J': return ".---";
    case 'K': return "-.-";
    case 'L': return ".-..";
    case 'M': return "--";
    case 'N': return "-.";
    case 'O': return "---";
    case 'P': return ".--.";
    case 'Q': return "--.-";
    case 'R': return ".-.";
    case 'S': return "...";
    case 'T': return "-";
    case 'U': return "..-";
    case 'V': return "...-";
    case 'W': return ".--";
    case 'X': return "-..-";
    case 'Y': return "-.--";
    case 'Z': return "--..";
    case '0': return "-----";
    case '1': return ".----";
    case '2': return "..---";
    case '3': return "...--";
    case '4': return "....-";
    case '5': return ".....";
    case '6': return "-....";
    case '7': return "--...";
    case '8': return "---..";
    case '9': return "----.";
    case ' ': return " ";  // Word space
    default: return "?";
  }
}

// Timing in milliseconds
const unsigned int dotTime = 200;      // 1 unit
const unsigned int dashTime = dotTime*3;
const unsigned int symbolGap = dotTime;   // gap between dot/dash
const unsigned int letterGap = dotTime*3; // gap between letters
const unsigned int wordGap = dotTime*7;   // gap between words

void setup() {
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
  Serial.begin(9600);
  Serial.println("Morse Transmitter Ready!");
  Serial.println("Type your message and press Enter:");
}

void loop() {
  if (Serial.available() > 0) {
    String message = Serial.readStringUntil('\n');
    message.trim();
    Serial.print("Sending: ");
    Serial.println(message);
    sendMorse(message);
    Serial.println("Message sent!");
  }
}

void sendMorse(String msg) {
  for (int i=0; i<msg.length(); i++) {
    char c = msg[i];
    String code = morseCode(c);
    
    for (int j=0; j<code.length(); j++) {
      if (code[j] == '.') {
        digitalWrite(ledPin,HIGH);
        delay(dotTime);
        digitalWrite(ledPin,LOW);
      } 
      else if (code[j] == '-') {
        digitalWrite(ledPin,HIGH);
        delay(dashTime);
        digitalWrite(ledPin,LOW);
      }
      delay(symbolGap);
    }
    
    if(c==' ') delay(wordGap - letterGap);
    else delay(letterGap - symbolGap);
  }
}