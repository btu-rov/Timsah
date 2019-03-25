void setup() {
  Serial.begin(9600);
}

int tmp = 0;

void loop() {
  
  tmp++;
  delay(300);
  Serial.write("$\n");
  Serial.write("TMP\n"); // Temp
  Serial.write("#\n");

  // Temp Data
  Serial.print(tmp);
  Serial.write("\n");
  
  Serial.write("$\n");
  Serial.write("ACC\n"); // Acc
  Serial.write("#\n");

  // ACC Data
  Serial.write("100\n");
  Serial.write("200\n");
  Serial.write("300\n");

  Serial.write("$\n");
  Serial.write("GYR\n"); // Gyr
  Serial.write("#\n");

  // GYR Data
  Serial.write("-100\n");
  Serial.write("220\n");
  Serial.write("540\n");

  // End of data
  Serial.write("$$\n");
}
