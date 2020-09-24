#define red 3
#define gre 5
#define blu 6

#include <SoftwareSerial.h>
SoftwareSerial rgbl(10,11);
void setup() {
  // put your setup code here, to run once:
  rgbl.begin(9600);
  pinMode(red,OUTPUT);
  pinMode(gre,OUTPUT);
  pinMode(blu,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (rgbl.available() >1)
  {
    int rval = rgbl.parseInt();    
    int gval = rgbl.parseInt();    
    int bval = rgbl.parseInt();

    if (rgbl.read() == '\n')
    {
      analogWrite(red,rval);
      analogWrite(gre,gval);
      analogWrite(blu,bval);
    }
  }
}
