#include "../headers/battery.hpp"

/**
 * @brief Constructor for the Battery class
 * @details Initializes charge level to 100% and temperature to 25°C.
 */
Battery::Battery() : chargeLevel(100.0), temperature(25.0) {}

/**
 * @brief Simulates battery usage by decreasing charge level and randomly adjusting temperature.
 * @details Uses random number generators to simulate battery usage and temperature fluctuations.
 */
void Battery::update() {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_real_distribution<> usage_dist(0.1, 0.3);
    std::uniform_real_distribution<> temp_dist(-0.1, 0.1);

    double usage = usage_dist(gen);
    chargeLevel = std::max(0.0, chargeLevel - usage);
    temperature += temp_dist(gen);
}

/**
 * @brief Reads the current charge level of the battery.
 * @return The current charge level in percentage.
 */
double Battery::readCharge() const {
    return chargeLevel;
}

/**
 * @brief Reads the current temperature of the battery.
 * @return The current temperature in degrees Celsius.
 */
double Battery::readTemperature() const {
    return temperature;
}

/**
 * @brief Overloads the << operator to print battery information to an output stream.
 * @param os The output stream to write to.
 * @param battery The Battery object to print.
 * @return The output stream.
 */
std::ostream& operator<<(std::ostream& os, const Battery& battery) {
    os << "Battery Charge: " << std::fixed << std::setprecision(2) << battery.chargeLevel << "%, "
       << "Battery Temperature: " << std::fixed << std::setprecision(2) << battery.temperature << " °C";
    return os;
}