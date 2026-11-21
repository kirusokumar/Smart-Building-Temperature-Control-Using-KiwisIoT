#include <ESP8266WiFi.h>
#include <KiwisIoT.h>
#include <DHT.h>

const char* ssid = "YOUR_WIFI_NAME";
const char* pass = "YOUR_WIFI_PASSWORD";
const char* topic = "YOUR_TOPIC_ID";

#define DHT_PIN D4
#define DHT_TYPE DHT11

DHT dht(DHT_PIN, DHT_TYPE);

const float TEMP_LIMIT = 30.0;

KiwisIoT kiwisiot(ssid, pass, topic);

void sendDHTData() {

  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("Failed to read DHT sensor!");
    return;
  }

  String status;

  if (temperature >= TEMP_LIMIT) {
    status = "HIGH TEMPERATURE";
  } else {
    status = "TEMPERATURE NORMAL";
  }

  Serial.println();
  Serial.println("------ SMART BUILDING MONITORING ------");

  Serial.print("Temperature: ");
  Serial.print(temperature, 1);
  Serial.println(" C");

  Serial.print("Humidity: ");
  Serial.print(humidity, 1);
  Serial.println(" %");

  Serial.print("Status: ");
  Serial.println(status);

  kiwisiot.send("0", String(temperature, 1));
  kiwisiot.send("1", String(humidity, 1));
  kiwisiot.send("2", status);
}

void setup() {

  Serial.begin(115200);

  Serial.println();
  Serial.println("Smart Building Temperature Control");

  dht.begin();

  Serial.println("DHT sensor initialized");

  Serial.println("Connecting to KiwisIoT...");

  kiwisiot.begin();

  Serial.println("KiwisIoT initialized");
}

void loop() {

  kiwisiot.run();

  static unsigned long lastSend = 0;

  if (millis() - lastSend >= 2000) {
    lastSend = millis();
    sendDHTData();
  }

  delay(100);
}