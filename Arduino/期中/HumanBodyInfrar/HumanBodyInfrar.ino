#define pirPin 7

void setup() {
  // put your setup code here, to run once:
  pinMode(pirPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int pirValue =digitalRead(pirPin);
  Serial.println(pirValue);
  delay(1000);
}
