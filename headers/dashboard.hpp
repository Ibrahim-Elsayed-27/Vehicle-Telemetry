#ifndef DASHBOARD_H
#define DASHBOARD_H

#include <memory>
#include <sstream>
#include <iostream>

#include "sensors.hpp"
#include "battery.hpp"
#include "ecu.hpp"
#include "logger.hpp"

class Dashboard {
public:
    Dashboard(const std::shared_ptr<SpeedSensor>& speedSensor,
             const std::shared_ptr<FuelSensor>& fuelSensor,
             const std::shared_ptr<TemperatureSensor>& tempSensor,
             const std::shared_ptr<Battery>& battery,
             const std::shared_ptr<RadarSensor>& radarSensor,
             const std::shared_ptr<EngineControlUnit>& engineECU,
             const std::shared_ptr<BrakeControlUnit>& brakeECU,
             const std::shared_ptr<TransmissionControlUnit>& transmissionECU,
             Logger& logger);

    void display();

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
};

#endif // DASHBOARD_H