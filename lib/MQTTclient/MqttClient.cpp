#include "MqttClient.h"

MqttClient::MqttClient(Client &client) : m_MqttClient(client) {};

PubSubClient &MqttClient::setServer(const char *domain, uint16_t port)
{
    return m_MqttClient.setServer(domain, port);
}

PubSubClient &MqttClient::setCallback(std::function<void(char *, uint8_t *, unsigned int)> callback)
{
    return m_MqttClient.setCallback(callback);
}

void MqttClient::loop()
{
    m_MqttClient.loop();
}

void MqttClient::connect(const char *clientId)
{
    m_MqttClient.connect(clientId);
}

void MqttClient::disconnect()
{
    m_MqttClient.disconnect();
}

void MqttClient::publish(const char *topic, const char *payload)
{
    m_MqttClient.publish(topic, payload);
}

void MqttClient::subscribe(const char *topic)
{
    m_MqttClient.subscribe(topic);
}

void MqttClient::unsubscribe(const char *topic)
{
    m_MqttClient.unsubscribe(topic);
}

bool MqttClient::isConnected()
{
    return m_MqttClient.connected();
}