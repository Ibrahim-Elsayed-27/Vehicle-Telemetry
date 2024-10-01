#ifndef VEHICLE_HPP
#define VEHICLE_HPP

#include "sensors.hpp"
#include "ecu.hpp"
#include "logger.hpp"
#include "battery.hpp"
#include <memory>

class Vehicle {
public:

    void updateSensors();
    void adaptiveCruiseControl();
    void displayDashboard();
    void runDiagnostics();
    static Vehicle &GetInstance();

private:
    std::shared_ptr<SpeedSensor> speedSensor;
    std::shared_ptr<FuelSensor> fuelSensor;
    std::shared_ptr<TemperatureSensor> tempSensor;
    std::shared_ptr<Battery> battery;
    std::shared_ptr<RadarSensor> radarSensor;
    std::shared_ptr<EngineControlUnit> engineECU;
    std::shared_ptr<BrakeControlUnit> brakeECU;
    std::shared_ptr<TransmissionControlUnit> transmissionECU;
    Logger& logger;
    Vehicle();
    Vehicle(const Vehicle&) = delete;
    void operator=(const Vehicle&) = delete;
};

#endif // VEHICLE_HPP