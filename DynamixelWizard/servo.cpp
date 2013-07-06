#include "servo.h"

#include <QDebug>
#include <math.h>

Servo::Servo(const int& iID, const int& iBaudRate)
{
    m_oData.set_model_number(0);
    m_oData.set_firmware_version(0);
    m_oData.set_id(iID);
    m_oData.set_baud_rate(iBaudRate);
    m_oData.set_return_delay_time(0);
    m_oData.set_cw_angle_limit(0);
    m_oData.set_ccw_angle_limit(0);
    m_oData.set_highest_temp_limit(0);
    m_oData.set_lowest_voltage_limit(0);
    m_oData.set_highest_voltage_limit(0);
    m_oData.set_max_torque(0);
    m_oData.set_status_return_level(0);
    m_oData.set_alarm_led(0);
    m_oData.set_alarm_shutdown(0);

    m_oData.set_torque_enable(0);
    m_oData.set_led(0);
    m_oData.set_d_gain(0);
    m_oData.set_i_gain(0);
    m_oData.set_p_gain(0);
    m_oData.set_goal_position(0);
    m_oData.set_moving_speed(0);
    m_oData.set_torque_limit(0);
    m_oData.set_torque_limit(0);
    m_oData.set_present_position(0);
    m_oData.set_present_speed(0);
    m_oData.set_present_load(0);

    m_oData.set_present_voltage(0);
    m_oData.set_present_temp(0);

    m_oData.set_registered(0);
    m_oData.set_moving(0);
    m_oData.set_lock(0);
    m_oData.set_punch(0);
    m_oData.set_goal_acceleration(0);

}

Servo::~Servo()
{

}

void Servo::write_data(Data const& data) const {  // , double load) const{

    //static int goal_pos = data.goal_position_l();
    int iID = m_oData.id();

    dxl_write_word(iID, 6, data.cw_angle_limit());
    //dxl_write_word(iID, 7, data.cw_angle_limit_h());
    dxl_write_word(iID, 8, data.ccw_angle_limit());
    //dxl_write_word(iID, 9, data.ccw_angle_limit_h());

    dxl_write_word(iID, 12, data.lowest_voltage_limit());
    dxl_write_word(iID, 13, data.highest_voltage_limit());
    dxl_write_word(iID, 14, data.max_torque());
    //dxl_write_word(iID, 15, data.max_torque_h());


    dxl_write_word(iID, 24, data.torque_enable());

    /* DYNAMIXEL AX
    dxl_write_word(iID, 26, data.cw_compliance_margin());
    dxl_write_word(iID, 27, data.ccw_compliance_margin());
    dxl_write_word(iID, 28, data.cw_compliance_slope());
    dxl_write_word(iID, 29, data.ccw_compliance_slope());
    */
    dxl_write_byte(iID, 26, data.d_gain());
    dxl_write_byte(iID, 27, data.i_gain());
    dxl_write_byte(iID, 28, data.p_gain());

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

    dxl_write_word(iID, 30, data.goal_position());
    //dxl_write_word(iID, 31, data.goal_position_h());

    dxl_write_word(iID, 32, data.moving_speed());
    //dxl_write_word(iID, 33, data.moving_speed_h());

    dxl_write_word(iID, 34, data.torque_limit());
    //dxl_write_word(iID, 35, data.torque_limit_h());

    //dxl_write_word(iID, 47, data.lock());

    dxl_write_word(iID, 48, data.punch());
    //dxl_write_word(iID, 49, data.punch_h());


    dxl_write_word(iID, 34, control_torque(data.torque_limit(), data.goal_position()));
    //dxl_write_word(iID, 34, 1023);

    // TODO: goal acceleration, add also in gui


}

Data& Servo::receive_data()
{
    int iID = m_oData.id();

    /***** EEPROM *****/
    m_oData.set_model_number(dxl_read_word(iID, 0));
    m_oData.set_firmware_version(dxl_read_byte(iID, 2));

    m_oData.set_id(dxl_read_byte(iID, 3));
    m_oData.set_baud_rate(dxl_read_byte(iID, 4));
    m_oData.set_return_delay_time(dxl_read_byte(iID, 5));

    m_oData.set_cw_angle_limit(dxl_read_word(iID, 6));
    m_oData.set_ccw_angle_limit(dxl_read_word(iID, 8));

    m_oData.set_highest_temp_limit(dxl_read_byte(iID, 11));
    m_oData.set_lowest_voltage_limit(dxl_read_byte(iID, 12));
    m_oData.set_highest_voltage_limit(dxl_read_byte(iID, 13));

    m_oData.set_max_torque(dxl_read_word(iID, 14));
    m_oData.set_status_return_level(dxl_read_byte(iID, 16));
    m_oData.set_alarm_led(dxl_read_byte(iID, 17));
    m_oData.set_alarm_shutdown(dxl_read_byte(iID, 18));

    /***** RAM *****/
    m_oData.set_torque_enable(dxl_read_byte(iID, 24));
    m_oData.set_led(dxl_read_byte(iID, 25));

    m_oData.set_d_gain(dxl_read_byte(iID, 26));
    m_oData.set_i_gain(dxl_read_byte(iID, 27));
    m_oData.set_p_gain(dxl_read_byte(iID, 28));

    m_oData.set_goal_position(dxl_read_word(iID, 30));
    m_oData.set_moving_speed(dxl_read_word(iID, 32));
    m_oData.set_torque_limit(dxl_read_word(iID, 34));

    m_oData.set_present_position(dxl_read_word(iID, 36));

    m_oData.set_present_speed(dxl_read_word(iID, 38));

    m_oData.set_present_load(dxl_read_word(iID, 40));

    m_oData.set_present_voltage(dxl_read_byte(iID, 42));

    m_oData.set_present_temp(dxl_read_byte(iID, 43));

    m_oData.set_registered(dxl_read_byte(iID, 44));

    m_oData.set_moving(dxl_read_byte(iID, 46));

    m_oData.set_lock(dxl_read_byte(iID, 47));

    m_oData.set_punch(dxl_read_word(iID, 48));

    m_oData.set_goal_acceleration(dxl_read_byte(iID, 73));

    return m_oData; // TODO return really needed?
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
    
    int cur_pos = dxl_read_word(m_oData.id(), 36);
    
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
