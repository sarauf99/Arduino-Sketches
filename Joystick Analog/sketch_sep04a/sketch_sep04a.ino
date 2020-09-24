#include <Joystick.h>
#define xaxis A0
#define yaxis A1

Joystick_ Joystick;

void setup()
{
  // put your setup code here, to run once:
  pinMode(xaxis, INPUT);
  pinMode(yaxis, INPUT);
  pinMode(9, INPUT_PULLUP);
  pinMode(10, INPUT_PULLUP);
  pinMode(11, INPUT_PULLUP);
  pinMode(12, INPUT_PULLUP);
  //Serial.begin(115200);
  Joystick.begin();
}

// Constant that maps the phyical pin to the joystick button.
const int pinToButtonMap = 9;

// Last state of the button
int lastButtonState[4] = {0,0,0,0};

void loop()
{
   for (int index = 0; index < 4; index++)
  {
    int currentButtonState = !digitalRead(index + pinToButtonMap);
    if (currentButtonState != lastButtonState[index])
    {
      Joystick.setButton(index, currentButtonState);
      lastButtonState[index] = currentButtonState;
    }
  }
  Joystick.setXAxisRange(0, 1023);
  Joystick.setXAxis(analogRead(xaxis));
  Joystick.setYAxisRange(0, 1023);
  Joystick.setYAxis(analogRead(yaxis));
}
