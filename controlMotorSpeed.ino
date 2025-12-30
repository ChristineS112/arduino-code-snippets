int speedPin = 5;
int dir1 = 4;
int dir2 = 3;
int BP1 = 8;
int BP2 = 9;
int BP1Val = 0;
int BP2Val = 0;
int dt = 100;

int motorSpeed = 0;

void setup() {
  pinMode(speedPin, OUTPUT);
  pinMode(dir1, OUTPUT);
  pinMode(dir2, OUTPUT);
  pinMode(BP1, INPUT_PULLUP);
  pinMode(BP2, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {

  BP1Val = digitalRead(BP1);
  BP2Val = digitalRead(BP2);
  if(BP1Val == 0)
  {
    motorSpeed -=10;
    delay(dt);
  }
  if(BP2Val == 0)
  {
    motorSpeed += 10;
    delay(dt);
  }
  if(motorSpeed > 255)
  {
    motorSpeed = 255;
  }
  if(motorSpeed < -255)
  {
    motorSpeed = -255;
  }
  if(motorSpeed == 10)
  {
    motorSpeed = 100;
  }
  if(motorSpeed == -10)
  {
    motorSpeed = -100;
  }
  if(motorSpeed == 90 || motorSpeed == 95 || motorSpeed == -90 || motorSpeed == -95)
  {
    motorSpeed = 0;
  }
  if(motorSpeed > 0)
  {
    digitalWrite(dir1, HIGH);
    digitalWrite(dir2, LOW);
  }
  else
  {
    digitalWrite(dir1, LOW);
    digitalWrite(dir2, HIGH);
  }
  analogWrite(speedPin, abs(motorSpeed));
  Serial.println(motorSpeed);
  delay(dt);
}