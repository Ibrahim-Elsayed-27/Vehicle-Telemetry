#include "../headers/vehicle.hpp"

/**
 * @brief Constructor for the Vehicle class, initializing all components.
 * 
 * This constructor initializes all the sensors, ECUs, and the logger for the vehicle.
 */
Vehicle::Vehicle(const std::string& filePath) :
    speedSensor(std::make_shared<SpeedSensor>()),
    fuelSensor(std::make_shared<FuelSensor>()),
    tempSensor(std::make_shared<TemperatureSensor>()),
    battery(std::make_shared<Battery>()),
    radarSensor(std::make_shared<RadarSensor>()),
    engineECU(std::make_shared<EngineControlUnit>()),
    brakeECU(std::make_shared<BrakeControlUnit>()),
    transmissionECU(std::make_shared<TransmissionControlUnit>()),
    logger(Logger::GetInstance(filePath)),
    dashboard(std::make_unique<Dashboard>(speedSensor, fuelSensor, tempSensor, battery, radarSensor, engineECU, brakeECU, transmissionECU, logger)),
    diagnostics(std::make_unique<VehicleDiagnostics>(speedSensor, fuelSensor, tempSensor, battery, radarSensor, logger)),
    cruiseControl(std::make_unique<CruiseControlSystem>(radarSensor, engineECU, brakeECU, logger))
{}

/**
 * @brief Updates all sensors and logs the results.
 * 
 * This function updates the state of all sensors in the vehicle and logs each update.
 */
void Vehicle::updateSensors() {
    logger.Log("\n\nUpdating sensors.");

    speedSensor->update();
    logger.Log("Speed sensor updated.");

    fuelSensor->update();
    logger.Log("Fuel sensor updated.");

    tempSensor->setSpeed(speedSensor->readData());
    tempSensor->update();
    logger.Log("Temperature sensor updated.");

    battery->update();
    logger.Log("Battery updated.");

    radarSensor->update();
    logger.Log("Radar sensor updated.");
}

/**
 * @brief Displays the current vehicle dashboard.
 * 
 * This function delegates the responsibility to the Dashboard class to display
 * the current sensor readings, ECU states, and other relevant vehicle status details.
 */
void Vehicle::displayDashboard() {
    dashboard->display();
}

/**
 * @brief Runs diagnostic checks on all vehicle components.
 * 
 * This function delegates the responsibility to the VehicleDiagnostics class,
 * which performs a series of diagnostic checks on the sensors and logs the results.
 */
void Vehicle::runDiagnostics() {
    diagnostics->runDiagnostics();
}

/**
 * @brief Implements the adaptive cruise control functionality.
 * 
 * This function delegates the responsibility to the CruiseControlSystem class, 
 * which adjusts the vehicle's throttle and brake settings based on radar sensor readings.
 */
void Vehicle::adaptiveCruiseControl() {
    cruiseControl->adaptiveCruiseControl();
}
