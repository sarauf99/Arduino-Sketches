int D = 7;
const char A = A4;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(A, INPUT);
  pinMode(D, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("Digital: ");
  Serial.print(digitalRead(D));
  Serial.print(" Analog:");
  Serial.print(analogRead(A));
  Serial.println();
  delay(500);

}
