#include "servo.h"

#include "dynamixel.h"

#include <QDebug>
#include <math.h>

Servo::Servo(int const id) {
    m_id = id;
}

Servo::Servo()
{

}

Servo::~Servo() {

}

void Servo::write_data(Data const& data) const {  // , double load) const{

    //static int goal_pos = data.goal_position_l();
    int m_id = data.id();

    dxl_write_word(m_id, 6, data.cw_angle_limit_l());
    //dxl_write_word(m_id, 7, data.cw_angle_limit_h());
    dxl_write_word(m_id, 8, data.ccw_angle_limit_l());
    //dxl_write_word(m_id, 9, data.ccw_angle_limit_h());

    dxl_write_word(m_id, 12, data.lowest_voltage_limit());
    dxl_write_word(m_id, 13, data.highest_voltage_limit());
    dxl_write_word(m_id, 14, data.max_torque_l());
    //dxl_write_word(m_id, 15, data.max_torque_h());


    dxl_write_word(m_id, 24, data.torque_enable());

    /* DYNAMIXEL AX
    dxl_write_word(m_id, 26, data.cw_compliance_margin());
    dxl_write_word(m_id, 27, data.ccw_compliance_margin());
    dxl_write_word(m_id, 28, data.cw_compliance_slope());
    dxl_write_word(m_id, 29, data.ccw_compliance_slope());
    */
    dxl_write_word(m_id, 26, data.d_gain());
    dxl_write_word(m_id, 27, data.i_gain());
    dxl_write_word(m_id, 28, data.p_gain());

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

    dxl_write_word(m_id, 30, data.goal_position_l());
    //dxl_write_word(m_id, 31, data.goal_position_h());

    dxl_write_word(m_id, 32, data.moving_speed_l());
    //dxl_write_word(m_id, 33, data.moving_speed_h());

    dxl_write_word(m_id, 34, data.torque_limit_l());
    //dxl_write_word(m_id, 35, data.torque_limit_h());

    //dxl_write_word(m_id, 47, data.lock());

    dxl_write_word(m_id, 48, data.punch_l());
    //dxl_write_word(m_id, 49, data.punch_h());


    dxl_write_word(m_id, 34, control_torque(data.torque_limit_l(), data.goal_position_l()));
    //dxl_write_word(m_id, 34, 1023);

    // TODO: goal acceleration, add also in gui


}

Data& Servo::receive_data() const {

    Data data;

    /***** EEPROM *****/
    data.set_model_number_l(dxl_read_word(m_id, 0));
    data.set_firmware_version(dxl_read_byte(m_id, 2));

    data.set_id(dxl_read_byte(m_id, 3));
    data.set_baud_rate(dxl_read_byte(m_id, 4));
    data.set_return_delay_time(dxl_read_byte(m_id, 5));

    data.set_cw_angle_limit_l(dxl_read_word(m_id, 6));
    data.set_ccw_angle_limit_l(dxl_read_word(m_id, 8));

    data.set_highest_temp_limit(dxl_read_byte(m_id, 11));
    data.set_lowest_voltage_limit(dxl_read_byte(m_id, 12));
    data.set_highest_voltage_limit(dxl_read_byte(m_id, 13));

    data.set_max_torque_l(dxl_read_word(m_id, 14));
    data.set_status_return_level(dxl_read_byte(m_id, 16));
    data.set_alarm_led(dxl_read_byte(m_id, 17));
    data.set_alarm_shutdown(dxl_read_byte(m_id, 18));

    /***** RAM *****/
    data.set_torque_enable(dxl_read_byte(m_id, 24));
    data.set_led(dxl_read_byte(m_id, 25));

    data.set_d_gain(dxl_read_byte(m_id, 26));
    data.set_i_gain(dxl_read_byte(m_id, 27));
    data.set_p_gain(dxl_read_byte(m_id, 28));

    data.set_goal_position_l(dxl_read_word(m_id, 30));
    data.set_moving_speed_l(dxl_read_word(m_id, 32));
    data.set_torque_limit_l(dxl_read_word(m_id, 34));

    data.set_present_position_l(dxl_read_word(m_id, 36));
    //data.set_present_position_h(dxl_read_word(m_id, 37));

    data.set_present_speed_l(dxl_read_word(m_id, 38));
    //data.set_present_speed_h(dxl_read_word(m_id, 39));

    data.set_present_load_l(dxl_read_word(m_id, 40));
    //data.set_present_load_h(dxl_read_word(m_id, 41));

    data.set_present_voltage(dxl_read_byte(m_id, 42));

    data.set_present_temp(dxl_read_byte(m_id, 43));

    data.set_registered(dxl_read_byte(m_id, 44));

    data.set_moving(dxl_read_byte(m_id, 46));

    data.set_lock(dxl_read_byte(m_id, 47));

    data.set_punch_l(dxl_read_word(m_id, 48));

    data.set_goal_acceleration(dxl_read_byte(m_id, 73));

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
    
    int cur_pos = dxl_read_word(m_id, 36);
    
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
