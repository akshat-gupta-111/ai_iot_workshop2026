// Tactical Alert Mission
// Use Arduino to control a buzzer

int buzzer = 8;       // Buzzer connected to pin 9
int alertLevel = 150; // Try changing this value

void setup() {
  // Set the buzzer pin as OUTPUT
  pinMode(buzzer, OUTPUT);
}

void loop() {

  // Activate the buzzer
  analogWrite(buzzer, alertLevel);

  // Keep the alarm ON for some time
  delay(500);

  // Turn the buzzer OFF
  analogWrite(buzzer, 0);

  // Wait before the next alert
  delay(500);

  // TODO:
  // Can you modify the alert pattern?
  // Try changing the alertLevel and delays.
}