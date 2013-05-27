#include "servo.hpp"

#include "dynamixel.h"

#include <QDebug>
#include <math.h>

Servo::Servo(int const id) {
    id_ = id;
}

Servo::Servo()
{

}

Servo::~Servo() {

}

void Servo::write_data(Data const& data) const {  // , double load) const{

    //static int goal_pos = data.goal_position_l();
    int id_ = data.id();

    dxl_write_word(id_, 6, data.cw_angle_limit_l());
    //dxl_write_word(id_, 7, data.cw_angle_limit_h());
    dxl_write_word(id_, 8, data.ccw_angle_limit_l());
    //dxl_write_word(id_, 9, data.ccw_angle_limit_h());

    dxl_write_word(id_, 12, data.lowest_voltage_limit());
    dxl_write_word(id_, 13, data.highest_voltage_limit());
    dxl_write_word(id_, 14, data.max_torque_l());
    //dxl_write_word(id_, 15, data.max_torque_h());


    dxl_write_word(id_, 24, data.torque_enable());

    /* DYNAMIXEL AX
    dxl_write_word(id_, 26, data.cw_compliance_margin());
    dxl_write_word(id_, 27, data.ccw_compliance_margin());
    dxl_write_word(id_, 28, data.cw_compliance_slope());
    dxl_write_word(id_, 29, data.ccw_compliance_slope());
    */
    dxl_write_word(id_, 26, data.d_gain());
    dxl_write_word(id_, 27, data.i_gain());
    dxl_write_word(id_, 28, data.p_gain());

/*
    //PD-Control for goal position
//    static double force_old = 0.0;
//    double K_p = -0.04;
//    double K_d = 0.0;
//
//    if (load > 1023) {
//        load -= 1023;
//        K_p *= -1.0;
//    }
//
//    if (load > 200) {
//
//        double force = load;
//        double dfdt = force - force_old;
//
//        //qDebug() << "[DEBUG] Force: " << force;
//        //qDebug() << "[DEBUG] df/dt: " << dfdt;
//
//        double df = 0.0 - force;
//
//        //qDebug() << "[DEBUG] df" << df;
//
//        double R = K_p*df + K_d*dfdt;
//
//        //qDebug() << "[DEBUG] Postiton to add: " << R;
//
//
//        force_old = force;
//
//        goal_pos += (int)(R);
//
//        if (goal_pos > 1023)
//            goal_pos = 1023;
//
//        if (goal_pos < 0)
//            goal_pos = 0;
//
//        qDebug() << goal_pos;
//    }

*/

    dxl_write_word(id_, 30, data.goal_position_l());
    //dxl_write_word(id_, 31, data.goal_position_h());

    dxl_write_word(id_, 32, data.moving_speed_l());
    //dxl_write_word(id_, 33, data.moving_speed_h());

    //dxl_write_word(id_, 34, data.torque_limit_l());
    //dxl_write_word(id_, 35, data.torque_limit_h());

    //dxl_write_word(id_, 47, data.lock());

    dxl_write_word(id_, 48, data.punch_l());
    //dxl_write_word(id_, 49, data.punch_h());


    dxl_write_word(id_, 34, control_torque(data.torque_limit_l(), data.goal_position_l()));
    //dxl_write_word(id_, 34, 1023);

    // TODO: goal acceleration, add also in gui


}

Data Servo::receive_data() const {

    Data data;

    data.set_present_position_l(dxl_read_word(id_, 36));
    data.set_present_position_h(dxl_read_word(id_, 37));

    data.set_present_speed_l(dxl_read_word(id_, 38));
    data.set_present_speed_h(dxl_read_word(id_, 39));

    data.set_present_load_l(dxl_read_word(id_, 40));

    data.set_present_load_h(dxl_read_word(id_, 41));

    data.set_present_voltage(dxl_read_word(id_, 42));

    data.set_present_temp(dxl_read_word(id_, 43));

    data.set_registered(dxl_read_word(id_, 44));

    data.set_moving(dxl_read_word(id_, 46));

    return data;
}


int Servo::control_torque(int torque_limit, int goal_pos) const{
    // Model Torque Curve

    // torque
    //    |    \   |   /
    //    |     \  |  /
    //    |      \ | /
    //    |_______\|/____________pos
    //          cur_pos

    // Calculate slope based on the torque limit and the goal position
    double t = (double)torque_limit;
    double x = (double)goal_pos;
    double m = t/x;
    double des_load = 0.0;
    
    int cur_pos = dxl_read_word(id_, 36);
    
    // Magnitude of the position
    double pos = sqrt(pow(cur_pos - goal_pos, 2));

    // Proportional constant for compliance modelling
    double K_p = 2.0;

    // Calucalte the desired force
    des_load = K_p*m*pos;


    // Min. Torque to apply, otherwise the servo can not overcome the internal friction
    if (des_load < 80)
        des_load = 80;


    return (int)(des_load);
}
