#include <WiFi.h>

#include "SoftwareConfig.h"
#include "WifiConnect.h"

void WifiConnect::connect()
{
    // Tries to connect with previous credentials or starts smartconfig
    if (WiFi.begin() == WL_CONNECT_FAILED)
    {
        // Init WiFi as Station, start SmartConfig
        WiFi.mode(WIFI_STA);
        WiFi.beginSmartConfig();

        //Wait for SmartConfig packet from mobile
        Serial.println("Waiting for SmartConfig.");
        blockUntilSmartConfigIsComplete();
    }
}

void WifiConnect::blockUntilSmartConfigIsComplete()
{
    while (!WiFi.smartConfigDone())
    {
        delay(1 * MSTOSEC);
        Serial.print(".");
    }
    printSmartConfigComplete();
}

void WifiConnect::printSmartConfigComplete()
{
    Serial.println("");
    Serial.println("SmartConfig received.");
    Serial.print("Connected as [");
    Serial.print(WiFi.localIP());
    Serial.println("].");
}

bool WifiConnect::isConnected()
{
    return WiFi.isConnected();
}
