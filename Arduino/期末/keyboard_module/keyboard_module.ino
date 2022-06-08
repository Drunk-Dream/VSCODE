void setup() {
  // put your setup code here, to run once:
  pinMode(2,INPUT);
  pinMode(3,INPUT);
  pinMode(4,INPUT);
  pinMode(5,INPUT);
  pinMode(6,INPUT);
  pinMode(7,INPUT);
  pinMode(8,INPUT);
  pinMode(10,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
 if(digitalRead(2)) tone(10,523,100);
 //如果2号引脚电压值为真（按下了对应键）那就让无源音箱基于10号引脚输出523HZ 20ms
 if(digitalRead(3)) tone(10,587,100);
 if(digitalRead(4)) tone(10,659,100);
 if(digitalRead(5)) tone(10,698,100);
 if(digitalRead(6)) tone(10,784,100);
 if(digitalRead(7)) tone(10,880,100);
 if(digitalRead(8)) tone(10,988,100);
    }
