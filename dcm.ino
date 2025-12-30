int speedPin = 5;
int dir1 = 4;
int dir2 = 3;
int motorSpeed = 250;

void setup() {
  pinMode(speedPin, OUTPUT);
  pinMode(dir1, OUTPUT);
  pinMode(dir2, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(dir1, HIGH);
  digitalWrite(dir2, LOW);
  analogWrite(speedPin, motorSpeed);
  delay(3000);
  
  digitalWrite(dir1, HIGH);
  digitalWrite(dir2, LOW);
  
}