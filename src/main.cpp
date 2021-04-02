#include <Arduino.h>
#include <PubSubClient.h>

#include "SoftwareConfig.h"
#include "WifiConnect.h"
#include "Power.h"

static Power pwr;

void setup()
{
    Serial.begin(SERIALBAUD);
    WifiConnect wifi;
    wifi.connect();

    if(!wifi.isConnected())
    {
        pwr.powerOff();
    }
}

void loop()
{
    if (pwr.isBatteryLow())
    {
        pwr.powerOff();
    }
    
    // Connect MQTT
    // Check topic
    // Handle message

    // Control Fireplace


    pwr.sleepForMillis(SLEEPAWHILE);
}