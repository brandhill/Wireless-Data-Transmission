void setup() {
  Serial.begin(2400);
  pinMode(2, INPUT);
}

void loop() {
  byte data;
  
  if (digitalRead(2) == HIGH) {
    data = B00000001;
  } else {
    data = B00000000;
  }
  
  byte transmit = data ^ B10101010;
  
  Serial.write(transmit);
}
