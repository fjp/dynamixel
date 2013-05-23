#ifndef DATA_HPP
#define DATA_HPP

class Data
{
public:
    Data();
    ~Data();

    // set functions
    /**** EEPROM ****/
    void set_model_number_l(int const model_number_l);
    void set_model_number_h(int const model_number_h);

    void set_firmware_version(int const firmware_version);
    void set_id(int const id);
    void set_baud_rate(int const baud_rate);
    void set_return_delay_time(int const return_delay_time);

    void set_cw_angle_limit_l(int const cw_angle_limit_l);
    void set_cw_angle_limit_h(int const cw_angle_limit_h );
    void set_ccw_angle_limit_l(int const ccw_angle_limit_l);
    void set_ccw_angle_limit_h(int const ccw_angle_limit_h);

    void set_highest_temp_limit(int const highest_temp_limit);
    void set_lowest_voltage_limit(int const lowest_voltage_limit);
    void set_highest_voltage_limit(int const highest_voltage_limit);

    void set_max_torque_l(int const max_torque_l );
    void set_max_torque_h(int const max_torque_h);

    void set_status_return_level(int const status_return_level);
    void set_alarm_led(int const alarm_led);
    void set_alarm_shutdown(int const alarm_shutdown);

    /**** RAM ****/
    void set_torque_enable(int const torque_enable);
    void set_led(int const led);

    /* DYNAMIXEL AX
    void set_cw_compliance_margin(int const cw_compliance_margin);
    void set_ccw_compliance_margin(int const ccw_compliance_margin);
    void set_cw_compliance_slope(int const cw_compliance_slope);
    void set_ccw_compliance_slope(int const ccw_compliance_slope);
    */

    void set_d_gain(int const d_gain);
    void set_i_gain(int const i_gain);
    void set_p_gain(int const p_gain);

    void set_goal_position_l(int const goal_position_l);
    void set_goal_position_h(int const goal_position_h);
    void set_moving_speed_l(int const moving_speed_l);
    void set_moving_speed_h(int const moving_speed_h);
    void set_torque_limit_l(int const torque_limit_l);
    void set_torque_limit_h(int const torque_limit_h);
    void set_present_load_l(int const present_load_l);
    void set_present_load_h(int const present_load_h);
    void set_present_position_l(int const present_position_l);
    void set_present_position_h(int const present_position_h);
    void set_present_speed_l(int const present_speed_l);
    void set_present_speed_h(int const present_speed_h);

    void set_present_voltage(int const present_voltage);
    void set_present_temp(int const present_temp);

    void set_registered(int const registered);
    void set_moving(int const moving);
    void set_lock(int const lock);

    void set_punch_l(int const punch_l);
    void set_punch_h(int const punch_h);

    void set_goal_acceleration(int const goal_acceleration);

    void set_save_number(int const save_number);
    void set_connection(bool const connection );
    void set_force(double const force);


    // Get functions
    /**** EEPROM ****/
    int model_number_l() const;
    int model_number_h() const;

    int firmware_version() const;
    int id() const;
    int baud_rate() const;
    int return_delay_time() const;

    int cw_angle_limit_l() const;
    int cw_angle_limit_h() const;
    int ccw_angle_limit_l() const;
    int ccw_angle_limit_h() const;

    int highest_temp_limit() const;
    int lowest_voltage_limit() const;
    int highest_voltage_limit() const;

    int max_torque_l() const;
    int max_torque_h() const;

    int status_return_level() const;
    int alarm_led() const;
    int alarm_shutdown() const;

    /**** RAM ****/
    int torque_enable() const;
    int led() const;

    /* DYNAMIXEL AX
    int cw_compliance_margin() const;
    int ccw_compliance_margin() const;
    int cw_compliance_slope() const;
    int ccw_compliance_slope() const;
    */

    int d_gain() const;
    int i_gain() const;
    int p_gain() const;

    int goal_position_l() const;
    int goal_position_h() const;
    int moving_speed_l() const;
    int moving_speed_h() const;
    int torque_limit_l() const;
    int torque_limit_h() const;
    int present_load_l() const;
    int present_load_h() const;
    int present_position_l() const;
    int present_position_h() const;
    int present_speed_l() const;
    int present_speed_h() const;

    int present_voltage() const;
    int present_temp() const;

    int registered() const;
    int moving() const;
    int lock() const;

    int punch_l() const;
    int punch_h() const;

    int goal_acceleration() const;

    int save_number() const;
    bool connection() const;
    double force() const;


private:

    /**** EEPROM ****/
    int model_number_l_;
    int model_number_h_;

    int firmware_version_;
    int id_;
    int baud_rate_;
    int return_delay_time_;

    int cw_angle_limit_l_;
    int cw_angle_limit_h_;
    int ccw_angle_limit_l_;
    int ccw_angle_limit_h_;

    int highest_temp_limit_;
    int lowest_voltage_limit_;
    int highest_voltage_limit_;

    int max_torque_l_;
    int max_torque_h_;

    int status_return_level_;
    int alarm_led_;
    int alarm_shutdown_;

    /**** RAM ****/
    int torque_enable_;
    int led_;

    /* DYNAMIXEL AX
    int cw_compliance_margin_;
    int ccw_compliance_margin_;
    int cw_compliance_slope_;
    int ccw_compliance_slope_;
    */

    int d_gain_;
    int i_gain_;
    int p_gain_;

    int goal_position_l_;
    int goal_position_h_;
    int moving_speed_l_;
    int moving_speed_h_;
    int torque_limit_l_;
    int torque_limit_h_;
    int present_load_l_;
    int present_load_h_;
    int present_position_l_;
    int present_position_h_;
    int present_speed_l_;
    int present_speed_h_;

    int present_voltage_;
    int present_temp_;

    int registered_;
    int moving_;
    int lock_;

    int punch_l_;
    int punch_h_;

    int goal_acceleration_;

    int save_number_;
    bool connection_;
    double force_;



};

#endif // DATA_HPP
