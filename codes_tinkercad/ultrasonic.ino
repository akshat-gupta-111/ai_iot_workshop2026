// lets do it!

const int trigPin = 7; // Connect Trigger/Signal pin to digital pin 7
const int echoPin = 7; // Connect Echo pin to digital pin 7 (use separate pins like 9 and 10 if using a 4-pin sensor)

void setup() {
  Serial.begin(9600); // Start serial communication
}

void loop() {
  // Clear the trigPin by setting it LOW
  pinMode(trigPin, OUTPUT);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  // Send a 10 microsecond HIGH pulse to trigPin
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Read the echoPin, return the sound wave travel time in microseconds
  pinMode(echoPin, INPUT);
  long duration = pulseIn(echoPin, HIGH);
  
  // Calculate the distance in centimeters
  long distance = duration * 0.034 / 2;
  
  // Print the distance to the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  
  delay(500); // Wait half a second between readings
}
