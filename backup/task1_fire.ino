// Define pin connections
const int trigPin = 9;
const int echoPin = 8;
const int ledPin = 12;
const int buzzerPin = 11;

// Define threshold distance as a variable (in cm)
long thresholdDistance = 50; 

void setup() {
  Serial.begin(9600);       // Start serial communication
  pinMode(trigPin, OUTPUT);  // Set trigger pin as output
  pinMode(echoPin, INPUT);   // Set echo pin as input
  pinMode(ledPin, OUTPUT);   // Set LED pin as output
  pinMode(buzzerPin, OUTPUT);// Set buzzer pin as output
}

void loop() {
  // Clear the trigger pin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  // Send a 10-microsecond pulse to trigger pin
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Read the echo pin and calculate distance in cm
  long duration = pulseIn(echoPin, HIGH);
  long distance = duration * 0.034 / 2;
  
  // Print distance to Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  
  // Check if distance is below the threshold
  if (distance <= thresholdDistance && distance > 0) {
    digitalWrite(ledPin, HIGH);   // Turn LED ON
    digitalWrite(buzzerPin, HIGH); // Turn Buzzer ON
  } else {
    digitalWrite(ledPin, LOW);    // Turn LED OFF
    digitalWrite(buzzerPin, LOW);  // Turn Buzzer OFF
  }
  
  delay(500); // Wait half a second between readings
}
