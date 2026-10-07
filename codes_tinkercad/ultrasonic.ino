// Perimeter Guard - Intruder Detection
// Arduino + Ultrasonic Sensor

//define pins

long duration;
int distance;

// Define Danger zone in cm

void setup() {
  //define pinmode

  Serial.begin(9600);
}

void loop() {

  // Send ultrasonic pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read the returning signal
  duration = pulseIn(echoPin, HIGH);

  // Calculate distance

  // Display distance on Serial Monitor
  
  // Check if an intruder is detected
  if (distance <= dangerZone) {

    Serial.println("⚠ INTRUDER DETECTED!");

  } 
  else {

    Serial.println("PERIMETER CLEAR");

  }

  delay(500);
}