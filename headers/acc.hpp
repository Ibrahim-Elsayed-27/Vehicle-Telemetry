#ifndef CRUISE_CONTROL_SYSTEM_H
#define CRUISE_CONTROL_SYSTEM_H

#include <memory>
#include <sstream>
#include <iostream>

#include "sensors.hpp"
#include "ecu.hpp"
#include "logger.hpp"

class CruiseControlSystem {
public:
    CruiseControlSystem(const std::shared_ptr<RadarSensor>& radarSensor,
                       const std::shared_ptr<EngineControlUnit>& engineECU,
                       const std::shared_ptr<BrakeControlUnit>& brakeECU,
                       Logger& logger);

    void adaptiveCruiseControl();

private:
    std::shared_ptr<RadarSensor> radarSensor;
    std::shared_ptr<EngineControlUnit> engineECU;
    std::shared_ptr<BrakeControlUnit> brakeECU;
    Logger& logger;
};

#endif // CRUISE_CONTROL_SYSTEM_H