const char x = A0, y = A1, z = A2;
const int b1 = 6, b2 = 7, b3 = 8, b4 = 9;
int magnitude();

void setup()
{
  // put your setup code here, to run once:
  pinMode(x, INPUT), (y, INPUT), (z, INPUT), (b1, INPUT), (b2, INPUT), (b3, INPUT), (b4, INPUT);

  Serial.begin(9600);
  Serial.print("Hello");
}

void loop()
{
  // put your main code here, to run repeatedly:
  /*Serial.print(analogRead(x));
    Serial.print(" ");
    Serial.print(analogRead(y));
    Serial.print(" ");
    Serial.print(analogRead(z));
    Serial.print(" ");
    Serial.print(mag);
    Serial.println();*/
  int mag = magnitude();
  int mapmag = map(mag, 0, 1118, 0, 255);
  int lim = 270;
  //Serial.println(mapmag);
  while (true)
  {
    if (digitalRead(b1) == HIGH && (lim - mapmag) < 50)
    {
      Serial.println('a');
      while (digitalRead(b1) == HIGH)
      {

      }
    }
    else if (digitalRead(b2) == HIGH && (lim - mapmag) < 50)
    {

      Serial.print('w');
      while (digitalRead(b2) == HIGH)
      {

      }
    }
    else if (digitalRead(b3) == HIGH && (lim - mapmag) < 50)
    {
      Serial.print("d");
      while (digitalRead(b3) == HIGH)
      {

      }
    }
    else if (digitalRead(b4) == HIGH && (lim - mapmag) < 50)
    {
      Serial.print("s");
      while (digitalRead(b4) == HIGH)
      {

      }
    }
    else if (digitalRead(b1) == HIGH && (lim - mapmag) > 50)
    {
      Serial.print("j");
      while (digitalRead(b1) == HIGH)
      {

      }
    }
    else if (digitalRead(b2) == HIGH && (lim - mapmag) > 50)
    {

      Serial.print("i");
      while (digitalRead(b2) == HIGH)
      {

      }
    }
    else if (digitalRead(b3) == HIGH && (lim - mapmag) > 50)
    {
      Serial.print("l");
      while (digitalRead(b3) == HIGH)
      {

      }
    }
    else if (digitalRead(b4) == HIGH && (lim - mapmag) > 50)
    {
      Serial.print("k");
      while (digitalRead(b4) == HIGH)
      {

      }
    }


  }
}

int magnitude()
{
  return ((analogRead(x) ^ 2) + (analogRead(y) ^ 2) + (analogRead(z) ^ 2)) ^ (1 / 2);
}
