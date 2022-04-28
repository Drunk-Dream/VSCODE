#define soundPin A5

void setup() {
  // put your setup code here, to run once:
  pinMode(soundPin,INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  double soundV = analogRead(soundPin);
  Serial.println(soundV);
  delay(1000);
}
