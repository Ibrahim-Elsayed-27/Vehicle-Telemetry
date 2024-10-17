#include "../headers/acc.hpp"

/**
 * @brief Constructor for the CruiseControlSystem class.
 * 
 * This constructor initializes the cruise control system by receiving shared pointers to the radar sensor,
 * engine control unit (ECU), and brake control unit (ECU), along with a reference to the logger.
 * 
 * @param radarSensor Shared pointer to the radar sensor.
 * @param engineECU Shared pointer to the engine control unit (ECU).
 * @param brakeECU Shared pointer to the brake control unit (ECU).
 * @param logger Reference to the logger for logging adaptive cruise control operations.
 */
CruiseControlSystem::CruiseControlSystem(const std::shared_ptr<RadarSensor>& radarSensor,
                    const std::shared_ptr<EngineControlUnit>& engineECU,
                    const std::shared_ptr<BrakeControlUnit>& brakeECU,
                    Logger& logger)
    : radarSensor(radarSensor), engineECU(engineECU), brakeECU(brakeECU), logger(logger) {}

/**
 * @brief Implements adaptive cruise control logic.
 * 
 * This function adjusts the vehicle's speed and braking based on the distance to the vehicle ahead,
 * as detected by the radar sensor. The system slows down if the distance is less than 50 meters, 
 * maintains speed for distances between 50 and 100 meters, and accelerates if the distance exceeds 100 meters.
 */
void CruiseControlSystem::adaptiveCruiseControl() {
    logger.Log("\n\nRunning adaptive cruise control.");

    double distance = radarSensor->readData();
    logger.Log("Radar detected distance: " + std::to_string(distance));

    if (distance < 50) {
        logger.Log("Distance < 50, slowing down.");
        engineECU->setThrottlePosition(30);
        brakeECU->setBrakePressure(50);
    } else if (distance < 100) {
        logger.Log("Distance between 50 and 100, maintaining speed.");
        engineECU->setThrottlePosition(50);
        brakeECU->setBrakePressure(0);
    } else {
        logger.Log("Distance > 100, speeding up.");
        engineECU->setThrottlePosition(70);
        brakeECU->setBrakePressure(0);
    }
}
