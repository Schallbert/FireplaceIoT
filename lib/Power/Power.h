#ifndef POWER_H
#define POWER_H

#include "Arduino_types.h"

class Power
{
    public:
    Power() = default;
    ~Power() = default;
    Power(Power &cpy) = delete;

    void sleepForMillis(uint16_t sec);
    void powerOff();

    bool isBatteryLow();
};

#endif // POWER_H