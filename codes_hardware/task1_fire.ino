const int trigPin = ;
const int echoPin = ;
const int buzzerPin = 8;

long duration;
int distance;
bool systemFiring = false;

void setup() {
  pinMode(trigPin, ); //ADD
  pinMode(echoPin, ); //ADD
  pinMode(buzzerPin, ); //ADD
  
  Serial.begin(9600); 
}

void loop() {
  
  if (Serial.available() > 0) {
    char command = Serial.read();
    if (command == 'F') {
      systemFiring = true;
    } else if (command == 'S') {
      systemFiring = false;
      noTone(buzzerPin); 
    }
  }

 
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, ); // ADD
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, ); // ADD
  distance = duration * 0.034 / 2; 
  

  Serial.println(distance);
  

  if (systemFiring) {
    
    tone(buzzerPin, 880); 
    delay(30);
    tone(buzzerPin, 587);
    delay(30);
  } else {
    delay(60); 
  }
}
