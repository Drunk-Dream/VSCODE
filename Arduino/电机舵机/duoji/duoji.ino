#include <Servo.h>
Servo a;
int i,p,j,k;
void setup(){
  a.attach(8);//指定舵机a的OUT引脚为3号引脚
  Serial.begin(9600);
}
void loop(){
  i = analogRead(A0);//获取A0引脚的输入值，即PS2摇杆X轴的数值
  j = analogRead(A1);//获取A1引脚的输入值，即PS2摇杆Y轴的数值
  Serial.print("映射前x轴：");
  Serial.print(i);
  Serial.print(" ");
  Serial.print("映射前y轴：");
  Serial.print(j);
  Serial.print(" ");
  p = map(i,0,1023,0,180);//将0到1023的值映射成0到180
  k = map(j,0,1023,0,255);
  Serial.print("映射后x轴：");
  Serial.print(p);
  Serial.print(" ");
  Serial.print("映射后y轴：");
  Serial.println(k);
  a.write(p);//设置舵机a角度为p
  analogWrite(5,k);
}
