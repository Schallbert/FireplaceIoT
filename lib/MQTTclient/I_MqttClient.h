#ifndef I_MQTTCLIENT_H
#define I_MQTTCLIENT_H

#include <functional>
#include "Arduino_types.h"

class PubSubClient;

class I_MqttClient
{
public:
    virtual ~I_MqttClient() {};

    virtual PubSubClient& setServer(const char * domain, uint16_t port) = 0;
    virtual PubSubClient& setCallback(std::function<void(char*, uint8_t*, unsigned int)> callback) = 0;

    virtual void loop() = 0;
    virtual void connect(const char *clientId) = 0;
    virtual void disconnect() = 0;

    virtual void publish(const char *topic, const char *payload) = 0;
    virtual void subscribe(const char *topic) = 0;
    virtual void unsubscribe(const char *topic) = 0;

    virtual bool isConnected() = 0;
};

#endif // MQTTCLIENT_H