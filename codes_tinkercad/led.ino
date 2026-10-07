// lets do it!

void setup() {
  pinMode(13, OUTPUT); // Initialize digital pin 13 as an output
}

// The loop function runs over and over again forever
void loop() {
  digitalWrite(13, HIGH);   // Turn the LED on (HIGH is the voltage level)
  delay(1000);              // Wait for a second (1000 milliseconds)
  digitalWrite(13, LOW);    // Turn the LED off by making the voltage LOW
  delay(1000);              // Wait for a second
}