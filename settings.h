#ifndef SETTINGS_H
#define SETTINGS_H

// WiFi přihlašovací údaje
const char* WIFI_SSID = "MikroTik";
const char* WIFI_PASSWORD = "vitaj597+";

// Statické IP nastavení sítě
const IPAddress local_IP(192,168,2,119);
const IPAddress gateway(192,168,2,1);
const IPAddress subnet(255,255,255,0);
const IPAddress primaryDNS(8, 8, 8, 8);   // Google DNS
const IPAddress secondaryDNS(8, 8, 4, 4); // Google DNS

// UPS server nastavení
const char* upsHost = "192.168.2.100"; // IP adresa NASu / UPS serveru
const uint16_t upsPort = 3493;
const char* upsName = "ups";

// Výchozí jazyk
#define DEFAULT_LANGUAGE "cz"
// #define DEFAULT_LANGUAGE "en"

// Interval obnovy webu v milisekundách (např. 60000 = 60 sekund)
const unsigned long WEBPAGE_RELOAD_INTERVAL_MS = 60000;

#endif