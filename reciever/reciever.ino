void setup() {
  Serial.begin(2400); // Initialize serial
  pinMode(13, OUTPUT); // Initialize the onboard LED
}

void loop() {
  if (Serial.available()) { // Only read data if it is available
    byte recieved = Serial.read(); // Read the raw data
    byte data = recieved ^ B10101010; // Process using a bitwise XOR to remove the modulation
    
    if (data == B00000001) { // Turn on the LED if it recieved a 1
      digitalWrite(13, HIGH);
    } else if (data == B00000000) { // Turn off the LED it recieved a 0
      digitalWrite(13, LOW);
    }
  }
}
