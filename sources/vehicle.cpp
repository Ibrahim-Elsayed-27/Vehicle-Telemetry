#include "../headers/vehicle.hpp"

/**
 * @brief Constructor for the Vehicle class, initializing all components.
 * 
 * This constructor initializes all the sensors, ECUs, and the logger for the vehicle.
 */
Vehicle::Vehicle() :
    speedSensor(std::make_shared<SpeedSensor>()),
    fuelSensor(std::make_shared<FuelSensor>()),
    tempSensor(std::make_shared<TemperatureSensor>()),
    battery(std::make_shared<Battery>()),
    radarSensor(std::make_shared<RadarSensor>()),
    engineECU(std::make_shared<EngineControlUnit>()),
    brakeECU(std::make_shared<BrakeControlUnit>()),
    transmissionECU(std::make_shared<TransmissionControlUnit>()),
    logger(Logger::GetInstance("E:\\Mozakra\\Software\\OOP\\Vehicle_Telemetry\\log.txt"))
{}

/**
 * @brief Singleton pattern implementation to get a reference to the Vehicle instance.
 * @return Reference to the Vehicle instance.
 */
Vehicle& Vehicle::GetInstance() {
    static Vehicle instance;
    return instance;
}

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
 * @brief Implements adaptive cruise control logic based on radar sensor readings.
 * 
 * This function adjusts the vehicle's speed based on the distance to the vehicle ahead,
 * as detected by the radar sensor.
 */
void Vehicle::adaptiveCruiseControl() {
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

/**
 * @brief Displays the current vehicle status on the dashboard.
 * 
 * This function creates a string representation of the vehicle's current status,
 * including all sensor readings and ECU states, and outputs it to the console.
 */
void Vehicle::displayDashboard() {
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

/**
 * @brief Runs diagnostic checks on the vehicle's components.
 * 
 * This function performs a series of checks on all vehicle sensors and components,
 * logging the results and outputting warnings for any values outside of normal ranges.
 */
void Vehicle::runDiagnostics() {
    logger.Log("\n\nRunning diagnostics.");
    std::cout << "\n--- Diagnostics Report ---" << std::endl;

    auto checkAndLog = [this](const std::string& sensorName, double value, double threshold, const std::string& warningMessage) {
        std::ostringstream logMessage;
        logMessage << sensorName << " read: " << std::fixed << std::setprecision(2) << value;
        logger.Log(logMessage.str());

        if ((sensorName == "Speed" && value > threshold) || 
            (sensorName != "Speed" && value < threshold)) {
            logger.Log("Warning: " + warningMessage);
            std::cout << "Warning: " << warningMessage << std::endl;
        }
    };

    checkAndLog("Speed", speedSensor->readData(), 120, "High speed detected!");
    checkAndLog("Fuel", fuelSensor->readData(), 5, "Low fuel level!");
    checkAndLog("Temperature", tempSensor->readData(), 90, "Engine overheating!");
    checkAndLog("Battery Charge", battery->readCharge(), 20, "Low battery charge!");
    checkAndLog("Battery Temperature", battery->readTemperature(), 40, "Battery overheating!");
    checkAndLog("Radar Distance", radarSensor->readData(), 20, "Vehicle ahead too close!");

    std::cout << "--- End of Diagnostics ---\n" << std::endl;
}