void setup() {
  // put your setup code here, to run once:gg
  Serial.begin(115200);
  pinMode(2, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(2) == 1)
  {
    Serial.println("S");
  }
  else
  {
    Serial.println("G");
  }
  //g delay(500);
}
