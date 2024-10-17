#ifndef VEHICLE_HPP
#define VEHICLE_HPP

#include "sensors.hpp"
#include "ecu.hpp"
#include "logger.hpp"
#include "battery.hpp"
#include "dashboard.hpp"
#include "diagnostics.hpp"
#include "acc.hpp"
#include <memory>

class Vehicle {
public:

    void updateSensors();
    void adaptiveCruiseControl();
    void displayDashboard();
    void runDiagnostics();
    Vehicle(const std::string& filePath);
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
    std::unique_ptr<Dashboard> dashboard;
    std::unique_ptr<VehicleDiagnostics> diagnostics;
    std::unique_ptr<CruiseControlSystem> cruiseControl;
    
};

#endif // VEHICLE_HPP