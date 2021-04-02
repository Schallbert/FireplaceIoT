#ifndef WIFICONNECT_H
#define WIFICONNECT_H

class WifiConnect 
{
    public:
    WifiConnect() = default;
    ~WifiConnect() = default;
    WifiConnect(WifiConnect &cpy) = delete;

    void connect();
    bool isConnected();

    private:
    void blockUntilSmartConfigIsComplete();
    void printSmartConfigComplete();
};

#endif // WIFICONNECT_H