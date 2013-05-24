#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qcustomplot.h"

#include <QDebug>


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui_(new Ui::MainWindow) {
    ui_->setupUi(this);

    // Init member variables
    exit_ = false;
    power_ = false;

    // Connect signals with class slots
    connect(ui_->pbExit, SIGNAL(clicked()), this, SLOT(set_exit()));
    connect(ui_->pbPower, SIGNAL(clicked()), this, SLOT(set_power_on_off()));

    // Dynamic rescaling of the axis
    //connect(ui_->cp_plot->xAxis, SIGNAL(rangeChanged(QCPRange)), ui_->cp_plot->xAxis2, SLOT(setRange(QCPRange)));
    //connect(ui_->cp_plot->yAxis, SIGNAL(rangeChanged(QCPRange)), ui_->cp_plot->yAxis2, SLOT(setRange(QCPRange)));

    // Set up the plot parameters
    setup_plot();

    force_ = new QVector<double>(1);
    time_ = new QVector<double>(1);

}

MainWindow::~MainWindow() {
    delete ui_;
}

void MainWindow::changeEvent(QEvent *e) {
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui_->retranslateUi(this);
        break;
    default:
        break;
    }
}

void MainWindow::setup_plot() {
    // Create Graph and set color
    ui_->cp_plot->addGraph();
    ui_->cp_plot->graph(0)->setPen(QPen(Qt::blue));
    ui_->cp_plot->graph(0)->setLineStyle(QCPGraph::lsNone);
    ui_->cp_plot->graph(0)->setScatterStyle(QCP::ssCircle);
    ui_->cp_plot->graph(0)->setScatterSize(4);

    // Axis labels
    ui_->cp_plot->xAxis->setLabel("t");
    ui_->cp_plot->yAxis->setLabel("N");

    // Set range
    ui_->cp_plot->xAxis->setRange(-500,500);
    ui_->cp_plot->yAxis->setRange(-1.5,1.5);

}

void MainWindow::UpdateData() {

    switch(connection_) {
    case 0:
        ui_->le_connection->setText("No device connected");
        break;
    case 1:
        ui_->le_connection->setText("Failed to open USB2Dynamixel");
        break;
    case 2:
        ui_->le_connection->setText("Succeed to open USB2Dynamixel");
        break;
    case 3:
        ui_->le_connection->setText("Overheat - Cooldown required!");
        break;
    default:
        ui_->le_connection->setText("No device connected");
        break;
    }

    // Dynamixel ID
    data_.set_id(ui_->sbID->value());
    ui_->l_dynamixel_id->setText(QString::number(data_.id()));

    // Angle Limit
    data_.set_cw_angle_limit_l(ui_->hs_cw_angle_limit_l->value());
    data_.set_ccw_angle_limit_l(ui_->hs_ccw_angle_limit_l->value());
    ui_->l_cw_angle_limit_l->setText(QString::number(data_.cw_angle_limit_l()));
    ui_->l_ccw_angle_limit_l->setText(QString::number(data_.ccw_angle_limit_l()));

    // Voltage Limit
    data_.set_lowest_voltage_limit(ui_->hs_lowest_voltage_limit->value());
    data_.set_highest_voltage_limit(ui_->hs_highest_voltage_limit->value());
    ui_->l_lowest_voltage_limit->setText(QString::number(data_.lowest_voltage_limit()));
    ui_->l_highest_voltage_limit->setText(QString::number(data_.highest_voltage_limit()));

    // Max. Torque
    data_.set_max_torque_l(ui_->hs_max_torque_l->value());
    ui_->l_max_torque_l->setText(QString::number(data_.max_torque_l()));

    // Compliance Margin
    /* DYNAMIXEL AX
    data_.set_cw_compliance_margin(ui_->hs_cw_compliance_margin->value());
    data_.set_ccw_compliance_margin(ui_->hs_ccw_compliance_margin->value());
    ui_->l_cw_compliance_margin->setText(QString::number(data_.cw_compliance_margin()));
    ui_->l_ccw_compliance_margin->setText(QString::number(data_.ccw_compliance_margin()));


    // Compliance Slope
    data_.set_cw_compliance_slope(ui_->hs_cw_compliance_slope->value());
    data_.set_ccw_compliance_slope(ui_->hs_ccw_compliance_slope->value());
    ui_->l_cw_compliance_slope->setText(QString::number(data_.cw_compliance_slope()));
    ui_->l_ccw_compliance_slope->setText(QString::number(data_.ccw_compliance_slope()));
    */

    // PID Gain
    data_.set_d_gain(ui_->hs_d_gain->value());
    data_.set_i_gain(ui_->hs_i_gain->value());
    data_.set_p_gain(ui_->hs_p_gain->value());
    ui_->l_d_gain->setText(QString::number(data_.d_gain()));
    ui_->l_i_gain->setText(QString::number(data_.i_gain()));
    ui_->l_p_gain->setText(QString::number(data_.p_gain()));


    // Torque Enable
    data_.set_torque_enable(ui_->hs_torque_enable->value());
    ui_->l_torque_enable->setText(QString::number(data_.torque_enable()));

    // Goal Position
    data_.set_goal_position_l(ui_->hs_goal_pos_l->value());
    ui_->l_goal_pos_l->setText(QString::number(data_.goal_position_l()));

    // Moving Speed
    data_.set_moving_speed_l(ui_->hs_move_speed_l->value());
    ui_->l_move_speed_l->setText(QString::number(data_.moving_speed_l()));

    // Torque Limit
    data_.set_torque_limit_l(ui_->hs_torque_limit_l->value());
    ui_->l_torque_limit_l->setText(QString::number(data_.torque_limit_l()));

    // Lock
    data_.set_lock(ui_->hs_lock->value());
    ui_->l_lock->setText(QString::number(data_.lock()));

    // Punch
    data_.set_punch_l(ui_->hs_punch_l->value());

    ui_->l_punch_l->setText(QString::number(data_.punch_l()));

    // Goal Acceleration
    data_.set_goal_acceleration(ui_->hs_goal_acceleration->value());
    ui_->l_goal_acceleration->setText(QString::number(data_.goal_acceleration()));

    // Copy number of spin box
    data_.set_save_number(ui_->sbNumber->value());

}


void MainWindow::set_data(Data const& data) {

    ui_->l_dynamixel_id->setText(QString::number(data.id()));

    // Display read only informtion on UI
    ui_->l_present_pos_l->setText(QString::number(data.present_position_l()));
    ui_->l_present_pos_h->setText(QString::number(data.present_position_h()));
    ui_->l_present_speed_l->setText(QString::number(data.present_speed_l()));
    ui_->l_present_speed_h->setText(QString::number(data.present_speed_h()));
    ui_->l_present_load_l->setText(QString::number(data.present_load_l()));
    ui_->l_present_load_h->setText(QString::number(data.present_load_h()));
    ui_->l_present_voltage->setText(QString::number(data.present_voltage()));
    ui_->l_present_temp->setText(QString::number(data.present_temp()));
    ui_->l_registered->setText(QString::number(data.registered()));
    ui_->l_moving->setText(QString::number(data.moving()));



    // Plot data to graph
    double pos = (double)(data.goal_position_l() - data.present_position_l());
    time_->push_back(pos);
    double force = data.force()*0.04;
    force_->push_back(force);

    ui_->cp_plot->graph(0)->setData(*time_, *force_);
    ui_->cp_plot->replot();

}

void MainWindow::set_connection(int const& connection) {
    connection_ = connection;
}


Data MainWindow::data() const {
    return data_;
}

bool MainWindow::exit() const {
    return exit_;
}

bool MainWindow::power() const {
    return power_;
}

void MainWindow::set_exit() {
    exit_ = true;
}

// Set variable power_, lable color and button name
void MainWindow::set_power_on_off() {
    if (power_ == false) {
        power_ = true;
        ui_->lPower->setStyleSheet("background-color: rgb(0, 255, 0);");
        ui_->pbPower->setText("Power off");
    } else {
        power_ = false;
        ui_->lPower->setStyleSheet("background-color: rgb(255, 0, 0);");
        ui_->pbPower->setText("Power on");

    }
}


