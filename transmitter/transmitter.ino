void setup() {
  Serial.begin(2400); // Initialize serial
  pinMode(2, INPUT); // Initialize the input pin
}

void loop() {
  byte data;
  
  if (digitalRead(2) == HIGH) { // If the input is 1, set the data to 1, else set the data to 0
    data = B00000001;
  } else {
    data = B00000000;
  }
  
  byte transmit = data ^ B10101010; // Use a bitwise XOR to apply a basic modulation to the data
  
  Serial.write(transmit); // Send the data
}
