# ** Synology-UPS-Monitor**
Jednoduchý UPS monitor pro Synology a UPS CyberPower s webovým serverem.

<img width="709" height="1123" alt="image" src="https://github.com/user-attachments/assets/5ea1c44d-da5c-4d18-a8ea-18e1f163d641" />



## **Hardware:**

## **Nastavení:**

>Ovládací panel - Hardware a napájení - UPS

> [!NOTE]
V nastavení Synology musí být stejná IP adresa jaká je v settings.h!

<img width="767" height="810" alt="image" src="https://github.com/user-attachments/assets/977d3a80-e999-47c3-a620-80372b1bf530" />


## **Software a funkce**

Výchozí nastavení v **settings.h**

- WIFI_SSID = ""; – název wifi
- WIFI_PASSWORD = "";  – heslo na wifi

- IPAddress local_IP(xxx,xxx,xxx,xxx); – IP adresa nonitoru v síti
- IPAddress gateway(xxx,xxx,xxx,xxx); – výchozí brána
- IPAddress subnet(255,255,255,0); – maska sítě

- const uint16_t upsPort = 3493; - port UPS
- const char* upsName = "ups"; 

- #define DEFAULT_LANGUAGE "cz" - výchozí jazyk čeština
  
- const unsigned long WEBPAGE_RELOAD_INTERVAL_MS = 60000;
