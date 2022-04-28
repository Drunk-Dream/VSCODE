/*

【Arduino】168种传感器模块系列实验（55）

实验五十五：DHT11 温湿度复合传感器模块（数字型单总线通信）

实验程序之二

*/

#include "DHT.h"

#define DHTPIN 2     

#define DHTTYPE DHT11   

DHT dht(DHTPIN, DHTTYPE);

void setup() {

Serial.begin(9600);

Serial.println("DHTxx test!");

  dht.begin();

}

void loop() {



delay(2000);

float h = dht.readHumidity();

float t = dht.readTemperature();

float f = dht.readTemperature(true);



if(isnan(h) || isnan(t) || isnan(f)) {

Serial.println("Failed to read from DHT sensor!");

return;

  }

float hi = dht.computeHeatIndex(f, h);

Serial.print("Humidity: ");

  Serial.print(h);

Serial.print(" %");

Serial.print("\t");

Serial.print("Temperature: ");

  Serial.print(t);

Serial.println(" *C ");



}
