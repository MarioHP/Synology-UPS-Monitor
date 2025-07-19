#ifndef SETTINGS_H
#define SETTINGS_H

// WiFi přihlašovací údaje
const char* WIFI_SSID = "";
const char* WIFI_PASSWORD = "";

// Statické IP nastavení sítě
const IPAddress local_IP(xxx,xxx,xxx,xxx);
const IPAddress gateway(xxx,xxx,xxx,xxx);
const IPAddress subnet(255,255,255,0);

// UPS server nastavení
const char* upsHost = "xxx,xxx,xxx,xxx"; // IP adresa NASu / UPS serveru
const uint16_t upsPort = 3493;
const char* upsName = "ups";

// Výchozí jazyk
#define DEFAULT_LANGUAGE "cz"
// #define DEFAULT_LANGUAGE "en"

// Interval obnovy webu v milisekundách (např. 60000 = 60 sekund)
const unsigned long WEBPAGE_RELOAD_INTERVAL_MS = 60000;

#endif
