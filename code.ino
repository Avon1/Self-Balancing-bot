void setup() {
  pinMode(8, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(9, INPUT);
  digitalWrite(11, HIGH);
  digitalWrite(8, LOW);
  Serial.begin(9600);
}
double trig(int trig, int echo) {
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  int duration = pulseIn(echo, HIGH);
  double distance = duration * 0.034 / 2;
//  delay(100);
  return distance;
}
void loop() {
  double x = 0 ;
  for (int i = 0 ; i < 5 ; i ++) {
    x = x + trig (10, 9);
  }
  Serial.println(x / 5);
}

