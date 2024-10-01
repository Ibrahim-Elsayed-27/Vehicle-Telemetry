#include "../headers/battery.hpp"

/// Constructor for the Battery class
/// Initializes charge level to 100% and temperature to 25°C.
Battery::Battery() : chargeLevel(100.0), temperature(25.0) {}

/// Simulates battery usage by decreasing charge level and randomly adjusting temperature.
void Battery::update() {
    /// Calculate random battery usage between 0.1 and 0.3
    double usage = (rand() % 3 + 1) * 0.1;

    /// Decrease charge level, ensuring it doesn't go below 0
    chargeLevel = (chargeLevel - usage > 0) ? chargeLevel - usage : 0;

    /// Randomly adjust temperature within a small range
    temperature += (rand() % 3 - 1) * 0.1;
}

/// Reads the current charge level of the battery.
/// @return The current charge level in percentage.
double Battery::readCharge() const {
    return chargeLevel;
}

/// Reads the current temperature of the battery.
/// @return The current temperature in degrees Celsius.
double Battery::readTemperature() const {
    return temperature;
}

/// Overloads the << operator to print battery information to an output stream.
/// @param os The output stream to write to.
/// @param battery The Battery object to print.
/// @return The output stream.
std::ostream& operator<<(std::ostream& os, const Battery& battery) {
    os << "Battery Charge: " << std::fixed << std::setprecision(2) << battery.chargeLevel << "%, "
    << "Battery Temperature: " << std::fixed << std::setprecision(2) << battery.temperature << " °C";
    return os;
}