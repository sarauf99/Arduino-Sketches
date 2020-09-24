#include <HCSR04.h>

int sig = 8;
int trig = 4;
int echo = 5;
HCSR04 s1(trig,echo);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(sig,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(s1.dist());
  if(s1.dist()<100)
    digitalWrite(sig,HIGH);
  else
    digitalWrite(sig,LOW);
}
