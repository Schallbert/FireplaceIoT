#ifndef WIFICONNECT_H
#define WIFICONNECT_H

class WifiConnect 
{
    public:
    WifiConnect() = default;
    ~WifiConnect() = default;
    WifiConnect(WifiConnect &cpy) = delete;

    void connectUsingSmarConfig();
    bool isConnected();

    private:
    void blockUntilSmartConfigIsComplete();
    void printSmartConfigComplete();

    bool connected{false};
};

#endif // WIFICONNECT_H