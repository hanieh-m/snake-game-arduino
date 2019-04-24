int incomingByte = 0;   // for incoming serial data

void setup() {
        Serial.begin(9600);     // opens serial port, sets data rate to 9600 bps
}

void loop() {
        unsigned long previousMillis = millis();
        bool moved = false;
        while(millis() - previousMillis <= 5000) {
          if (Serial.available() > 0) {
                  incomingByte = Serial.read();
                  Serial.print(incomingByte);
                  moved = true;
                  break;
          }
        }
        if(!moved)
          Serial.print("outside of loop");
}

void snakeMove(int dir, long snake[][2]) {
  return;
}
