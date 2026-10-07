#include "Arduino_LED_Matrix.h" 

ArduinoLEDMatrix matrix; 

void setup() {
  Serial.begin(115200);   
  matrix.begin();         
  
  while (!Serial) {
    ; 
  }
}

void loop() {
  
  if (Serial.available() > 0) {
    
    char incomingChar = Serial.read();  
    
    
    if (incomingChar == '\n' || incomingChar == '\r') {
      return;
    }

    if (incomingChar == '') { // ADD
      
      matrix.loadFrame(LEDMATRIX_HEART_BIG);
    } 
    else if (incomingChar == '') { //ADD
      
      matrix.loadFrame(LEDMATRIX_EMOJI_SAD);
    }
  }
}
