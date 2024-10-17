#ifndef VEHICLE_DIAGNOSTICS_H
#define VEHICLE_DIAGNOSTICS_H

#include <memory>
#include <sstream>
#include <iostream>
#include <iomanip>

#include "sensors.hpp"
#include "battery.hpp"
#include "logger.hpp"

class VehicleDiagnostics {
public:
    VehicleDiagnostics(const std::shared_ptr<SpeedSensor>& speedSensor,
                       const std::shared_ptr<FuelSensor>& fuelSensor,
                       const std::shared_ptr<TemperatureSensor>& tempSensor,
                       const std::shared_ptr<Battery>& battery,
                       const std::shared_ptr<RadarSensor>& radarSensor,
                       Logger& logger);

    void runDiagnostics();

private:
    std::shared_ptr<SpeedSensor> speedSensor;
    std::shared_ptr<FuelSensor> fuelSensor;
    std::shared_ptr<TemperatureSensor> tempSensor;
    std::shared_ptr<Battery> battery;
    std::shared_ptr<RadarSensor> radarSensor;
    Logger& logger;
};

#endif // VEHICLE_DIAGNOSTICS_H