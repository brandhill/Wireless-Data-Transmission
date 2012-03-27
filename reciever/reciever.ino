void setup() {
  Serial.begin(2400);
  pinMode(13, OUTPUT);
}

void loop() {
  if (Serial.available()) {
    byte recieved = Serial.read();
    byte data = recieved ^ B10101010;
    
    if (data == B00000001) {
      digitalWrite(13, HIGH);
    } else if (data == B00000000) {
      digitalWrite(13, LOW);
    }
  }
}
