// Подключаем библиотеку SoftwareSerial
#include <SoftwareSerial.h>
#include <Servo.h>

//для манипулятора 
#define MAGIC_NUM 58.2;

Servo manip;
Servo mainServo;
int probe = 160;
int bucket = 30;
//45 - 180
void manipServoTr(int a){ 
  manip.write(a);
}

//30-120
void mainServoTr( int a) {
  mainServo.write(a);
}
 
// Создаем класс BTserial для работы с bluetooth модулем.
SoftwareSerial BTserial(0, 1); // порт RX, порт TX
 
void setup()
{
  // Настраиваем скорость передачи данных.
  Serial.begin(9600);  
  BTserial.begin(9600); // По умолчанию 9600 бот.

  manip.attach(9);
  mainServo.attach(10);
  
  
  delay(1000);
  manipServoTr(probe);
  mainServoTr(bucket);
}

void Motor(int SpeedRight, int SpeedLeft, int time2exec=100){
  if (SpeedRight > 0){
    digitalWrite(4, 0);
    analogWrite(5, SpeedRight);
  }
  else if (SpeedRight < 0){
    digitalWrite(4, 1);
    analogWrite(5, -SpeedRight);
  }
  else
  {
    digitalWrite(4, 0);
    analogWrite(5, 0);
    
  }

  if (SpeedLeft > 0){
    digitalWrite(7, 0);
    analogWrite(6, SpeedLeft);
  }
  else if (SpeedLeft < 0){
    
  digitalWrite(7, 1);
    analogWrite(6, -SpeedLeft);
  }
  else
  {
    digitalWrite(7, 0);
    analogWrite(6, 0);
    
  }
  Serial.println("OK");
  delay(time2exec);
}
 
void loop()
{
  // Получаем данные от bluetooth модуля и передаем их в монитор порта.
  if (BTserial.available())
  {
    
    String incomingString = BTserial.readStringUntil('\n');
    incomingString.trim();
    Serial.println(incomingString);
    
    if (incomingString == "go"){
        Serial.println("vpered");
        Motor(120,120);
        
      }
    if (incomingString == "back"){
        Serial.println("nazad");
        Motor(-120,-120);
      }
    if (incomingString == "left"){
      Serial.println("nalevo");
      Motor(-95,95);
    }
    if (incomingString == "right"){
      Serial.println("napravo");
      Motor(95,-95);
    }
    if (incomingString == "stop"){
      Serial.println("stop");
      Motor(0,0);
    }
    if (incomingString == "sh"){
      probe=probe+10;
      manipServoTr(probe);
    }
    if (incomingString == "raz"){
      probe= probe-10;
      manipServoTr(probe);
    }
    if (incomingString == "bu"){
      bucket=bucket+10;
      mainServoTr(bucket);
    }
    if (incomingString == "bd"){
      bucket= bucket-10;
      mainServoTr(bucket);
    }
  }
  // Получаем данные от монитора порта и передаем их в bluetooth модуль.
  if (Serial.available())
  {
    BTserial.write(Serial.read());
  }
}
