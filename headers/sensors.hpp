#ifndef SENSORS_HPP
#define SENSORS_HPP

#include <random>
#include <cmath>
#include <iostream>
#include <iomanip>      // For formatted output

// Sensors interface
class Sensor {
public:
    virtual void update() = 0;
    virtual double readData() const = 0;
    virtual ~Sensor() = default;
};

// Speed Sensor Class (declaration)
class SpeedSensor : public Sensor {
private:
    double speed;  // Speed in km/h
public:
    SpeedSensor();
    void update() override;
    double readData() const override;
    friend std::ostream& operator<<(std::ostream& os, const SpeedSensor& sensor);
};

// Fuel Sensor Class (declaration)
class FuelSensor : public Sensor {
private:
    double fuelLevel;  // Fuel level in liters
public:
    FuelSensor();
    void update() override;
    double readData() const override;
    friend std::ostream& operator<<(std::ostream& os, const FuelSensor& sensor);
};

// Temperature Sensor Class (declaration)
class TemperatureSensor : public Sensor {
private:
    double temperature;  // Engine temperature in °C
    double speed; // Store the speed to simulate increasing temp with increasing the speed
public:
    TemperatureSensor();
    void update() override;
    double readData() const override;
    void setSpeed(double newSpeed);
    friend std::ostream& operator<<(std::ostream& os, const TemperatureSensor& sensor);
};

// Radar Sensor Class for Adaptive Cruise Control (declaration)
class RadarSensor : public Sensor {
private:
    double distance;  // Distance to the vehicle ahead in meters
public:
    RadarSensor();
    void update() override;
    double readData() const override;
    friend std::ostream& operator<<(std::ostream& os, const RadarSensor& sensor);
};

#endif // SENSORS_HPP