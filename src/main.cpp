// ESP32 WiFi Scanner - SSID only
// 每 10 秒掃描一次，僅在序列埠列出每個 SSID

#include <Arduino.h>
#include <WiFi.h>

void setup() {
	Serial.begin(9600);
	delay(1000);
	Serial.println();
	Serial.println("ESP32 WiFi Scanner - SSID only");

	WiFi.mode(WIFI_STA);
	WiFi.disconnect();
	delay(100);
}

void loop() {
	Serial.println("掃描 SSID...");
	int n = WiFi.scanNetworks();
	if (n <= 0) {
		Serial.println("未找到任何網路");
	} else {
		Serial.printf("共找到 %d 個網路:\n", n);
		for (int i = 0; i < n; ++i) {
			Serial.printf("%d: %s\n", i + 1, WiFi.SSID(i).c_str());
		}
	}

	WiFi.scanDelete();
	delay(10000);
}
