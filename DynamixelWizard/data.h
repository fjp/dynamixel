#ifndef DATA_HPP
#define DATA_HPP

/**
 * @brief The Data class contains data regarding the current status and operation, which exists inside of Dynamixel.
 *
 * EEPROM and RAM
 *  Data in RAM area is reset to the initial value whenever the power is turned on
 *  while data in EEPROM area is kept once the value is set even if the power is turned off.

 * Address
 *  It represents the location of data. To read from or write data to Control Table, the user should assign the correct address in the Instruction Packet.
 *
 * Access
 *  Dynamixel has two kinds of data: Read-only data, which is mainly used for sensing, and Read-and-Write data, which is used for driving.
 *
 * Initial Value
 *  In case of data in the EEPROM Area, the initial values on the right side of the below Control Table are the factory default settings.
 *  In case of data in the RAM Area, the initial values on the right side of the above Control Tables are the ones when the power is turned on.
 *
 * Highest/Lowest Byte
 *  In the Control table, some data share the same name, but they are attached with (L) or (H) at the end of each name to distinguish the address.
 *  This data requires 16bit, but it is divided into 8bit each for the addresses (low) and (high).
 *  These two addresses should be written with one Instruction Packet at the same time.
 */
class Data
{
public:
    Data();
    ~Data();

    // set functions
    /***** EEPROM *****/
    /**
     * @brief set_model_number_l Lowest byte of model number
     * @Adress
     * @Access
     * @Initial Value
     * @param model_number_l
     */
    void set_model_number_l(int const model_number_l);

    /**
     * @brief set_model_number_h Highest byte of model number
     * @Adress
     * @Access
     * @Initial Value
     * @param model_number_h
     */
    void set_model_number_h(int const model_number_h);

    /**
     * @brief set_firmware_version Information on the version of firmware
     * @Adress
     * @Access
     * @Initial Value
     * @param firmware_version
     */
    void set_firmware_version(int const firmware_version);

    /**
     * @brief set_id
     * @Adress
     * @Access
     * @Initial Value
     * @param id
     */
    void set_id(int const id);

    /**
     * @brief set_baud_rate
     * @Adress
     * @Access
     * @Initial Value
     * @param baud_rate
     */
    void set_baud_rate(int const baud_rate);

    /**
     * @brief set_return_delay_time
     * @Adress
     * @Access
     * @Initial Value
     * @param return_delay_time
     */
    void set_return_delay_time(int const return_delay_time);

    /**
     * @brief set_cw_angle_limit_l
     * @Adress
     * @Access
     * @Initial Value
     * @param cw_angle_limit_l
     */
    void set_cw_angle_limit_l(int const cw_angle_limit_l);

    /**
     * @brief set_cw_angle_limit_h
     * @Adress
     * @Access
     * @Initial Value
     * @param cw_angle_limit_h
     */
    void set_cw_angle_limit_h(int const cw_angle_limit_h );

    /**
     * @brief set_ccw_angle_limit_l
     * @Adress
     * @Access
     * @Initial Value
     * @param ccw_angle_limit_l
     */
    void set_ccw_angle_limit_l(int const ccw_angle_limit_l);

    /**
     * @brief set_ccw_angle_limit_h
     * @Adress
     * @Access
     * @Initial Value
     * @param ccw_angle_limit_h
     */
    void set_ccw_angle_limit_h(int const ccw_angle_limit_h);

    /**
     * @brief set_highest_temp_limit
     * @Adress
     * @Access
     * @Initial Value
     * @param highest_temp_limit
     */
    void set_highest_temp_limit(int const highest_temp_limit);

    /**
     * @brief set_lowest_voltage_limit
     * @Adress
     * @Access
     * @Initial Value
     * @param lowest_voltage_limit
     */
    void set_lowest_voltage_limit(int const lowest_voltage_limit);

    /**
     * @brief set_highest_voltage_limit
     * @Adress
     * @Access
     * @Initial Value
     * @param highest_voltage_limit
     */
    void set_highest_voltage_limit(int const highest_voltage_limit);

    /**
     * @brief set_max_torque_l
     * @Adress
     * @Access
     * @Initial Value
     * @param max_torque_l
     */
    void set_max_torque_l(int const max_torque_l );

    /**
     * @brief set_max_torque_h
     * @Adress
     * @Access
     * @Initial Value
     * @param max_torque_h
     */
    void set_max_torque_h(int const max_torque_h);

    /**
     * @brief set_status_return_level
     * @Adress
     * @Access
     * @Initial Value
     * @param status_return_level
     */
    void set_status_return_level(int const status_return_level);

    /**
     * @brief set_alarm_led
     * @Adress
     * @Access
     * @Initial Value
     * @param alarm_led
     */
    void set_alarm_led(int const alarm_led);

    /**
     * @brief set_alarm_shutdown
     * @Adress
     * @Access
     * @Initial Value
     * @param alarm_shutdown
     */
    void set_alarm_shutdown(int const alarm_shutdown);

    /***** RAM *****/
    /**
     * @brief set_torque_enable
     * @Adress
     * @Access
     * @Initial Value
     * @param torque_enable
     */
    void set_torque_enable(int const torque_enable);

    /**
     * @brief set_led
     * @Adress
     * @Access
     * @Initial Value
     * @param led
     */
    void set_led(int const led);

    /* DYNAMIXEL AX
    void set_cw_compliance_margin(int const cw_compliance_margin);
    void set_ccw_compliance_margin(int const ccw_compliance_margin);
    void set_cw_compliance_slope(int const cw_compliance_slope);
    void set_ccw_compliance_slope(int const ccw_compliance_slope);
    */

    /**
     * @brief set_d_gain
     * @Adress
     * @Access
     * @Initial Value
     * @param d_gain
     */
    void set_d_gain(int const d_gain);

    /**
     * @brief set_i_gain
     * @Adress
     * @Access
     * @Initial Value
     * @param i_gain
     */
    void set_i_gain(int const i_gain);

    /**
     * @brief set_p_gain
     * @Adress
     * @Access
     * @Initial Value
     * @param p_gain
     */
    void set_p_gain(int const p_gain);

    /**
     * @brief set_goal_position_l
     * @Adress
     * @Access
     * @Initial Value
     * @param goal_position_l
     */
    void set_goal_position_l(int const goal_position_l);

    /**
     * @brief set_goal_position_h
     * @Adress
     * @Access
     * @Initial Value
     * @param goal_position_h
     */
    void set_goal_position_h(int const goal_position_h);

    /**
     * @brief set_moving_speed_l
     * @Adress
     * @Access
     * @Initial Value
     * @param moving_speed_l
     */
    void set_moving_speed_l(int const moving_speed_l);

    /**
     * @brief set_moving_speed_h
     * @Adress
     * @Access
     * @Initial Value
     * @param moving_speed_h
     */
    void set_moving_speed_h(int const moving_speed_h);

    /**
     * @brief set_torque_limit_l
     * @Adress
     * @Access
     * @Initial Value
     * @param torque_limit_l
     */
    void set_torque_limit_l(int const torque_limit_l);

    /**
     * @brief set_torque_limit_h
     * @Adress
     * @Access
     * @Initial Value
     * @param torque_limit_h
     */
    void set_torque_limit_h(int const torque_limit_h);

    /**
     * @brief set_present_load_l
     * @Adress
     * @Access
     * @Initial Value
     * @param present_load_l
     */
    void set_present_load_l(int const present_load_l);

    /**
     * @brief set_present_load_h
     * @Adress
     * @Access
     * @Initial Value
     * @param present_load_h
     */
    void set_present_load_h(int const present_load_h);

    /**
     * @brief set_present_position_l
     * @Adress
     * @Access
     * @Initial Value
     * @param present_position_l
     */
    void set_present_position_l(int const present_position_l);

    /**
     * @brief set_present_position_h
     * @Adress
     * @Access
     * @Initial Value
     * @param present_position_h
     */
    void set_present_position_h(int const present_position_h);

    /**
     * @brief set_present_speed_l
     * @Adress
     * @Access
     * @Initial Value
     * @param present_speed_l
     */
    void set_present_speed_l(int const present_speed_l);

    /**
     * @brief set_present_speed_h
     * @Adress
     * @Access
     * @Initial Value
     * @param present_speed_h
     */
    void set_present_speed_h(int const present_speed_h);

    /**
     * @brief set_present_voltage
     * @Adress
     * @Access
     * @Initial Value
     * @param present_voltage
     */
    void set_present_voltage(int const present_voltage);

    /**
     * @brief set_present_temp
     * @Adress
     * @Access
     * @Initial Value
     * @param present_temp
     */
    void set_present_temp(int const present_temp);

    /**
     * @brief set_registered
     * @Adress
     * @Access
     * @Initial Value
     * @param registered
     */
    void set_registered(int const registered);

    /**
     * @brief set_moving
     * @Adress
     * @Access
     * @Initial Value
     * @param moving
     */
    void set_moving(int const moving);

    /**
     * @brief set_lock
     * @Adress
     * @Access
     * @Initial Value
     * @param lock
     */
    void set_lock(int const lock);

    /**
     * @brief set_punch_l
     * @Adress
     * @Access
     * @Initial Value
     * @param punch_l
     */
    void set_punch_l(int const punch_l);

    /**
     * @brief set_punch_h
     * @Adress
     * @Access
     * @Initial Value
     * @param punch_h
     */
    void set_punch_h(int const punch_h);

    /**
     * @brief set_goal_acceleration
     * @Adress
     * @Access
     * @Initial Value
     * @param goal_acceleration
     */
    void set_goal_acceleration(int const goal_acceleration);

    /**
     * @brief set_save_number
     * @Adress
     * @Access
     * @Initial Value
     * @param save_number
     */
    void set_save_number(int const save_number);

    /**
     * @brief set_connection
     * @Adress
     * @Access
     * @Initial Value
     * @param connection
     */
    void set_connection(bool const connection );

    /**
     * @brief set_force
     * @Adress
     * @Access
     * @Initial Value
     * @param force
     */
    void set_force(double const force);


    // Get functions
    /**** EEPROM ****/
    /**
     * @brief model_number_l
     * @Adress
     * @Access
     * @Initial Value
     * @return
     */
    int model_number_l() const;

    /**
     * @brief model_number_h
     * @Adress
     * @Access
     * @Initial Value
     * @return
     */
    int model_number_h() const;

    /**
     * @brief firmware_version
     * @Adress
     * @Access
     * @Initial Value
     * @return
     */
    int firmware_version() const;

    /**
     * @brief id
     * @Adress
     * @Access
     * @Initial Value
     * @return
     */
    int id() const;

    /**
     * @brief baud_rate
     * @Adress
     * @Access
     * @Initial Value
     * @return
     */
    int baud_rate() const;

    /**
     * @brief return_delay_time
     * @Adress
     * @Access
     * @Initial Value
     * @return
     */
    int return_delay_time() const;

    /**
     * @brief cw_angle_limit_l
     * @Adress
     * @Access
     * @Initial Value
     * @return
     */
    int cw_angle_limit_l() const;

    /**
     * @brief cw_angle_limit_h
     * @Adress
     * @Access
     * @Initial Value
     * @return
     */
    int cw_angle_limit_h() const;

    /**
     * @brief ccw_angle_limit_l
     * @Adress
     * @Access
     * @Initial Value
     * @return
     */
    int ccw_angle_limit_l() const;

    /**
     * @brief ccw_angle_limit_h
     * @Adress
     * @Access
     * @Initial Value
     * @return
     */
    int ccw_angle_limit_h() const;

    /**
     * @brief highest_temp_limit
     * @Adress
     * @Access
     * @Initial Value
     * @return
     */
    int highest_temp_limit() const;

    /**
     * @brief lowest_voltage_limit
     * @Adress
     * @Access
     * @Initial Value
     * @return
     */
    int lowest_voltage_limit() const;

    /**
     * @brief highest_voltage_limit
     * @Adress
     * @Access
     * @Initial Value
     * @return
     */
    int highest_voltage_limit() const;

    /**
     * @brief max_torque_l
     * @Adress
     * @Access
     * @Initial Value
     * @return
     */
    int max_torque_l() const;

    /**
     * @brief max_torque_h
     * @Adress
     * @Access
     * @Initial Value
     * @return
     */
    int max_torque_h() const;

    /**
     * @brief status_return_level
     * @Adress
     * @Access
     * @Initial Value
     * @return
     */
    int status_return_level() const;

    /**
     * @brief alarm_led
     * @Adress
     * @Access
     * @Initial Value
     * @return
     */
    int alarm_led() const;

    /**
     * @brief alarm_shutdown
     * @Adress
     * @Access
     * @Initial Value
     * @return
     */
    int alarm_shutdown() const;

    /**** RAM ****/
    /**
     * @brief torque_enable
     * @Adress
     * @Access
     * @Initial Value
     * @return
     */
    int torque_enable() const;

    /**
     * @brief led
     * @Adress
     * @Access
     * @Initial Value
     * @return
     */
    int led() const;

    /* DYNAMIXEL AX
    int cw_compliance_margin() const;
    int ccw_compliance_margin() const;
    int cw_compliance_slope() const;
    int ccw_compliance_slope() const;
    */

    /**
     * @brief d_gain
     * @Adress
     * @Access
     * @Initial Value
     * @return
     */
    int d_gain() const;

    /**
     * @brief i_gain
     * @Adress
     * @Access
     * @Initial Value
     * @return
     */
    int i_gain() const;

    /**
     * @brief p_gain
     * @Adress
     * @Access
     * @Initial Value
     * @return
     */
    int p_gain() const;

    /**
     * @brief goal_position_l
     * @Adress
     * @Access
     * @Initial Value
     * @return
     */
    int goal_position_l() const;

    /**
     * @brief goal_position_h
     * @Adress
     * @Access
     * @Initial Value
     * @return
     */
    int goal_position_h() const;

    /**
     * @brief moving_speed_l
     * @Adress
     * @Access
     * @Initial Value
     * @return
     */
    int moving_speed_l() const;

    /**
     * @brief moving_speed_h
     * @Adress
     * @Access
     * @Initial Value
     * @return
     */
    int moving_speed_h() const;

    /**
     * @brief torque_limit_l
     * @Adress
     * @Access
     * @Initial Value
     * @return
     */
    int torque_limit_l() const;

    /**
     * @brief torque_limit_h
     * @Adress
     * @Access
     * @Initial Value
     * @return
     */
    int torque_limit_h() const;

    /**
     * @brief present_load_l
     * @Adress
     * @Access
     * @Initial Value
     * @return
     */
    int present_load_l() const;

    /**
     * @brief present_load_h
     * @Adress
     * @Access
     * @Initial Value
     * @return
     */
    int present_load_h() const;

    /**
     * @brief present_position_l
     * @Adress
     * @Access
     * @Initial Value
     * @return
     */
    int present_position_l() const;

    /**
     * @brief present_position_h
     * @Adress
     * @Access
     * @Initial Value
     * @return
     */
    int present_position_h() const;

    /**
     * @brief present_speed_l
     * @Adress
     * @Access
     * @Initial Value
     * @return
     */
    int present_speed_l() const;

    /**
     * @brief present_speed_h
     * @Adress
     * @Access
     * @Initial Value
     * @return
     */
    int present_speed_h() const;

    /**
     * @brief present_voltage
     * @Adress
     * @Access
     * @Initial Value
     * @return
     */
    int present_voltage() const;

    /**
     * @brief present_temp
     * @Adress
     * @Access
     * @Initial Value
     * @return
     */
    int present_temp() const;

    /**
     * @brief registered
     * @Adress
     * @Access
     * @Initial Value
     * @return
     */
    int registered() const;

    /**
     * @brief moving
     * @Adress
     * @Access
     * @Initial Value
     * @return
     */
    int moving() const;

    /**
     * @brief lock
     * @Adress
     * @Access
     * @Initial Value
     * @return
     */
    int lock() const;

    /**
     * @brief punch_l
     * @Adress
     * @Access
     * @Initial Value
     * @return
     */
    int punch_l() const;

    /**
     * @brief punch_h
     * @Adress
     * @Access
     * @Initial Value
     * @return
     */
    int punch_h() const;

    /**
     * @brief goal_acceleration
     * @Adress
     * @Access
     * @Initial Value
     * @return
     */
    int goal_acceleration() const;

    /**
     * @brief connection
     * @Adress
     * @Access
     * @Initial Value
     * @return
     */
    bool connection() const;


private:

    /**** EEPROM ****/
    int m_model_number_l;
    int m_model_number_h;

    int m_firmware_version;
    int m_id;
    int m_baud_rate;
    int m_return_delay_time;

    int m_cw_angle_limit_l;
    int m_cw_angle_limit_h;
    int m_ccw_angle_limit_l;
    int m_ccw_angle_limit_h;

    int m_highest_temp_limit;
    int m_lowest_voltage_limit;
    int m_highest_voltage_limit;

    int m_max_torque_l;
    int m_max_torque_h;

    int m_status_return_level;
    int m_alarm_led;
    int m_alarm_shutdown;

    /**** RAM ****/
    int m_torque_enable;
    int m_led;

    /* DYNAMIXEL AX
    int cw_compliance_margin_;
    int ccw_compliance_margin_;
    int cw_compliance_slope_;
    int ccw_compliance_slope_;
    */

    int m_d_gain;
    int m_i_gain;
    int m_p_gain;

    int m_goal_position_l;
    int m_goal_position_h;
    int m_moving_speed_l;
    int m_moving_speed_h;
    int m_torque_limit_l;
    int m_torque_limit_h;
    int m_present_load_l;
    int m_present_load_h;
    int m_present_position_l;
    int m_present_position_h;
    int m_present_speed_l;
    int m_present_speed_h;

    int m_present_voltage;
    int m_present_temp;

    int m_registered;
    int m_moving;
    int m_lock;

    int m_punch_l;
    int m_punch_h;

    int m_goal_acceleration;

    bool m_connection;
};

#endif // DATA_HPP
