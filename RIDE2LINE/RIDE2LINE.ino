double GLOBAL_LEFT = 0;
double GLOBAL_RIGHT = 0;

int SPEED_LEFT = 100;
int SPEED_RIGHT = 100;
int KOEF_SPEED = 100;
double K = 0.4;

void GetFromLine(){
  double Left = analogRead(0);
  double Right = analogRead(1);
  
  Serial.print("Left: ");
  Serial.println(Left);
  Serial.print("Right: ");
  Serial.println(Right);
  delay(500);
  }

// TODO Kalibrovka datchikov 10 raz


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
  delay(time2exec);
}

void setup() {
  Serial.begin(9600);

  Motor(0,0,0);    /* СДЕЛАТТЬ МНОЖЕСТВЕННУЮ ПРВОЕРКУ ЧЕРЕЗ МАТОЖИДАНИЕ*/
  GLOBAL_LEFT = analogRead(0);
  GLOBAL_RIGHT = analogRead(1);
  delay(500);
  
  
}

void loop() {

  double Left_line = analogRead(0);
  double Right_line = analogRead(1);
  int reg = (int)((Left_line - GLOBAL_LEFT) - (Right_line - GLOBAL_RIGHT))*K;
//  Serial.println(reg);
  if(reg > KOEF_SPEED){
    Motor(-((reg-SPEED_LEFT)%255),200, 50);
  }
  else if(reg < -KOEF_SPEED){
    Motor(200,-((-reg-SPEED_RIGHT)%255), 50);
  }
  Motor(SPEED_LEFT-reg,SPEED_RIGHT+reg);
  
}
