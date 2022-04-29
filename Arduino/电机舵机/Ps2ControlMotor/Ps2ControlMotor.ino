#include <Stepper.h>
const int xPin = A0;
const int yPin = A1;
const int btPin = 7;

// 这里设置步进电机旋转一圈是多少步
#define STEPS 100

//设置步进电机的步数和引脚（就是注意点2里面说的驱动板上IN1～IN4连接的四个数字口）。
Stepper stepper(STEPS, 2, 4, 3, 5);


void setup()
{
  pinMode(btPin,INPUT);
  digitalWrite(btPin, HIGH);
  Serial.begin(9600);
    // 设置电机的转速：每分钟为90步
  stepper.setSpeed(90);
}

void loop(){
    int xCoordinate = analogRead(xPin);
    if (xCoordinate < 400)
    {
        stepper.step(10);
    }
    else if(xCoordinate > 600)
    {
        stepper.step(-10);
    }
    
}