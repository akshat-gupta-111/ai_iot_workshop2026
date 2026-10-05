// lets do it!

const int trigPin = 9;
const int echoPin = 10;
const int buzzerPin = 8; // Connect your passive or active buzzer here

long duration;
int distance;
bool systemFiring = false;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  
  Serial.begin(9600); // Must match the baud rate selected in the browser
}

void loop() {
  // 1. Listen for firing signals sent downstream from the browser utility
  if (Serial.available() > 0) {
    char command = Serial.read();
    if (command == 'F') {
      systemFiring = true;
    } else if (command == 'S') {
      systemFiring = false;
      noTone(buzzerPin); // Immediately silence the buzzer
    }
  }

  // 2. Read the ultrasonic sensor distance
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2; // Calculate distance in centimeters
  
  // 3. Send the raw numeric value to the frontend
  Serial.println(distance);
  
  // 4. Generate the audio fire sound if the threshold is crossed
  if (systemFiring) {
    // Alternates between two rapid frequencies to sound like firing lasers/pulses
    tone(buzzerPin, 880); 
    delay(30);
    tone(buzzerPin, 587);
    delay(30);
  } else {
    // Small baseline delay when idle to protect the serial buffer from flooding
    delay(60); 
  }
}
