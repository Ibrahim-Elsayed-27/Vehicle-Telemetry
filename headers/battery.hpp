#ifndef BATTERY_HPP
#define BATTERY_HPP

#include <iostream>
#include <iomanip>      // For formatted output
#include <random>

class Battery {
public:
    Battery();
    void update();
    double readCharge() const;
    double readTemperature() const;
    friend std::ostream& operator<<(std::ostream& os, const Battery& battery);

private:
    double chargeLevel;
    double temperature;
};

#endif // BATTERY_HPP