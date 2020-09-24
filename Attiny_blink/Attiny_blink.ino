#include <SoftwareSerial.h>

void setup()  {
 Serial.begin(9600);
}
 
void loop()
{
 Serial.println("Can it be true?! A serial monitor indeed!");
 delay(10);
}
