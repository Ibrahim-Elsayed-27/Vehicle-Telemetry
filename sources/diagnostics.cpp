#include "../headers/diagnostics.hpp"

/**
 * @brief Constructor for the VehicleDiagnostics class.
 * 
 * This constructor initializes the diagnostic system by passing in shared pointers 
 * to various sensors and a reference to the logger.
 * 
 * @param speedSensor Shared pointer to the speed sensor.
 * @param fuelSensor Shared pointer to the fuel sensor.
 * @param tempSensor Shared pointer to the temperature sensor.
 * @param battery Shared pointer to the battery.
 * @param radarSensor Shared pointer to the radar sensor.
 * @param logger Reference to the logger for logging diagnostic messages.
 */
VehicleDiagnostics::VehicleDiagnostics(const std::shared_ptr<SpeedSensor>& speedSensor,
                    const std::shared_ptr<FuelSensor>& fuelSensor,
                    const std::shared_ptr<TemperatureSensor>& tempSensor,
                    const std::shared_ptr<Battery>& battery,
                    const std::shared_ptr<RadarSensor>& radarSensor,
                    Logger& logger)
    : speedSensor(speedSensor), fuelSensor(fuelSensor), tempSensor(tempSensor),
        battery(battery), radarSensor(radarSensor), logger(logger) {}

/**
 * @brief Runs diagnostic checks on all vehicle components.
 * 
 * This function checks the state of all sensors and logs the values along with any warnings
 * for values outside of normal ranges. The results are logged using the logger and displayed on the console.
 */
void VehicleDiagnostics::runDiagnostics() {
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
