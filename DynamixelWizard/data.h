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
     * @brief set_model_number word of model number
     * @Adress 0 (0X00)
     * @Access R
     * @Initial Value 29 (0X1D)
     * @param model_number
     */
    void set_model_number(int const model_number);

    /**
     * @brief set_firmware_version Information on the version of firmware
     * @Adress 2 (0X02)
     * @Access R
     * @Initial Value -
     * @param firmware_version
     */
    void set_firmware_version(int const firmware_version);

    /**
     * @brief set_id ID of Dynamixel
     * @Adress 3 (0X03)
     * @Access RW
     * @Initial Value 1 (0X01)
     * @param id
     */
    void set_id(int const id);

    /**
     * @brief set_baud_rate Baud Rate of Dynamixel
     * @Adress 4 (0X04)
     * @Access RW
     * @Initial Value 34 (0X22)
     * @param baud_rate
     */
    void set_baud_rate(int const baud_rate);

    /**
     * @brief set_return_delay_time Return Delay Time
     * It is the delay time per data value that takes from the transmission of Instruction Packet until the return of Status Packet.
     * 0 to 254 (0xFE) can be used, and the delay time per data value is 2 usec.
     * That is to say, if the data value is 10, 20 usec is delayed. The initial value is 250 (0xFA) (i.e., 0.5 msec).
     * @Adress 5 (0X05)
     * @Access RW
     * @Initial Value 250 (0XFA)
     * @param return_delay_time
     */
    void set_return_delay_time(int const return_delay_time);

    /**
     * @brief set_cw_angle_limit word of clockwise Angle Limit
     * @Adress 6 (0X06)
     * @Access RW
     * @Initial Value 0 (0X00)
     * @param cw_angle_limit_l
     */
    void set_cw_angle_limit(int const cw_angle_limit);

    /**
     * @brief set_ccw_angle_limit word of counterclockwise Angle Limit
     * @Adress 8 (0X08)
     * @Access RW
     * @Initial Value 255 (0XFF)
     * @param ccw_angle_limit_l
     */
    void set_ccw_angle_limit(int const ccw_angle_limit);

    /**
     * @brief set_highest_temp_limit Internal Temperature Limit
     * @Adress 11 (0X0B)
     * @Access RW
     * @Initial Value
     * @param highest_temp_limit
     */
    void set_highest_temp_limit(int const highest_temp_limit);

    /**
     * @brief set_lowest_voltage_limit Lowest Voltage Limit
     * @Adress 12 (0X0C)
     * @Access RW
     * @Initial Value 60 (0X3C)
     * @param lowest_voltage_limit
     */
    void set_lowest_voltage_limit(int const lowest_voltage_limit);

    /**
     * @brief set_highest_voltage_limit
     * @Adress 13 (0X0D)
     * @Access RW
     * @Initial Value 160 (0XA0)
     * @param highest_voltage_limit
     */
    void set_highest_voltage_limit(int const highest_voltage_limit);

    /**
     * @brief set_max_torque word of Max. Torque
     * @Adress 14 (0X0E)
     * @Access RW
     * @Initial Value 255 (0XFF)
     * @param max_torque_l
     */
    void set_max_torque(int const max_torque);

    /**
     * @brief set_status_return_level Status Return Level
     * @Adress 16 (0X10)
     * @Access RW
     * @Initial Value 2 (0X02)
     * @param status_return_level
     */
    void set_status_return_level(int const status_return_level);

    /**
     * @brief set_alarm_led LED for Alarm
     * @Adress 17 (0X11)
     * @Access RW
     * @Initial Value 36 (0X24)
     * @param alarm_led
     */
    void set_alarm_led(int const alarm_led);

    /**
     * @brief set_alarm_shutdown Shutdown for Alarm
     * @Adress 18 (0X12)
     * @Access RW
     * @Initial Value 36 (0X24)
     * @param alarm_shutdown
     */
    void set_alarm_shutdown(int const alarm_shutdown);

    /***** RAM *****/
    /**
     * @brief set_torque_enable
     * @Adress 24 (0X18)
     * @Access RW
     * @Initial Value 0 (0X00)
     * @param torque_enable
     */
    void set_torque_enable(int const torque_enable);

    /**
     * @brief set_led
     * @Adress 25 (0X19)
     * @Access RW
     * @Initial Value 0 (0X00)
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
     * @brief set_d_gain Derivative Gain
     * @Adress 26 (0X1A)
     * @Access RW
     * @Initial Value 0 (0X00)
     * @param d_gain
     */
    void set_d_gain(int const d_gain);

    /**
     * @brief set_i_gain Integral Gain
     * @Adress 27 (0X1B)
     * @Access RW
     * @Initial Value 0 (0X00)
     * @param i_gain
     */
    void set_i_gain(int const i_gain);

    /**
     * @brief set_p_gain Proportional Gain
     * @Adress 28 (0X1C)
     * @Access RW
     * @Initial Value 32 (0X20)
     * @param p_gain
     */
    void set_p_gain(int const p_gain);

    /**
     * @brief set_goal_position word of Goal Position
     * @Adress 30 (0X1E)
     * @Access RW
     * @Initial Value -
     * @param goal_position_l
     */
    void set_goal_position(int const goal_position);

    /**
     * @brief set_moving_speed word of Moving Speed
     * @Adress 32 (0X20)
     * @Access RW
     * @Initial Value -
     * @param moving_speed_l
     */
    void set_moving_speed(int const moving_speed);

    /**
     * @brief set_torque_limit word of Torque Limit
     * @Adress 34 (0X22)
     * @Access RW
     * @Initial Value ADD14 (Max Torque L)
     * @param torque_limit_l
     */
    void set_torque_limit(int const torque_limit);

    /**
     * @brief set_present_load word of Present Load
     * @Adress
     * @Access R
     * @Initial Value
     * @param present_load_l
     */
    void set_present_load(int const present_load);


    /**
     * @brief set_present_position word of Present Position
     * @Adress
     * @Access RW
     * @Initial Value
     * @param present_position_l
     */
     void set_present_position(int const present_position);

    /**
     * @brief set_present_speed word of Present Speed
     * @Adress
     * @Access
     * @Initial Value
     * @param present_speed_l
     */
    void set_present_speed(int const present_speed);

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
     * @Adress 44 (0X2C)
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
     * @param movin
     */
    void set_moving(int const moving);

    /**
     * @brief set_lock Locking EEPROM
     * @Adress 47 (0X2F)
     * @Access RW
     * @Initial Value 0 (0X00)
     * @param lock
     */
    void set_lock(int const lock);

    /**
     * @brief set_punch word of Punch
     * @Adress
     * @Access
     * @Initial Value 0 (0X00)
     * @param punch_l
     */
    void set_punch(int const punch);

    /**
     * @brief set_goal_acceleration word of Goal Acceleration
     * @Adress
     * @Access
     * @Initial Value 0 (0X00)
     * @param goal_acceleration
     */
    void set_goal_acceleration(int const goal_acceleration);

    /** TODO what does this do? - delete
     * @brief set_save_number
     * @Adress
     * @Access
     * @Initial Value
     * @param save_number
     */
    void set_save_number(int const save_number);

    /**
     * @brief set_connection
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
     * @Access R
     * @Initial Value
     * @return
     */
    int model_number() const;

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
     * @brief cw_angle_limit
     * @Adress
     * @Access
     * @Initial Value
     * @return
     */
    int cw_angle_limit() const;

    /**
     * @brief ccw_angle_limit
     * @Adress
     * @Access
     * @Initial Value
     * @return
     */
    int ccw_angle_limit() const;

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
     * @brief max_torque
     * @Adress
     * @Access
     * @Initial Value
     * @return
     */
    int max_torque() const;

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
     * @brief goal_position
     * @Adress
     * @Access
     * @Initial Value
     * @return
     */
    int goal_position() const;

    /**
     * @brief moving_speed
     * @Adress
     * @Access
     * @Initial Value
     * @return
     */
    int moving_speed() const;

    /**
     * @brief torque_limit
     * @Adress
     * @Access
     * @Initial Value
     * @return
     */
    int torque_limit() const;

    /**
     * @brief present_load
     * @Adress
     * @Access
     * @Initial Value
     * @return
     */
    int present_load() const;


    /**
     * @brief present_position
     * @Adress
     * @Access
     * @Initial Value
     * @return
     */
    int present_position() const;

    /**
     * @brief present_speed
     * @Adress
     * @Access
     * @Initial Value
     * @return
     */
    int present_speed() const;

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
     * @brief punch
     * @Adress
     * @Access
     * @Initial Value
     * @return
     */
    int punch() const;

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
    int m_model_number;

    int m_firmware_version;
    int m_id;
    int m_baud_rate;
    int m_return_delay_time;

    int m_cw_angle_limit;
    int m_ccw_angle_limit;

    int m_highest_temp_limit;
    int m_lowest_voltage_limit;
    int m_highest_voltage_limit;

    int m_max_torque;

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

    int m_goal_position;
    int m_moving_speed;
    int m_torque_limit;
    int m_present_load;
    int m_present_position;
    int m_present_speed;

    int m_present_voltage;
    int m_present_temp;

    int m_registered;
    int m_moving;
    int m_lock;

    int m_punch;

    int m_goal_acceleration;

    bool m_connection;
};

#endif // DATA_HPP
