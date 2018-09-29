void setup() {
  // put your setup code here, to run once:
pinMode(D4,OUTPUT);
pinMode(D3,INPUT);
Serial.begin(9600);
}

void loop() {
//trig pin  D4
//echo pin  D3
  // put your main code here, to run repeatedly:
digitalWrite(D4, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(D4, HIGH);
delayMicroseconds(10);
digitalWrite(D4, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
int duration = pulseIn(D3, HIGH);
// Calculating the distance
double distance= duration*0.034/2;
// Prints the distance on the Serial Monitor
Serial.print("Distance: ");
Serial.println(distance);
delay(250);
}
