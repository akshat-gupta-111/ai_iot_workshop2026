// lets do it!
#include "Arduino_LED_Matrix.h" // Include the built-in R4 LED Matrix library

ArduinoLEDMatrix matrix; // Create an instance of the LED matrix

// Corrected 3-element uint32_t array for a "Broken Heart" 💔
const uint32_t broken_heart[] = {
    0x30c79e7d,
    0xe3bc1d80,
    0xe0040000
};

void setup() {
  Serial.begin(115200);   // Initialize USB Serial communication
  matrix.begin();         // Initialize the LED matrix
  
  // Wait for the native USB serial port to open (essential for the UNO R4)
  while (!Serial) {
    ; 
  }
}

void loop() {
  // Check if data is available to read over USB
  if (Serial.available() > 0) {
    // Read the incoming byte (as a character)
    char incomingChar = Serial.read();
    
    // Ignore newline or carriage return characters sent by serial monitors
    if (incomingChar == '\n' || incomingChar == '\r') {
      return;
    }

    if (incomingChar == '1') {
      // Print a full heart using the pre-designed frame gallery
      matrix.loadFrame(LEDMATRIX_HEART_BIG);
    } 
    else if (incomingChar == '0') {
      // Print the custom broken heart frame using the correct function
      matrix.loadFrame(LEDMATRIX_EMOJI_SAD);
    }
  }
}
