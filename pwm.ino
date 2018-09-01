#include <Wire.h>
#include "Adafruit_DRV2605.h"

const int A9 = 9;
const int A10 =10;
const int A11 =11;
const int A12 =12;
const int A13 =13;
const int A15 =15;

const int SOA = 10;

const float V_OUT = 2;
int i = 0;

Adafruit_DRV2605 drv;

void setup() {
  Serial.begin(9600);
  drv.begin();
  
  //DRV2505LをPWM動作モードにする
  Serial.println("set PWM mode");
  drv.setMode(DRV2605_MODE_PWMANALOG);
  analogWrite(A9 , 128);
  analogWrite(A10, 128);
  analogWrite(A11, 128);

  Serial.println("start");
}

void loop() {  
  if(Serial.available()>0){
    switch (Serial.read()){
      case 'a':
        Serial.println("ahead");
        i=0;
        while(i<5){
          ahead();
          delay(1000);
          i++;
        }
        Serial.println("stop");
        break;
     case 'b':
        Serial.println("back");
        i=0;
        while(i<5){
          back();
          delay(1000);
          i++;
        }
        Serial.println("stop");
        break;
     case 'r':
        Serial.println("right");
        i=0;
        while(i<5){
          right();
          delay(1000);
          i++;
        }
        Serial.println("stop");
        break;
     case 'l':
        Serial.println("left");
        i=0;
        while(i<5){
          left();
          delay(1000);
          i++;
        }
        Serial.println("stop");
        break;
     default:
        Serial.println("stop");
        a9stop();
        a10stop();
        a11stop();
        break;
    }
  }


  
  //ahead();
  //delay(1000);
  //back();
  //delay(1000);
  //right();
  //delay(1000);
  //left();
  //delay(2000);
}

void a9start(){
  analogWrite(A9, 255);
}
void a9up(){
  for (int i = 128; i <= 255; i++){
    analogWrite(A9,  i);
    delay(5);
  }
}
void a9down(){
  for (int i = 255; i  >= 128; i--){
    analogWrite(A9,  i);
    delay(5);
  }
}
void a9stop(){
  analogWrite(A9, 128);
}

void a10start(){
  analogWrite(A10, 255);
}
void a10up(){
  for (int i = 128; i <= 255; i++){
    analogWrite(A10,  i);
    delay(5);
  }
}
void a10down(){
  for (int i = 255; i  >= 128; i--){
    analogWrite(A10,  i);
    delay(5);
  }
}
void a10stop(){
  analogWrite(A10, 128);
}

void a11start(){
  analogWrite(A11, 255);
}
void a11up(){
  for (int i = 128; i <= 255; i++){
    analogWrite(A11,  i);
    delay(5);
  }
}
void a11down(){
  for (int i = 255; i  >= 128; i--){
    analogWrite(A11,  i);
    delay(5);
  }
}
void a11stop(){
  analogWrite(A11, 128);
}

void downup(int down_pin, int up_pin){
  for(int i = 128; i<255; i++){
    //value = i * 10 + 128;
    analogWrite(down_pin, 383 - i);
    analogWrite(up_pin, i);
    //delay(10);
  }
}

void ahead(){
  a11up();
  delay(200);
  a11stop();
  delay(SOA);
  a9start();
  delay(200);
  a9down();
}

void back(){
  a9up();
  delay(200);
  a9stop();
  delay(SOA);
  a11start();
  delay(200);
  a11down();
}

void right(){
  a10up();
  delay(200);
  a10stop();
  delay(SOA);
  a9start();
  delay(200);
  a9down();
}

void left(){
  a9up();
  delay(200);
  a9stop();
  delay(SOA);
  a10start();
  delay(200);
  a10down();
}
