int trigPin = 12;
int echoPin = 11;
int buzzPin = 2;
float pingTravelTime;

void setup() {
  // put your setup code here, to run once:

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzPin, OUTPUT);
}
void loop() {
  // 1. Get initial distance
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  pingTravelTime = pulseIn(echoPin, HIGH);
  float distance = pingTravelTime * 0.0343 / 2;
  

  // 2. The Loop
  while(distance < 30 && distance > 0) { // Added > 0 because pulseIn returns 0 on error
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