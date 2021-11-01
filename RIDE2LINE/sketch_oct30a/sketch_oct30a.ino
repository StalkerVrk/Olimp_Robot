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
  // put your setup code here, to run once:

}

void loop() {
  Motor(100,100);

}
