void setup() {
  Serial.begin(9600);
}

void loop() {
  delay(1000);
  Serial.write("45"); // send a byte with the value 45
  Serial.write("\n");
  delay(1000);
  Serial.write("Timsah\n");
}
