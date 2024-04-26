#include <WiFi.h>
#include <HTTPClient.h>
#include <DHT.h>
#include <Wire.h>
#include <Adafruit_BMP280.h>
#include "credentials.h"

#define DHTPIN 19
#define I2C_SDA 18
#define I2C_SCL 17

TwoWire I2CBMP = TwoWire(0);
DHT dht22(DHTPIN, DHT22);
Adafruit_BMP280 bmp(&I2CBMP);

String URL = "http://" + IP + "/weather/postdata.php";

int temp = 0;
int hum = 0;
int temp_bmp = 0;
int pres = 0;

void setup() {
    Serial.begin(115200);
    I2CBMP.begin(I2C_SDA, I2C_SCL, 100000);
    bmp.begin(0x77);
    dht22.begin();
    WiFiConnect();
}

void loop() {
    temp = dht22.readHumidity();
    hum = dht22.readTemperature();
    temp_bmp = bmp.readTemperature();
    pres = bmp.readPressure();
    Serial.println(temp_bmp);
    Serial.println(pres);
    sendPostRequest();
    delay(10000);
}

void WiFiConnect() {
    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, password);
    
    while (WiFi.status() != WL_CONNECTED) {
        delay(300);
        Serial.print(".");
    }

    Serial.print("\nConnected to: ");
    Serial.println(ssid);
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());
}


void sendPostRequest() {
    String postdata = "temp=" + String(temp) + "&temp_bmp=" + String(temp_bmp) + "&hum=" + String(hum) + "&pres=" + String(pres);
    HTTPClient http;
    http.begin(URL);

    http.addHeader("Content-Type", "application/x-www-form-urlencoded");
    int httpcode = http.POST(postdata);
    String response = http.getString();

    Serial.print("URL: ");
    Serial.println(URL);
    Serial.print("Data: ");
    Serial.println(postdata);
    Serial.print("httpcode: ");
    Serial.println(httpcode);
    Serial.print("response: ");
    Serial.println(response);
}