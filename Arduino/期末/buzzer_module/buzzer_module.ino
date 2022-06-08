int beep=12;
void setup() {
  // put your setup code here, to run once:
pinMode(beep,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
long frequency=300;
tone(beep,frequency);
delay(10*1000);
noTone(beep);
delay(10*1000);
}