#include "../headers/vehicle.hpp"

/// Constructor for the Vehicle class, initializing all components.
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

/// Singleton pattern implementation to get a reference to the Vehicle instance.
/// @return Reference to the Vehicle instance.
Vehicle& Vehicle::GetInstance() {
    static Vehicle instance;
    return instance;
}

/// Updates all sensors and logs the results.
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

/// Implements adaptive cruise control logic based on radar sensor readings.
void Vehicle::adaptiveCruiseControl() {
    logger.Log("\n\nRunning adaptive cruise control.");

    double distance = radarSensor->readData();
    logger.Log("Radar detected distance: " + std::to_string(distance));

    if (distance < 50) {
        logger.Log("Distance < 50, slowing down.");
        engineECU->setThrottlePosition(30);
        brakeECU->setBrakePressure(50);
    } else if (distance >= 50 && distance < 100) {
        logger.Log("Distance between 50 and 100, maintaining speed.");
        engineECU->setThrottlePosition(50);
        brakeECU->setBrakePressure(0);
    } else {
        logger.Log("Distance > 100, speeding up.");
        engineECU->setThrottlePosition(70);
        brakeECU->setBrakePressure(0);
    }
}

/// Displays the current vehicle status on the dashboard.
void Vehicle::displayDashboard() {
    logger.Log("\n\nDisplaying vehicle dashboard.");

    std::cout << "\n======= Vehicle Dashboard =======" << std::endl;
    std::cout << *speedSensor << std::endl;
    std::cout << *fuelSensor << std::endl;
    std::cout << *tempSensor << std::endl;
    std::cout << *battery << std::endl;
    std::cout << *radarSensor << std::endl;
    std::cout << "Throttle Position: " << engineECU->getThrottlePosition() << "%" << std::endl;
    std::cout << "Brake Pressure: " << brakeECU->getBrakePressure() << "%" << std::endl;
    std::cout << "Current Gear: " << transmissionECU->getGear() << std::endl;
    std::cout << "=================================\n" << std::endl;
}

/// Runs diagnostic checks on the vehicle's components.
void Vehicle::runDiagnostics() {
    logger.Log("\n\nRunning diagnostics.");
    std::cout << "\n--- Diagnostics Report ---" << std::endl;

    // Speed Check
    double speed = speedSensor->readData();
    logger.Log("Speed sensor read: " + std::to_string(speed));
    if (speed > 120) {
        logger.Log("Warning: High speed detected!");
        std::cout << "Warning: High Speed Detected!" << std::endl;
    }

    // Fuel Level Check
    double fuelLevel = fuelSensor->readData();
    logger.Log("Fuel sensor read: " + std::to_string(fuelLevel));
    if (fuelLevel < 5) {
        logger.Log("Warning: Low fuel level!");
        std::cout << "Warning: Low Fuel Level!" << std::endl;
    }

    // Engine Temperature Check
    double temp = tempSensor->readData();
    logger.Log("Temperature sensor read: " + std::to_string(temp));
    if (temp > 90) {
        logger.Log("Warning: Engine overheating!");
        std::cout << "Warning: Engine Overheating!" << std::endl;
    }

    // Battery Charge Level Check
    double batteryCharge = battery->readCharge();
    logger.Log("Battery charge level read: " + std::to_string(batteryCharge));
    if (batteryCharge < 20) {
        logger.Log("Warning: Low battery charge!");
        std::cout << "Warning: Low Battery Charge!" << std::endl;
    }

    // Battery Temperature Check
    double batteryTemp = battery->readTemperature();
    logger.Log("Battery temperature read: " + std::to_string(batteryTemp));
    if (batteryTemp > 40) {
        logger.Log("Warning: Battery overheating!");
        std::cout << "Warning: Battery Overheating!" << std::endl;
    }

    // Radar Distance Check
    double radarDistance = radarSensor->readData();
    logger.Log("Radar sensor read: " + std::to_string(radarDistance));
    if (radarDistance < 20) {
        logger.Log("Warning: Vehicle ahead too close!");
        std::cout << "Warning: Vehicle Ahead Too Close!" << std::endl;
    }

    std::cout << "--- End of Diagnostics ---\n" << std::endl;
}