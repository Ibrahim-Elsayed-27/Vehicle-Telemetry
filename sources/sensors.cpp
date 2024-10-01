#include "../headers/sensors.hpp"

// Speed Sensor Class (implementation)
SpeedSensor::SpeedSensor() : speed(0.0) {}

/// Updates the speed sensor with a randomly generated value between 0 and 200 km/h.
void SpeedSensor::update() {
    speed = rand() % 201;
}

/// Reads the current speed from the sensor.
/// @return The current speed in km/h.
double SpeedSensor::readData() const {
    return speed;
}

/// Overloads the << operator to print speed sensor information to an output stream.
/// @param os The output stream to write to.
/// @param sensor The SpeedSensor object to print.
/// @return The output stream.
std::ostream& operator<<(std::ostream& os, const SpeedSensor& sensor) {
    os << "Speed: " << sensor.speed << " km/h";
    return os;
}

// Fuel Sensor Class (implementation)
FuelSensor::FuelSensor() : fuelLevel(50.0) {}

/// Updates the fuel sensor by simulating fuel consumption.
void FuelSensor::update() {
    /// Calculate random fuel consumption between 0.1 and 0.5 liters
    double consumption = (rand() % 5 + 1) * 0.1;

    /// Decrease fuel level, ensuring it doesn't go below 0
    fuelLevel = (fuelLevel - consumption > 0) ? fuelLevel - consumption : 0;
}

/// Reads the current fuel level from the sensor.
/// @return The current fuel level in liters.
double FuelSensor::readData() const {
    return fuelLevel;
}

/// Overloads the << operator to print fuel sensor information to an output stream.
/// @param os The output stream to write to.
/// @param sensor The FuelSensor object to print.
/// @return The output stream.
std::ostream& operator<<(std::ostream& os, const FuelSensor& sensor) {
    os << "Fuel Level: " << std::fixed << std::setprecision(2) << sensor.fuelLevel << " liters";
    return os;
}

// Temperature Sensor Class (implementation)
TemperatureSensor::TemperatureSensor() : temperature(70.0), speed(0) {}

/// Updates the temperature sensor based on current speed and random fluctuations.
void TemperatureSensor::update() {
    /// Calculate temperature based on speed and random fluctuations
    temperature = 70.0 + (speed * 0.1) + (rand() % 5 - 2);
}

/// Reads the current temperature from the sensor.
/// @return The current temperature in degrees Celsius.
double TemperatureSensor::readData() const {
    return temperature;
}

/// Sets the speed used for temperature calculations.
/// @param newSpeed The new speed value.
void TemperatureSensor::setSpeed(double newSpeed) {
    speed = newSpeed;
}

/// Overloads the << operator to print temperature sensor information to an output stream.
/// @param os The output stream to write to.
/// @param sensor The TemperatureSensor object to print.
/// @return The output stream.
std::ostream& operator<<(std::ostream& os, const TemperatureSensor& sensor) {
    os << "Engine Temperature: " << std::fixed << std::setprecision(2) << sensor.temperature << " °C";
    return os;
}

// Radar Sensor Class for Adaptive Cruise Control (implementation)
RadarSensor::RadarSensor() : distance(100.0) {}

/// Updates the radar sensor with a randomly generated distance between 10 and 200 meters.
void RadarSensor::update() {
    distance = rand() % 191 + 10;
}

/// Reads the current distance from the radar sensor.
/// @return The current distance in meters.
double RadarSensor::readData() const {
    return distance;
}

/// Overloads the << operator to print radar sensor information to an output stream.
/// @param os The output stream to write to.
/// @param sensor The RadarSensor object to print.
/// @return The output stream.
std::ostream& operator<<(std::ostream& os, const RadarSensor& sensor) {
    os << "Front Vehicle Distance: " << std::fixed << std::setprecision(2) << sensor.distance << " meters";
    return os;
}