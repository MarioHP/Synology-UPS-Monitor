# **Synology UPS Monitor**
Jednoduchý a levný monitor pro **Synology** a UPS **CyberPower** s webovým serverem. Jazyková verze Česky a English.
Monitor je napájený z USB a tak jej jde připojit přímo do volného portu USB Synology.

<img width="600" alt="image" src="https://github.com/user-attachments/assets/dab9d36d-5157-4f36-8195-b14481aa5054" />

>Testováno pouze s UPS CyberPower UT850EG, ale bude pravděpodobně funkční i s jinými UPS.

> [!NOTE]
V plánu je o něco dražší verze pro LilyGO TTGO T-Displej ESP32 s přímým zobrazením základních hodnot UPS na displeji.

<p float="left">
  <img width="400" alt="image1" src="https://github.com/user-attachments/assets/5ea1c44d-da5c-4d18-a8ea-18e1f163d641" />
  <img width="400" alt="image2" src="https://github.com/user-attachments/assets/0f2d1d25-95f7-46e9-961b-ad1a9cba586f" />
</p>

## **Hardware:**
https://www.laskakit.cz/iot-esp8266-lua-nodemcu-amica-cp2102-wifi-modul/

Krabička (3D tisk):

https://makerworld.com/en/models/1620122-synology-ups-monitor-with-webserver


## **Nastavení:**

>Ovládací panel - Hardware a napájení - UPS

> [!NOTE]
V nastavení Synology musí být stejná IP adresa, jaká je **IP adresa nonitoru v síti** v settings.h!

<img width="500" alt="image" src="https://github.com/user-attachments/assets/977d3a80-e999-47c3-a620-80372b1bf530" />


## **Software a funkce**

Výchozí nastavení v **settings.h**

- WIFI_SSID = ""; – název wifi
- WIFI_PASSWORD = "";  – heslo na wifi

- IPAddress local_IP(xxx,xxx,xxx,xxx); – IP adresa nonitoru v síti a v nastavení Synology (např. 192.168.2.119)
- IPAddress gateway(xxx,xxx,xxx,xxx); – výchozí brána
- IPAddress subnet(255,255,255,0); – maska sítě
 
- const uint16_t upsPort = 3493; - port UPS
- const char* upsName = "ups"; - jméno UPS
 
- #define DEFAULT_LANGUAGE "cz" - výchozí jazyk čeština
 
- const unsigned long WEBPAGE_RELOAD_INTERVAL_MS = 60000; - obnova stránky webového serveru (1 minuta).

## **html_basic**

> [!NOTE]
Základní data o UPS. Při použití **přejmenuj na html.h**

<img width="500" alt="image" src="https://github.com/user-attachments/assets/92823cf1-2133-48a0-a41c-0bd934d26013" />


