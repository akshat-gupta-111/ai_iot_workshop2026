// lets do it!

int buzzerPin = 8; // Define the digital pin connected to the buzzer

void setup() {
  pinMode(buzzerPin, OUTPUT); // Set the buzzer pin as an output
}

void loop() {
  tone(buzzerPin, 1000);   // Play a 1000 Hz tone for 1 second
  delay(1000);             // Wait 1 second
  noTone(buzzerPin);       // Stop the tone
  delay(1000);             // Wait 1 second
}