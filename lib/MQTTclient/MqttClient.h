#ifndef MQTTCLIENT_H
#define MQTTCLIENT_H

#include <PubSubClient.h>
#include "I_MqttClient.h"

// Wrapper class with no business logic.
// Created to enable interface class for loose coupling.

class MqttClient
{
    public:
    MqttClient(Client &client);
    ~MqttClient() = default;
    MqttClient(MqttClient &cpy) = delete;

    PubSubClient& setServer(const char * domain, uint16_t port);
    PubSubClient& setCallback(std::function<void(char*, uint8_t*, unsigned int)> callback);

    void loop();
    void connect(const char *clientId);
    void disconnect();

    void publish(const char *topic, const char *payload);
    void subscribe(const char *topic);
    void unsubscribe(const char *topic);

    bool isConnected();

    private:
    PubSubClient m_MqttClient;
};

#endif // MQTTCLIENT_H