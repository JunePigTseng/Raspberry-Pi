int lightSensorPin = A0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println(
    (analogRead(lightSensorPin) / 1000.0) * 3.3
  );
  delay(100);
}
