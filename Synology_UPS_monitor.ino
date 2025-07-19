// Board: NodeMCU 1.0 (ESP-12E)
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include "settings.h"
#include "html.h"
#include "translations_cz.h"
#include "translations_en.h"
#include <Arduino.h>
#include <map>

WiFiClient client;
ESP8266WebServer server(80);
std::map<String, String> upsData;

// Načti UPS data
void updateUpsData() {
  upsData.clear();

if (!client.connect(upsHost, upsPort)) {
  Serial.println("Nelze se připojit k UPS serveru");
  return;
}

  client.printf("LIST VAR %s\n", upsName);
  unsigned long timeout = millis() + 2000;

  while (millis() < timeout) {
    while (client.available()) {
      String line = client.readStringUntil('\n');
      line.trim();
      if (line.startsWith("VAR")) {
        int a = line.indexOf(' ', 4);
        int b = line.indexOf(' ', a + 1);
        int q1 = line.indexOf('"', b);
        int q2 = line.indexOf('"', q1 + 1);

        if (a != -1 && b != -1 && q1 != -1 && q2 != -1) {
          String key = line.substring(a + 1, b);
          String value = line.substring(q1 + 1, q2);
          upsData[key] = value;
        }
      }
    }
  }

  client.stop();
}

// Obsluha webové stránky
void handleRoot() {
  updateUpsData();

  String lang = String(DEFAULT_LANGUAGE);
  const std::map<String, String>* translations = nullptr;

  if (lang == "en") {
    translations = &paramTranslations_en;
  } else {
    translations = &paramTranslations_cz;
  }

  server.send(200, "text/html", generateHtml(upsData, *translations, lang));
  String wifiSignal = String(WiFi.RSSI()) + " dBm";
  
}

void setup() {
  Serial.begin(115200);

  // Nastavení statické IP
  if (!WiFi.config(local_IP, gateway, subnet, primaryDNS, secondaryDNS)) {
    Serial.println("Chyba při nastavování statické IP!");
  }

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

  Serial.print("Připojování k WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500); Serial.print(".");
  }

  Serial.println("\nWiFi připojeno, IP: " + WiFi.localIP().toString());

  server.on("/", handleRoot);
  server.begin();
  Serial.println("HTTP server spuštěn");
}

void loop() {
  server.handleClient();
}
