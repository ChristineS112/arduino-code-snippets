int latchPin = 11;
int clockPin = 9;
int dataPin = 12;

byte LEDsOn = 0b01010101;
byte LEDsOff = 0b10101010;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, LEDsOn);
  digitalWrite(latchPin, HIGH);
  delay(1000);
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, LEDsOff);
  digitalWrite(latchPin, HIGH);
  delay(1000);
}
