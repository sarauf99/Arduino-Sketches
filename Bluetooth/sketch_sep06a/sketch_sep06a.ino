#define red 9
#define gre 10
#define blu 11

int rcol, grcol, gcol, bcol;

void setup()
{
  // put your setup code here, to run once:
  pinMode(red, OUTPUT);
  pinMode(gre, OUTPUT);
  pinMode(blu, OUTPUT);
  Serial.begin(9600);
}

String rgb;
//char inte;
int val;
void loop()
{
  rgb = '\n';
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0)
  {
    rgb = Serial.readString();
    //rgb += inte;
  }
  //Serial.println(rgb);
  val = rgb.toInt();
  //Serial.println(val);
  rcol = val / 1000000;
  grcol = val - rcol * 1000000;
  gcol = grcol / 1000;
  bcol = grcol - gcol * 1000;
  analogWrite(red,rcol);
  analogWrite(blu,bcol);
  analogWrite(gre,gcol);
}
