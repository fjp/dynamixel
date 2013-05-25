#ifndef SERVO_HPP
#define SERVO_HPP

#include "data.h"

class Servo
{
public:
    Servo(int const id);
    Servo();
    ~Servo();

    void write_data(Data const& data) const;//, double load) const;
    Data receive_data() const;

private:
    // Returns the desired load that is applied to force the sensor the get back to the goal position
    int control_torque(int torque_limit, int goal_pos) const;


    int id_;

};

#endif // SERVO_HPP
