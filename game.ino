int incomingByte = 0;   // for incoming serial data
long snake[64][2] = {{62, 64}, {63, 64}, {64, 64}, {65, 64}};
long snakeLen = 4;

void setup() {
        Serial.begin(9600);     // opens serial port, sets data rate to 9600 bps
}

void loop() {
        unsigned long previousMillis = millis();
        bool moved = false;
        int dir = 0;
        while(millis() - previousMillis <= 5000) {
          dir = 0;
          if (Serial.available() > 0) {
                  incomingByte = Serial.read();
                  moved = true;
                  dir = incomingByte;
                  break;
          }
        }
        snakeMove(dir);
}

void snakeMove(int dir) {
  if(dir != 10) {
    Serial.print("direction: ");
    Serial.print(dir);
    Serial.print("    ");
    int verDir = snake[snakeLen - 1][0] - snake[snakeLen - 2][0];
    int horDir = snake[snakeLen - 1][1] - snake[snakeLen - 2][1];
    if( (horDir == 1 && dir == 117) || (horDir == -1 && dir == 100) || (verDir == 1 && dir == -114) || (verDir == 1 && dir == 108) )
      return;
    int i = 0;
    for(i = 0; i < snakeLen - 1; ++i) { // remove first element (the tail of the snake)
      snake[i][0] = snake[i + 1][0];
      snake[i][1] = snake[i + 1][1];
    }
    switch(dir) {
      case(0): // continue same movement
      {
        if(verDir == 1) { // it is going right
          snake[snakeLen - 1][0] = snake[snakeLen - 2][0] + 1;
          snake[snakeLen - 1][1] = snake[snakeLen - 2][1];
        }
        else if(verDir == -1) { // it is going left
          snake[snakeLen - 1][0] = snake[snakeLen - 2][0] - 1;
          snake[snakeLen - 1][1] = snake[snakeLen - 2][1];
        }
        else if(horDir == 1) { // it is going down
          snake[snakeLen - 1][0] = snake[snakeLen - 2][0];
          snake[snakeLen - 1][1] = snake[snakeLen - 2][1] + 1;
        }
        else if(horDir == -1) { // it is going up
          snake[snakeLen - 1][0] = snake[snakeLen - 2][0];
          snake[snakeLen - 1][1] = snake[snakeLen - 2][1] - 1;
        }
        break;
      }
      case(117): // up
      {
        if(horDir != 1) {
          snake[snakeLen - 1][0] = snake[snakeLen - 2][0];
          snake[snakeLen - 1][1] = snake[snakeLen - 2][1] - 1;
        }
        else {
          snakeMove(0);
        }
        break;
      }
      case(100): // down
      {
        if(horDir != -1) {
          snake[snakeLen - 1][0] = snake[snakeLen - 2][0];
          snake[snakeLen - 1][1] = snake[snakeLen - 2][1] + 1;
        }
        else {
          snakeMove(0);
        }
        break;
      }
      case(114): // right
      {
        if(verDir != -1) {
          snake[snakeLen - 1][0] = snake[snakeLen - 2][0] + 1;
          snake[snakeLen - 1][1] = snake[snakeLen - 2][1];
        }
        else {
          snakeMove(0);
        }
        break;
      }
      case(108): // left
      {
        if(verDir != 1) {
          snake[snakeLen - 1][0] = snake[snakeLen - 2][0] - 1;
          snake[snakeLen - 1][1] = snake[snakeLen - 2][1];
        }
        else {
          snakeMove(0);
        }
        break;
      }
    }
    Serial.print("{ ");
    for(i = 0; i < snakeLen; ++i){
       Serial.print("{");
       Serial.print(snake[i][0]);
       Serial.print(", ");
       Serial.print(snake[i][1]);
       Serial.print("} ");
    }
    Serial.print("}");
    Serial.println();
  }
  return;
}
