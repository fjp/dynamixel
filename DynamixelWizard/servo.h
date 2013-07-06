#ifndef SERVO_HPP
#define SERVO_HPP

#include "dynamixel.h"

#include "data.h"

class Servo
{
public:
    Servo();
    ~Servo();

    void write_data(Data const& data) const;//, double load) const;
    Data& receive_data() const;

private:
    Data m_oData;

    // Returns the desired load that is applied to force the sensor the get back to the goal position
    int control_torque(int torque_limit, int goal_pos) const;

};

#endif // SERVO_HPP
