#include <HCSR04.h>

HCSR04 hc(2, 1); //initialisation class HCSR04 (trig pin , echo pin)
int out = 4;
int in = 3;
int potp = 0;

void setup()
{
  pinMode(out, OUTPUT);
  pinMode(in, INPUT);
  pinMode(potp, OUTPUT);
}

void loop()
{
  digitalWrite(potp, LOW);
  int ran = analogRead(in);
  int dis;
  dis = map(ran, 0, 1023, 20, 200);

  {
    if (hc.dist() < 200)
      digitalWrite(out, HIGH);
    else
      digitalWrite(out, LOW);
  }
}
