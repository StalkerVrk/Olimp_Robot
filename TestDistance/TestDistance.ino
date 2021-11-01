void setup() {
  Serial.begin(9600);
  
  pinMode(11, OUTPUT);
}

void Test(){

  digitalWrite(11, 1);
  delayMicroseconds(10);
  digitalWrite(11, 0);
  double Get0 = pulseIn(A0, 1) / 49;
  
   
  Serial.print("A0: ");
  Serial.println(Get0);

  delay(500);
  }

void loop() {
  Test();
//  digitalWrite(11, 150);
}
