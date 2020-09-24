int sw;
void setup()
{
  // put your setup code here, to run once:
  pinMode(13, OUTPUT);
  Serial.begin(9600);

}

void loop()
{
  // put your main code here, to run repeatedly:
  while (Serial.available())
  {
    sw = Serial.read();

    if (sw == '1')
      digitalWrite(13, HIGH);
    else if (sw != '1')
      digitalWrite(13, LOW);
  }
  /*digitalWrite(13, HIGH);
    delay(500);
    digitalWrite(13, LOW);
    delay(500);*/
}
