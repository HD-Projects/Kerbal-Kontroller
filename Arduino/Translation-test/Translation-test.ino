void setup() {
  Serial.begin(9600);

  pinMode(2, INPUT);
}

void loop() {
  delay(20);

  if (digitalRead(2) == HIGH) {
    Serial.println("HI");
  }
}