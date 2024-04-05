#include <WiFi.h>
#include <HTTPClient.h>
#include <DHT.h>
#include "credentials.h"

#define DHTPIN 27

DHT dht22(DHTPIN, DHT22);

String URL = "http://" + IP + "/weather/testdata.php";

int temp = 0;
int hum = 0;

void setup() {
    Serial.begin(115200);
    dht22.begin();
    WiFiConnect();
}

void loop() {
    temp = dht22.readHumidity();
    hum = dht22.readTemperature();
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
    String postdata = "temp=" + String(temp) + "&hum=" + String(hum);
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