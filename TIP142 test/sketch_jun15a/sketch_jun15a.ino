int d = 4;
void setup() {
  // put your setup code here, to run once:
  
  pinMode(d, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(d, HIGH);
  delay(700);
  digitalWrite(d, LOW);
  delay(700);
}
