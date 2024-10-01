#include "../headers/ecu.hpp"

/// Constructor for the EngineControlUnit class
/// Initializes throttle position to 0.0.
EngineControlUnit::EngineControlUnit() : throttlePosition(0.0) {}

/// Sets the throttle position.
/// @param position The new throttle position.
void EngineControlUnit::setThrottlePosition(double position) {
    throttlePosition = position;
}

/// Gets the current throttle position.
/// @return The current throttle position.
double EngineControlUnit::getThrottlePosition() const {
    return throttlePosition;
}

/// Constructor for the BrakeControlUnit class
/// Initializes brake pressure to 0.0.
BrakeControlUnit::BrakeControlUnit() : brakePressure(0.0) {}

/// Sets the brake pressure.
/// @param pressure The new brake pressure.
void BrakeControlUnit::setBrakePressure(double pressure) {
    brakePressure = pressure;
}

/// Gets the current brake pressure.
/// @return The current brake pressure.
double BrakeControlUnit::getBrakePressure() const {
    return brakePressure;
}

/// Constructor for the TransmissionControlUnit class
/// Initializes gear to 1.
TransmissionControlUnit::TransmissionControlUnit() : gear(1) {}

/// Changes the current gear.
/// @param newGear The new gear.
void TransmissionControlUnit::changeGear(int newGear) {
    gear = newGear;
}

/// Gets the current gear.
/// @return The current gear.
int TransmissionControlUnit::getGear() const {
    return gear;
}