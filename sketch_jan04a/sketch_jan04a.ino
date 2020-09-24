void setup() {
  // put your setup code here, to run once:
pinMode(A0,INPUT),(A1,INPUT),(A2,INPUT),(A3,INPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(digitalRead(A0));
  Serial.println(digitalRead(A1));
  Serial.println(digitalRead(A2));
  Serial.println(digitalRead(A3));
  Serial.clear;
}
