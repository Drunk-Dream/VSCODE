#define C1 262
#define C2 294
#define C3 330
#define C4 350
#define C5 393
#define C6 441
#define C7 494
#define C0 0

int tune[] =
{
  C1,C1,C5,C5,C6,C6,C5,C0,C4,C4,C3,C3,
  C2,C2,C1,C0,C5,C5,C4,C4,C3,C3,C2,C0,
  C5,C5,C4,C4,C3,C3,C2,C0,C1,C1,C5,C5,
  C6,C6,C5,C0,C4,C4,C3,C3,C2,C2,C1,C0
};
float durt[]=
{
  0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,
  0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,
  0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,
  0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5
};

int length;
int tonepin = 7;
void setup() {
    pinMode(tonepin, OUTPUT);
    length = sizeof(tune) / sizeof(tune[0]);
}

void loop()
{
  for(int x=0;x<length;x++)
  {
    tone(tonepin,tune[x]);
    delay(1000*durt[x]);
    noTone(tonepin);
  }
  delay(2*1000);
}
