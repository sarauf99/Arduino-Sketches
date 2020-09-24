#include <HCSR04.h>

int w11 = 8, w12 = 9, w21 = 11, w22 = 13;
int ust1 = 2, use1 = 3, ust2 = 4, use2 = 5, ust3 = 6, use3 = 7;
const char ir1 = A0, ir2 = A1, ir3 = A2, ir4 = A3;
int fn;
HCSR04 us1(ust1, use1), us2(ust2, use2), us3(ust3, use3);


int fw();
int bw();
int stp();
int hcsr04();
int right();
int left();



void setup() {
  // put your setup code here, to run once:
  pinMode(w11, OUTPUT), (w12, OUTPUT), (w21, OUTPUT), (w22, OUTPUT), (ir1, INPUT), (ir2, INPUT), (ir3, INPUT), (ir4, INPUT);
  Serial.begin(9600);
}

void loop()
{
  bool ir_1 = digitalRead(ir1), ir_2 = digitalRead(ir2), ir_3 = digitalRead(ir3), ir_4 = digitalRead(ir4);
  Serial.println(ir_1);
  Serial.println(ir_2);
  Serial.println(ir_3);
  Serial.println(ir_4);
  Serial.println();
  //  delay(2000);
  if (ir_1 == 1 && ir_2 == 1 && ir_3 == 1 && ir_4 == 1)
  {
    stp();
  }
  else// if (ir_1 < 40 && ir_2 < 40 && ir_3 < 40 && ir_4 < 40)
  {
    hcsr04();
  }
}

int fw()
{
  digitalWrite(w11, HIGH);
  analogWrite(w12, 155);
  analogWrite(w21, 100);
  digitalWrite(w22, LOW);
  return 1;
}

int bw() {
  digitalWrite(w11, LOW);
  digitalWrite(w12, HIGH);
  digitalWrite(w21, LOW);
  digitalWrite(w22, HIGH);
  return 1;
}

int stp()
{
  digitalWrite(w11, LOW);
  digitalWrite(w12, LOW);
  digitalWrite(w21, LOW);
  digitalWrite(w22, LOW);
  return 1;
}

int left()
{
  digitalWrite(w11, HIGH);
  analogWrite(w12, 0);
  analogWrite(w21, 0);
  digitalWrite(w22, HIGH);
  return 1;
}

int right()
{
  digitalWrite(w11, LOW);
  analogWrite(w12, 255);
  analogWrite(w21, 255);
  digitalWrite(w22, LOW);
  return 1;
}

int hcsr04()
{

  bool ir_1 = digitalRead(ir1), ir_2 = digitalRead(ir2), ir_3 = digitalRead(ir3), ir_4 = digitalRead(ir4);
  if (ir_1 == 0 && ir_2 == 0)
  {
    //bool ir_1=digitalRead(ir1),ir_2=digitalRead(ir2),ir_3=digitalRead(ir3),ir_4=digitalRead(ir4)
    if (us1.dist() > 8)
    {
      fw();
    }
    else if (us1.dist() < 8 && us2.dist() > 12)
    {
      right();
    }
    else if (us1.dist() < 8 && us3.dist() > 12)
    {
      left();
    }
    else
    {
      bw();
      delay(700);
      stp();
    }
  }
  else if (ir_1 == 1 || ir_2 == 1)
  {
    bw();
    if (ir_3 == 1 && us2.dist() > 12)
    {
      right();
    }
    else if (ir_4 == 1 && us3.dist() > 12)
    {
      left();
    }
    else if (ir_4 == 1 && ir_3 == 1)
    {
      fw();
    }
    delay(750);
    if (us2.dist() > 12)
    {
      right();
    }
    else if (us3.dist() > 12)
    {
      left();
    }
    else
    {
      stp();
    }
  }

  return 1;
}
