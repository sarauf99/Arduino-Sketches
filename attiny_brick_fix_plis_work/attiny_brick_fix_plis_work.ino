int freq = 3;

void setup() {
  // put your setup code here, to run once:
pinMode(freq,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(freq,HIGH);
delay(1/16000000);
digitalWrite(freq,LOW);
delay(1/16000000);
}
