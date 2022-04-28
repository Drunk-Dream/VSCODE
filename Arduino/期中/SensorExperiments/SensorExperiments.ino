// SensorExperiments
#include "DHT.h"
#define DHTPIN 2
#define DHTTYPE DHT11
#define pirPin 7
#define soundPin A5

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(pirPin, INPUT);
  pinMode(soundPin, INPUT);
  dht.begin();
  delay(2000);
}

void loop() {
  // put your main code here, to run repeatedly:
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  float f = dht.readTemperature(true);
  double soundV = analogRead(soundPin);
  int pirValue = digitalRead(pirPin);

  if(isnan(h) || isnan(t) || isnan(f)) {
  Serial.println("Failed to read from DHT sensor!");
  return;
  }

  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print(" %");
  Serial.print("\t");
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.println(" *C ");

  Serial.print("isHuman:");
  Serial.print(pirValue);

  Serial.print("sound: ");
  Serial.println(soundV);

  delay(500);
}
