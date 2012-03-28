int pin = 5;

void setup() {
  Serial.begin(2400); // Initialize serial
  pinMode(pin, INPUT); // Initialize the input pin
  digitalWrite(pin, HIGH); // Activate the internal pullup
  pinMode(13, OUTPUT); // Initialize the onboard LED
}

byte modulate(byte data) {
  return data ^ B10101010; // Use a bitwise XOR to apply a basic modulation to the data
}

void loop() {
  byte data;
  
  if (digitalRead(pin) == HIGH) { // If the input is 1, set the data to 1, else set the data to 0
    data = modulate(1);
    digitalWrite(13, HIGH);
  } else {
    data = modulate(0);
    digitalWrite(13, LOW);
  }
  
  Serial.write(modulate(255)); // Send random packet to prepare for data transfer
  Serial.write(data); // Send the data
  
  delay(100); // Pause to avoid overloading the connection
}
