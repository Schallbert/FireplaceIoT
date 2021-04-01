#include <Arduino.h>
#include <PubSubClient.h>
#include <WiFiClientSecure.h>
#include <WiFi.h>

constexpr uint32_t SERIALBAUD{115200};
constexpr uint16_t MSTOSEC{1000};

void setup()
{
    Serial.begin(SERIALBAUD);

    // Tries to connect with previous credentials or starts smartconfig
    if (WiFi.begin() == WL_CONNECT_FAILED)
    {
        // Init WiFi as Station, start SmartConfig
        WiFi.mode(WIFI_STA);
        WiFi.beginSmartConfig();

        //Wait for SmartConfig packet from mobile
        Serial.println("Waiting for SmartConfig.");
        while (!WiFi.smartConfigDone())
        {
            delay(MSTOSEC);
            Serial.print(".");
        }

        Serial.println("");
        Serial.println("SmartConfig received.");
    }
}

    void loop()
    {
        // put your main code here, to run repeatedly:
    }