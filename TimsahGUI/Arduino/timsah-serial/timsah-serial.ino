void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}

int tmp = 0;

void loop() {
  
  tmp++;
  delay(3000);
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

// Get serial data
void serialEvent(){
  String in = Serial.readString();
    Serial.write("I received: ");
    Serial.print(in);
    Serial.write("\n");
    // If first char is 1 then turn on led
    if(in[0] == '1') {
      digitalWrite(13, HIGH);
    }else {
      digitalWrite(13, LOW); 
    }
}
