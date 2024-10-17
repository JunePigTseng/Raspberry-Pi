int bzPin = 11;
int LEDPins[] = {7,6,5};
int delaytime = 200;

void setup() {
  pinMode(bzPin,OUTPUT);
  for(int i = 0; i < sizeof(LEDPins)/sizeof(int); i++)
  {
    pinMode(LEDPins[i],OUTPUT);
  }
  Serial.begin(115200);
}

enum Mode {NOTE, LED};
Mode mode = NOTE;

void loop() {
  char c;
  if(Serial.available())
  {
    c = Serial.read();
    if(c == 'n')
    {
      mode = NOTE;
    }
    else if(c == 'l')
    {
      mode = LED;
    }
    else if(mode == NOTE)
    {
      switch (c)
      {
        case '1':
          tone(bzPin,1046,delaytime);//發出c6 1秒
          Serial.println("發出c6");
          break;
        case '2':
          tone(bzPin,1175,delaytime);//發出d6 1秒
          Serial.println("發出d6");
          break;
        case '3':
          tone(bzPin,1318,delaytime);//發出e6 1秒
          Serial.println("發出e6");
          break;
        case '4':
          tone(bzPin,1397,delaytime);//發出f6 1秒
          Serial.println("發出f6");
          break;
        case '5':
          tone(bzPin,1568,delaytime);//發出g6 1秒
          Serial.println("發出g6");
          break;
        case '6':
          tone(bzPin,1760,delaytime);//發出a6 1秒
          Serial.println("發出a6");
          break;
        case '7':
          tone(bzPin,1976,delaytime);//發出b6 1秒
          Serial.println("發出b7");
          break;
        case 'c':
          tone(bzPin,523,delaytime);//發出c5 1秒（低8度）
          Serial.println("發出c5");
          break;
        case 'd':
          tone(bzPin,587,delaytime);//發出d5 1秒（低8度）
          Serial.println("發出d5");
          break;
        case 'e':
          tone(bzPin,659,delaytime);//發出e5 1秒（低8度）
          Serial.println("發出e5");
          break;
        case 'f':
          tone(bzPin,698,delaytime);//發出f5 1秒（低8度）
          Serial.println("發出f5");
          break;
        case 'g':
          tone(bzPin,784,delaytime);//發出g5 1秒（低8度）
          Serial.println("發出g5");
          break;
        case 'a':
          tone(bzPin,880,delaytime);//發出a5 1秒（低8度）
          Serial.println("發出a5");
          break;
        case 'b':
          tone(bzPin,988,delaytime);//發出b5 1秒（低8度）
          Serial.println("發出b5");
          break;
        case 'C':
          tone(bzPin,2093,delaytime);//發出c7 1秒（高8度）
          Serial.println("發出c7");
          break;
        case 'D':
          tone(bzPin,2349,delaytime);//發出d7 1秒（高8度）
          Serial.println("發出d7");
          break;
        case 'E':
          tone(bzPin,2637,delaytime);//發出e7 1秒（高8度）
          Serial.println("發出e7");
          break;
        case 'F':
          tone(bzPin,2794,delaytime);//發出f7 1秒（高8度）
          Serial.println("發出f7");
          break;
        case 'G':
          tone(bzPin,3136,delaytime);//發出g7 1秒（高8度）
          Serial.println("發出g7");
          break;
        case 'A':
          tone(bzPin,3520,delaytime);//發出a7 1秒（高8度）
          Serial.println("發出a7");
          break;
        case 'B':
          tone(bzPin,3951,delaytime);//發出b7 1秒（高8度）
          Serial.println("發出b7");
          break;
        case '0':
          noTone(bzPin);//停止發聲
          Serial.println("停止發聲");
          break;
      }
      delay(delaytime);
    }
    else if(mode == LED)
    {
      switch (c)
      {
        case '1':
          digitalWrite(LEDPins[0],HIGH);
          delay(delaytime);
          digitalWrite(LEDPins[0],LOW);
          break;
        case '2':
          digitalWrite(LEDPins[1],HIGH);
          delay(delaytime);
          digitalWrite(LEDPins[1],LOW);
          break;
        case '3':
          digitalWrite(LEDPins[2],HIGH);
          delay(delaytime);
          digitalWrite(LEDPins[2],LOW);
          break;
        case '0':
          digitalWrite(LEDPins[0],LOW);
          digitalWrite(LEDPins[1],LOW);
          digitalWrite(LEDPins[2],LOW);
          break;
        case '4':
          for(int i = 0; i < sizeof(LEDPins)/sizeof(int); i++)
          {
            digitalWrite(LEDPins[i],HIGH);
            delay(delaytime);
          }
          for(int i = 0; i < sizeof(LEDPins)/sizeof(int); i++)
          {
            digitalWrite(LEDPins[i],LOW);
            delay(delaytime);
          }
          break;
      }
    }
  }
}
