#ifndef ECU_HPP
#define ECU_HPP

class EngineControlUnit {
public:
    EngineControlUnit();
    void setThrottlePosition(double position);
    double getThrottlePosition() const;

private:
    double throttlePosition;
};

class BrakeControlUnit {
public:
    BrakeControlUnit();
    void setBrakePressure(double pressure);
    double getBrakePressure() const;

private:
    double brakePressure;
};

class TransmissionControlUnit {
public:
    TransmissionControlUnit();
    void changeGear(int newGear);
    int getGear() const;

private:
    int gear;
};

#endif // ECU_HPP