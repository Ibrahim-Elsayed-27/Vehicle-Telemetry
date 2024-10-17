#include <iostream>
#include <thread>
#include <chrono>
#include "../headers/vehicle.hpp"

/// Main entry point for the vehicle simulation.
int main() {
    // Get the singleton instance of the Vehicle class
    Vehicle myCar = Vehicle("C:\\Users\\himah\\Desktop\\log.txt");

    // Main loop for continuous simulation
    while (true) {
        // Update sensor readings
        myCar.updateSensors();

        // Perform adaptive cruise control adjustments
        myCar.adaptiveCruiseControl();

        // Display the current vehicle status on the dashboard
        myCar.displayDashboard();

        // Run diagnostic checks
        myCar.runDiagnostics();

        // Wait for 2 seconds before the next update
        std::this_thread::sleep_for(std::chrono::seconds(2));
    }

    return 0;
}