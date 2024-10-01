#include "../headers/ecu.hpp"

/**
 * @brief Constructor for the EngineControlUnit class
 * @details Initializes throttle position to 0.0.
 */
EngineControlUnit::EngineControlUnit() : throttlePosition(0.0) {}

/**
 * @brief Sets the throttle position.
 * @param position The new throttle position (clamped between 0.0 and 100.0).
 */
void EngineControlUnit::setThrottlePosition(double position) {
    throttlePosition = clamp(position, 0.0, 100.0);
}

/**
 * @brief Gets the current throttle position.
 * @return The current throttle position.
 */
double EngineControlUnit::getThrottlePosition() const {
    return throttlePosition;
}

/**
 * @brief Constructor for the BrakeControlUnit class
 * @details Initializes brake pressure to 0.0.
 */
BrakeControlUnit::BrakeControlUnit() : brakePressure(0.0) {}

/**
 * @brief Sets the brake pressure.
 * @param pressure The new brake pressure (clamped between 0.0 and 100.0).
 */
void BrakeControlUnit::setBrakePressure(double pressure) {
    brakePressure = clamp(pressure, 0.0, 100.0);
}

/**
 * @brief Gets the current brake pressure.
 * @return The current brake pressure.
 */
double BrakeControlUnit::getBrakePressure() const {
    return brakePressure;
}

/**
 * @brief Constructor for the TransmissionControlUnit class
 * @details Initializes gear to 1.
 */
TransmissionControlUnit::TransmissionControlUnit() : gear(1) {}

/**
 * @brief Changes the current gear.
 * @param newGear The new gear (clamped between 1 and 6).
 */
void TransmissionControlUnit::changeGear(int newGear) {
    gear = clamp(newGear, 1, 6);
}

/**
 * @brief Gets the current gear.
 * @return The current gear.
 */
int TransmissionControlUnit::getGear() const {
    return gear;
}