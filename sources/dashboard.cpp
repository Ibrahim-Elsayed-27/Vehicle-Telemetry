#include "../headers/dashboard.hpp"

/**
 * @brief Constructor for the Dashboard class.
 * 
 * This constructor initializes the dashboard by receiving shared pointers to various sensors and ECUs,
 * as well as a reference to the logger for logging dashboard displays.
 * 
 * @param speedSensor Shared pointer to the speed sensor.
 * @param fuelSensor Shared pointer to the fuel sensor.
 * @param tempSensor Shared pointer to the temperature sensor.
 * @param battery Shared pointer to the battery.
 * @param radarSensor Shared pointer to the radar sensor.
 * @param engineECU Shared pointer to the engine control unit (ECU).
 * @param brakeECU Shared pointer to the brake control unit (ECU).
 * @param transmissionECU Shared pointer to the transmission control unit (ECU).
 * @param logger Reference to the logger for logging dashboard information.
 */
Dashboard::Dashboard(const std::shared_ptr<SpeedSensor>& speedSensor,
            const std::shared_ptr<FuelSensor>& fuelSensor,
            const std::shared_ptr<TemperatureSensor>& tempSensor,
            const std::shared_ptr<Battery>& battery,
            const std::shared_ptr<RadarSensor>& radarSensor,
            const std::shared_ptr<EngineControlUnit>& engineECU,
            const std::shared_ptr<BrakeControlUnit>& brakeECU,
            const std::shared_ptr<TransmissionControlUnit>& transmissionECU,
            Logger& logger)
    : speedSensor(speedSensor), fuelSensor(fuelSensor), tempSensor(tempSensor),
        battery(battery), radarSensor(radarSensor), engineECU(engineECU),
        brakeECU(brakeECU), transmissionECU(transmissionECU), logger(logger) {}

/**
 * @brief Displays the vehicle dashboard.
 * 
 * This function outputs the current state of all sensors and ECUs to the console, 
 * including speed, fuel, temperature, battery, radar, throttle position, brake pressure, 
 * and transmission gear. It also logs the display to the logger.
 */
void Dashboard::display() {
    logger.Log("\n\nDisplaying vehicle dashboard.");
    
    std::ostringstream dashboard;
    dashboard << "\n======= Vehicle Dashboard =======\n"
              << *speedSensor << '\n'
              << *fuelSensor << '\n'
              << *tempSensor << '\n'
              << *battery << '\n'
              << *radarSensor << '\n'
              << "Throttle Position: " << engineECU->getThrottlePosition() << "%\n"
              << "Brake Pressure: " << brakeECU->getBrakePressure() << "%\n"
              << "Current Gear: " << transmissionECU->getGear() << '\n'
              << "=================================\n";

    std::cout << dashboard.str() << std::endl;
}
