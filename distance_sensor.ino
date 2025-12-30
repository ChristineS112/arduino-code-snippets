int trigPin = 12;
int echoPin = 11;
int buzzPin = 2;
float pingTravelTime;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzPin, OUTPUT);
}
void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  pingTravelTime = pulseIn(echoPin, HIGH);
  float distance = pingTravelTime * 0.0343 / 2;
  
  while(distance < 30 && distance > 0) { 
    digitalWrite(buzzPin, HIGH);
    
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    
    pingTravelTime = pulseIn(echoPin, HIGH);
    
    distance = pingTravelTime * 0.0343 / 2; 
  
    delay(50); 
  }

  digitalWrite(buzzPin, LOW);
  delay(100);
}
