void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}

int tmp = 0;

void loop() {
  
  tmp = random(25, 35);
  
  int Ax = random(-100,100);
  int Ay = random(-100, 100);
  int Az = random(-100, 100);

  int Gx = random(-100,100);
  int Gy = random(-100, 100);
  int Gz = random(-100, 100);

  int Tiltx = random(-100,100);
  int Tilty = random(-100, 100);
  int Tiltz = random(-100, 100);

  int speed[] = {random(0,100),random(0,100),random(0,100),random(0,100)};

  // Depth, Sonar 1, Sonar 2, Sonar 3
  int sonar[] = {random(0, 400), random(0, 400), random(0, 400), random(0, 400)};
  
  delay(100);
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
  Serial.print(Ax);
  Serial.write("\n");
  Serial.print(Ay);
  Serial.write("\n");
  Serial.print(Az);
  Serial.write("\n");

  Serial.write("$\n");
  Serial.write("GYR\n"); // Gyr
  Serial.write("#\n");

  // GYR Data
  Serial.print(Gx);
  Serial.write("\n");
  Serial.print(Gy);
  Serial.write("\n");
  Serial.print(Gz);
  Serial.write("\n");

  Serial.write("$\n");
  Serial.write("TLT\n"); // TLT
  Serial.write("#\n");

  // TLT Data
  Serial.print(Tiltx);
  Serial.write("\n");
  Serial.print(Tilty);
  Serial.write("\n");
  Serial.print(Tiltz);
  Serial.write("\n");

  Serial.write("$\n");
  Serial.write("SPD\n"); // Speed
  Serial.write("#\n");

  // Speed Data
  Serial.print(speed[0]);
  Serial.write("\n");
  Serial.print(speed[1]);
  Serial.write("\n");
  Serial.print(speed[2]);
  Serial.write("\n");
  Serial.print(speed[3]);
  Serial.write("\n");

  Serial.write("$\n");
  Serial.write("SON\n"); // Sonar
  Serial.write("#\n");

  // Speed Data
  Serial.print(sonar[0]);
  Serial.write("\n");
  Serial.print(sonar[1]);
  Serial.write("\n");
  Serial.print(sonar[2]);
  Serial.write("\n");
  Serial.print(sonar[3]);
  Serial.write("\n");
  
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
