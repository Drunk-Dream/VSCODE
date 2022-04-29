const int xPin = A0;   
const int yPin = A1; 
const int btPin = 7;

void setup()
{
  pinMode(btPin,INPUT);
  digitalWrite(btPin, HIGH);
  Serial.begin(9600);
}

void loop()
{
  Serial.print("X: ");
  //读取A0的值并打印
  Serial.print(analogRead(xPin),DEC);
  Serial.print("\tY: ");
  Serial.print(analogRead(yPin),DEC);
  Serial.print("\tZ: ");
  Serial.println(digitalRead(btPin));
  delay(100);
}