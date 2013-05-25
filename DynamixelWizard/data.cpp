#include "data.h"

Data::Data() {

}

Data::~Data() {

}

// set functions
void Data::set_model_number_l(int const model_number_l) {
    model_number_l_ = model_number_l;
}

void Data::set_model_number_h(int const model_number_h) {
    model_number_h_ = model_number_h;
}

void Data::set_firmware_version(int const firmware_version) {
    firmware_version_ = firmware_version;
}

void Data::set_id(int const id) {
    id_ = id;
}

void Data::set_baud_rate(int const baud_rate) {
    baud_rate_ = baud_rate;
}

void Data::set_return_delay_time(int const return_delay_time) {
    return_delay_time_ = return_delay_time;
}

void Data::set_cw_angle_limit_l(int const cw_angle_limit_l) {
    cw_angle_limit_l_ = cw_angle_limit_l;
}

void Data::set_cw_angle_limit_h(int const cw_angle_limit_h ) {
    cw_angle_limit_h_ = cw_angle_limit_h;
}

void Data::set_ccw_angle_limit_l(int const ccw_angle_limit_l) {
    ccw_angle_limit_l_ = ccw_angle_limit_l;
}

void Data::set_ccw_angle_limit_h(int const ccw_angle_limit_h) {
    ccw_angle_limit_h_ = ccw_angle_limit_h;
}

void Data::set_highest_temp_limit(int const highest_temp_limit) {
    highest_temp_limit_ = highest_temp_limit;
}

void Data::set_lowest_voltage_limit(int const lowest_voltage_limit) {
    lowest_voltage_limit_ = lowest_voltage_limit;
}

void Data::set_highest_voltage_limit(int const highest_voltage_limit) {
    highest_voltage_limit_ = highest_voltage_limit;
}

void Data::set_max_torque_l(int const max_torque_l ) {
    max_torque_l_ = max_torque_l;
}

void Data::set_max_torque_h(int const max_torque_h) {
    max_torque_h_ = max_torque_h;
}

void Data::set_status_return_level(int const status_return_level) {
    status_return_level_ = status_return_level;
}

void Data::set_alarm_led(int const alarm_led) {
    alarm_led_ = alarm_led;
}

void Data::set_alarm_shutdown(int const alarm_shutdown) {
    alarm_shutdown_ = alarm_shutdown;
}

void Data::set_torque_enable(int const torque_enable) {
    torque_enable_ = torque_enable;
}

void Data::set_led(int const led) {
    led_ = led;
}

void Data::set_d_gain(const int d_gain)
{
    d_gain_ = d_gain;
}

void Data::set_i_gain(const int i_gain)
{
    i_gain_ = i_gain;
}

void Data::set_p_gain(const int p_gain)
{
    p_gain_ = p_gain;
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

void Data::set_goal_position_l(int const goal_position_l) {
    goal_position_l_ = goal_position_l;
}

void Data::set_goal_position_h(int const goal_position_h) {
    goal_position_h_ = goal_position_h;
}

void Data::set_moving_speed_l(int const moving_speed_l) {
    moving_speed_l_ = moving_speed_l;
}

void Data::set_moving_speed_h(int const moving_speed_h) {
    moving_speed_h_ = moving_speed_h;
}

void Data::set_torque_limit_l(int const torque_limit_l) {
    torque_limit_l_ = torque_limit_l;
}

void Data::set_torque_limit_h(int const torque_limit_h) {
    torque_limit_h_ = torque_limit_h;
}

void Data::set_present_load_l(int const present_load_l) {
    present_load_l_ = present_load_l;
}

void Data::set_present_load_h(int const present_load_h) {
    present_load_h_ = present_load_h;
}

void Data::set_present_position_l(int const present_position_l) {
    present_position_l_ = present_position_l;
}

void Data::set_present_position_h(int const present_position_h) {
    present_position_h_ = present_position_h;
}

void Data::set_present_speed_l(int const present_speed_l) {
    present_speed_l_ = present_speed_l;
}

void Data::set_present_speed_h(int const present_speed_h) {
    present_speed_h_ = present_speed_h;
}

void Data::set_present_voltage(int const present_voltage) {
    present_voltage_ = present_voltage;
}

void Data::set_present_temp(int const present_temp) {
    present_temp_ = present_temp;
}

void Data::set_registered(int const registered) {
    registered_ = registered;
}

void Data::set_moving(int const moving) {
    moving_ = moving;
}

void Data::set_lock(int const lock) {
    lock_ = lock;
}

void Data::set_punch_l(int const punch_l) {
    punch_l_ = punch_l;
}

void Data::set_punch_h(int const punch_h) {
    punch_h_ = punch_h;
}

void Data::set_goal_acceleration(const int goal_acceleration)
{
    goal_acceleration_ = goal_acceleration;
}

void Data::set_connection(bool const connection ) {
    connection_ = connection;
}


// Get functions
int Data::model_number_l() const {
    return model_number_l_;
}

int Data::model_number_h() const {
    return model_number_h_;
}

int Data::firmware_version() const {
    return firmware_version_;
}

int Data::id() const {
    return id_;
}

int Data::baud_rate() const {
    return baud_rate_;
}

int Data::return_delay_time() const {
    return return_delay_time_;
}

int Data::cw_angle_limit_l() const {
    return cw_angle_limit_l_;
}

int Data::cw_angle_limit_h() const {
    return cw_angle_limit_h_;
}

int Data::ccw_angle_limit_l() const {
    return ccw_angle_limit_l_;
}

int Data::ccw_angle_limit_h() const {
    return ccw_angle_limit_h_;
}

int Data::highest_temp_limit() const {
    return highest_temp_limit_;
}

int Data::lowest_voltage_limit() const {
    return lowest_voltage_limit_;
}

int Data::highest_voltage_limit() const {
    return highest_voltage_limit_;
}

int Data::max_torque_l() const {
    return max_torque_l_;
}

int Data::max_torque_h() const {
    return max_torque_h_;
}

int Data::status_return_level() const {
    return status_return_level_;
}

int Data::alarm_led() const {
    return alarm_led_;
}

int Data::alarm_shutdown() const {
    return alarm_shutdown_;
}

int Data::torque_enable() const {
    return torque_enable_;
}

int Data::led() const {
    return led_;
}

int Data::d_gain() const
{
    return d_gain_;
}

int Data::i_gain() const
{
    return i_gain_;
}

int Data::p_gain() const
{
    return p_gain_;
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

int Data::goal_position_l() const {
    return goal_position_l_;
}

int Data::goal_position_h() const {
    return goal_position_h_;
}

int Data::moving_speed_l() const {
    return moving_speed_l_;
}

int Data::moving_speed_h() const {
    return moving_speed_h_;
}

int Data::torque_limit_l() const {
    return torque_limit_l_;
}

int Data::torque_limit_h() const {
    return torque_limit_h_;
}

int Data::present_load_l() const {
    return present_load_l_;
}

int Data::present_load_h() const {
    return present_load_h_;
}

int Data::present_position_l() const {
    return present_position_l_;
}

int Data::present_position_h() const {
    return present_position_h_;
}

int Data::present_speed_l() const {
    return present_speed_l_;
}

int Data::present_speed_h() const {
    return present_speed_h_;
}

int Data::present_voltage() const {
    return present_voltage_;
}

int Data::present_temp() const {
    return present_temp_;
}

int Data::registered() const {
    return registered_;
}

int Data::moving() const {
    return moving_;
}

int Data::lock() const {
    return lock_;
}

int Data::punch_l() const {
    return punch_l_;
}

int Data::punch_h() const {
    return punch_h_;
}

int Data::goal_acceleration() const
{
    return goal_acceleration_;
}

bool Data::connection() const {
    return connection_;
}
