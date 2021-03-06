#include "data.h"

Data::Data() {

}

Data::~Data() {

}

// set functions
void Data::set_model_number_l(int const model_number_l)
{
    m_model_number_l = model_number_l;
}

void Data::set_model_number_h(int const model_number_h)
{
    m_model_number_h = model_number_h;
}

void Data::set_firmware_version(int const firmware_version)
{
    m_firmware_version = firmware_version;
}

void Data::set_id(int const id)
{
    m_id = id;
}

void Data::set_baud_rate(int const baud_rate)
{
    m_baud_rate = baud_rate;
}

void Data::set_return_delay_time(int const return_delay_time)
{
    m_return_delay_time = return_delay_time;
}

void Data::set_cw_angle_limit_l(int const cw_angle_limit_l)
{
    m_cw_angle_limit_l = cw_angle_limit_l;
}

void Data::set_cw_angle_limit_h(int const cw_angle_limit_h )
{
    m_cw_angle_limit_h = cw_angle_limit_h;
}

void Data::set_ccw_angle_limit_l(int const ccw_angle_limit_l)
{
    m_ccw_angle_limit_l = ccw_angle_limit_l;
}

void Data::set_ccw_angle_limit_h(int const ccw_angle_limit_h)
{
    m_ccw_angle_limit_h = ccw_angle_limit_h;
}

void Data::set_highest_temp_limit(int const highest_temp_limit)
{
    m_highest_temp_limit = highest_temp_limit;
}

void Data::set_lowest_voltage_limit(int const lowest_voltage_limit)
{
    m_lowest_voltage_limit = lowest_voltage_limit;
}

void Data::set_highest_voltage_limit(int const highest_voltage_limit)
{
    m_highest_voltage_limit = highest_voltage_limit;
}

void Data::set_max_torque_l(int const max_torque_l )
{
    m_max_torque_l = max_torque_l;
}

void Data::set_max_torque_h(int const max_torque_h)
{
    m_max_torque_h = max_torque_h;
}

void Data::set_status_return_level(int const status_return_level)
{
    m_status_return_level = status_return_level;
}

void Data::set_alarm_led(int const alarm_led)
{
    m_alarm_led = alarm_led;
}

void Data::set_alarm_shutdown(int const alarm_shutdown)
{
    m_alarm_shutdown = alarm_shutdown;
}

void Data::set_torque_enable(int const torque_enable)
{
    m_torque_enable = torque_enable;
}

void Data::set_led(int const led)
{
    m_led = led;
}

void Data::set_d_gain(const int d_gain)
{
    m_d_gain = d_gain;
}

void Data::set_i_gain(const int i_gain)
{
    m_i_gain = i_gain;
}

void Data::set_p_gain(const int p_gain)
{
    m_p_gain = p_gain;
}

/* DYNAMIXEL AX
void Data::set_cw_compliance_margin(int const cw_compliance_margin) {
    cw_compliance_margin_ =cw_compliance_margin;
}

void Data::set_ccw_compliance_margin(int const ccw_compliance_margin) {
    ccw_compliance_margin_ = ccw_compliance_margin;
}

void Data::set_cw_compliance_slope(int const cw_compliance_slope) {
    cw_compliance_slope_ = cw_compliance_slope;
}

void Data::set_ccw_compliance_slope(int const ccw_compliance_slope) {
    ccw_compliance_slope_ = ccw_compliance_slope;
}
*/

void Data::set_goal_position_l(int const goal_position_l)
{
    m_goal_position_l = goal_position_l;
}

void Data::set_goal_position_h(int const goal_position_h)
{
    m_goal_position_h = goal_position_h;
}

void Data::set_moving_speed_l(int const moving_speed_l)
{
    m_moving_speed_l = moving_speed_l;
}

void Data::set_moving_speed_h(int const moving_speed_h)
{
    m_moving_speed_h = moving_speed_h;
}

void Data::set_torque_limit_l(int const torque_limit_l)
{
    m_torque_limit_l = torque_limit_l;
}

void Data::set_torque_limit_h(int const torque_limit_h)
{
    m_torque_limit_h = torque_limit_h;
}

void Data::set_present_load_l(int const present_load_l)
{
    m_present_load_l = present_load_l;
}

void Data::set_present_load_h(int const present_load_h)
{
    m_present_load_h = present_load_h;
}

void Data::set_present_position_l(int const present_position_l)
{
    m_present_position_l = present_position_l;
}

void Data::set_present_position_h(int const present_position_h)
{
    m_present_position_h = present_position_h;
}

void Data::set_present_speed_l(int const present_speed_l)
{
    m_present_speed_l = present_speed_l;
}

void Data::set_present_speed_h(int const present_speed_h)
{
    m_present_speed_h = present_speed_h;
}

void Data::set_present_voltage(int const present_voltage)
{
    m_present_voltage = present_voltage;
}

void Data::set_present_temp(int const present_temp)
{
    m_present_temp = present_temp;
}

void Data::set_registered(int const registered)
{
    m_registered = registered;
}

void Data::set_moving(int const moving)
{
    m_moving = moving;
}

void Data::set_lock(int const lock)
{
    m_lock = lock;
}

void Data::set_punch_l(int const punch_l)
{
    m_punch_l = punch_l;
}

void Data::set_punch_h(int const punch_h)
{
    m_punch_h = punch_h;
}

void Data::set_goal_acceleration(const int goal_acceleration)
{
    m_goal_acceleration = goal_acceleration;
}

void Data::set_connection(bool const connection )
{
    m_connection = connection;
}


// Get functions
int Data::model_number_l() const
{
    return m_model_number_l;
}

int Data::model_number_h() const
{
    return m_model_number_h;
}

int Data::firmware_version() const
{
    return m_firmware_version;
}

int Data::id() const
{
    return m_id;
}

int Data::baud_rate() const
{
    return m_baud_rate;
}

int Data::return_delay_time() const
{
    return m_return_delay_time;
}

int Data::cw_angle_limit_l() const
{
    return m_cw_angle_limit_l;
}

int Data::cw_angle_limit_h() const
{
    return m_cw_angle_limit_h;
}

int Data::ccw_angle_limit_l() const
{
    return m_ccw_angle_limit_l;
}

int Data::ccw_angle_limit_h() const
{
    return m_ccw_angle_limit_h;
}

int Data::highest_temp_limit() const
{
    return m_highest_temp_limit;
}

int Data::lowest_voltage_limit() const
{
    return m_lowest_voltage_limit;
}

int Data::highest_voltage_limit() const
{
    return m_highest_voltage_limit;
}

int Data::max_torque_l() const
{
    return m_max_torque_l;
}

int Data::max_torque_h() const
{
    return m_max_torque_h;
}

int Data::status_return_level() const
{
    return m_status_return_level;
}

int Data::alarm_led() const
{
    return m_alarm_led;
}

int Data::alarm_shutdown() const
{
    return m_alarm_shutdown;
}

int Data::torque_enable() const
{
    return m_torque_enable;
}

int Data::led() const
{
    return m_led;
}

int Data::d_gain() const
{
    return m_d_gain;
}

int Data::i_gain() const
{
    return m_i_gain;
}

int Data::p_gain() const
{
    return m_p_gain;
}

/* DYNAMIXEL AX
int Data::cw_compliance_margin() const {
    return cw_compliance_margin_;
}

int Data::ccw_compliance_margin() const {
    return ccw_compliance_margin_;
}

int Data::cw_compliance_slope() const {
    return cw_compliance_slope_;
}

int Data::ccw_compliance_slope() const {
    return ccw_compliance_slope_;
}
*/

int Data::goal_position_l() const
{
    return m_goal_position_l;
}

int Data::goal_position_h() const
{
    return m_goal_position_h;
}

int Data::moving_speed_l() const
{
    return m_moving_speed_l;
}

int Data::moving_speed_h() const
{
    return m_moving_speed_h;
}

int Data::torque_limit_l() const
{
    return m_torque_limit_l;
}

int Data::torque_limit_h() const
{
    return m_torque_limit_h;
}

int Data::present_load_l() const
{
    return m_present_load_l;
}

int Data::present_load_h() const
{
    return m_present_load_h;
}

int Data::present_position_l() const
{
    return m_present_position_l;
}

int Data::present_position_h() const
{
    return m_present_position_h;
}

int Data::present_speed_l() const
{
    return m_present_speed_l;
}

int Data::present_speed_h() const
{
    return m_present_speed_h;
}

int Data::present_voltage() const
{
    return m_present_voltage;
}

int Data::present_temp() const
{
    return m_present_temp;
}

int Data::registered() const
{
    return m_registered;
}

int Data::moving() const
{
    return m_moving;
}

int Data::lock() const
{
    return m_lock;
}

int Data::punch_l() const
{
    return m_punch_l;
}

int Data::punch_h() const
{
    return m_punch_h;
}

int Data::goal_acceleration() const
{
    return m_goal_acceleration;
}

bool Data::connection() const
{
    return m_connection;
}
