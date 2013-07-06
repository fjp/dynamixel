#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "dynamixel.h" //TODO weg

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_iSelectedAdress(25)
{
    ui->setupUi(this);

    m_cbUSBPort = new QComboBox(this);
    m_cbUSBPort->addItem("0");

    m_ittyUSBPort = m_cbUSBPort->itemData(m_cbUSBPort->currentIndex()).toInt();

    ui->mainToolBar->addWidget(m_cbUSBPort);
    ui->mainToolBar->addSeparator();
    ui->mainToolBar->addAction("Connect", this, SLOT(slotConnect()));
    connect(ui->pbStartSearching, SIGNAL(clicked()), this, SLOT(slotStartSearching()));
    //ui->mainToolBar->addAction()

    ui->tawControlTable->resizeColumnsToContents();

    connect(ui->trwFoundDynamixel, SIGNAL(itemClicked(QTreeWidgetItem*, int)), this, SLOT(slotDynamixelSelected(QTreeWidgetItem*, int)));
    connect(ui->tawControlTable, SIGNAL(cellClicked(int,int)), this, SLOT(slotSelectedControl(int,int)));

    for (int i = 0; i < 254; ++i)
    {
        ui->cbID->addItem(QString::number(i));
    }

    initStackedWidgetConnects();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::slotConnect()
{
    ui->swMain->setCurrentWidget(ui->pageConnection);

}


void MainWindow::slotStartSearching()
{
    if (ui->trwFoundDynamixel->topLevelItemCount() > 0)
    {
        ui->trwFoundDynamixel->clear();
    }

    for (int index = 0; index < ui->lwBaudRates->count(); ++index)
    {
        QListWidgetItem* lwiBaudRate = ui->lwBaudRates->item(index);
        if (lwiBaudRate->checkState() == Qt::Checked)
        {
            int iBaudRate = lwiBaudRate->text().toInt();
            qDebug() << "BaudRate: " << iBaudRate;

            /***** Open USB2Dynamixel with current BaudRate iBaudRate *****/
            connectToDynamixel(m_ittyUSBPort, iBaudRate);
            /*
            if (dxl_initialize(m_ittyUSBPort, iBaudRate) == 0)
            {
                qDebug() << "Failed to open USB2Dynamixel!\n";
                qDebug() << "Press Enter key to terminate...\n";
            }
            else
            {
                qDebug() << "Succeed to open USB2Dynamixel!\n";

                QString qsBaudRate = "Baud Rate: " + QString::number(iBaudRate);
                QTreeWidgetItem* qtwiBaudRate = new QTreeWidgetItem;

                if (ui->trwFoundDynamixel->findItems(qsBaudRate, Qt::MatchExactly).isEmpty())
                {
                    qtwiBaudRate->setText(0, qsBaudRate);
                    ui->trwFoundDynamixel->addTopLevelItem(qtwiBaudRate);
                }


                for (int iID = 0; iID <= 253; ++iID)
                {
                    ui->lSearching->setText(QString::number(iID));
                    ui->proBarSearching->setValue(static_cast<int>(static_cast<double>(iID)/253*100));
                    ui->proBarSearching->repaint();
                    QApplication::processEvents();

                    dxl_ping(iID);
                    if(dxl_get_result() == COMM_RXSUCCESS)
                    {
                        qDebug() << "Found Dynamixel with ID: " << iID;

                        QTreeWidgetItem* qtwiDynamixel = new QTreeWidgetItem;
                        qtwiDynamixel->setText(0, "Dynamixel ID: " + QString::number(iID));
                        qtwiBaudRate->addChild(qtwiDynamixel);
                    }
                }
            }*/
        }
    }
}

void MainWindow::slotDynamixelSelected(QTreeWidgetItem* qtwiItem, int iColumn)
{
    qDebug() << qtwiItem << iColumn;

    ui->swMain->setCurrentWidget(ui->pageSettings);

    int iBaudRate = 0;
    m_iSelectedDynamixelID = 254; // Broadcast ID to command all Dynamixel in the same Baud Rate

    // Check if selected item is a Child. qtwiBaudRate == NULL -> parent selected
    QTreeWidgetItem* qtwiBaudRate = qtwiItem->parent();
    if (qtwiBaudRate != NULL)
    {
        iBaudRate = qtwiBaudRate->text(0).split(" ").at(2).toInt();

        // extract ID from QString "Dynamixel ID: 1" -> .at(2)
        m_iSelectedDynamixelID = qtwiItem->text(0).split(" ").at(2).toInt();
    }
    else
    {
        // extract BaudRate from QString "Baud Rate: 1" -> .at(2)
        iBaudRate = qtwiItem->text(0).split(" ").at(2).toInt();
        m_iSelectedDynamixelID = 254;
    }


    qDebug() << "Dynamixel with ID" << m_iSelectedDynamixelID << "clicked";

    if (dxl_initialize(m_ittyUSBPort, iBaudRate) == 0)
    {
        qDebug() << "Failed to open USB2Dynamixel!\n";
        qDebug() << "Press Enter key to terminate...\n";
    }
    else
    {
        slotUpdateData();
    }
}

void MainWindow::slotValueChanged()
{
    Servo servo();

    qDebug() << "slotValueChanged: update data()";
    data();
    //slotUpdateData();

    servo.write_data(m_oData);

}

void MainWindow::slotSelectedControl(int row, int col)
{
    //qDebug() << "Row" << row;
    //qDebug() << "Column" << col;

    ui->swSelectedControl->setCurrentIndex(row);

    // Get Adress of selected Control
    m_iSelectedAdress = ui->tawControlTable->item(row, 1)->text().split(" ").at(0).toInt();
    qDebug() << "Adress:" << m_iSelectedAdress;

}

void MainWindow::slotUpdateData()
{
    Servo servo(m_iSelectedDynamixelID);

    m_oData = servo.receive_data();

    qDebug() << "ID:" << m_oData.id();

    ui->tawControlTable->setItem(0, 3, new QTableWidgetItem(QString::number(m_oData.model_number_l())));
    // TODO update swSelectedControl pages
    ui->tawControlTable->setItem(1, 3, new QTableWidgetItem(QString::number(m_oData.firmware_version())));

    ui->tawControlTable->setItem(2, 3, new QTableWidgetItem(QString::number(m_oData.id())));
    ui->cbID->setCurrentIndex(m_oData.id());

    ui->tawControlTable->setItem(3, 3, new QTableWidgetItem(QString::number(m_oData.baud_rate())));
    ui->tawControlTable->setItem(4, 3, new QTableWidgetItem(QString::number(m_oData.return_delay_time())));
    ui->tawControlTable->setItem(5, 3, new QTableWidgetItem(QString::number(m_oData.cw_angle_limit_l())));
    ui->vsCWAngleLimit->setValue(m_oData.cw_angle_limit_l());

    ui->tawControlTable->setItem(6, 3, new QTableWidgetItem(QString::number(m_oData.ccw_angle_limit_l())));
    ui->vsCCWAngleLimit->setValue(m_oData.ccw_angle_limit_l());

    ui->tawControlTable->setItem(7, 3, new QTableWidgetItem(QString::number(m_oData.highest_temp_limit())));
    ui->vsTemperatureLimit->setValue(m_oData.highest_temp_limit());

    ui->tawControlTable->setItem(8, 3, new QTableWidgetItem(QString::number(m_oData.lowest_voltage_limit())));
    ui->vsLowestVoltageLimit->setValue(m_oData.lowest_voltage_limit());

    ui->tawControlTable->setItem(9, 3, new QTableWidgetItem(QString::number(m_oData.highest_voltage_limit())));
    ui->vsHighestVoltageLimit->setValue(m_oData.highest_voltage_limit());

    ui->tawControlTable->setItem(10, 3, new QTableWidgetItem(QString::number(m_oData.max_torque_l())));
    ui->vsMaxTorque->setValue(m_oData.max_torque_l());
    ui->sbMaxTorque->setValue(m_oData.max_torque_l());

    ui->tawControlTable->setItem(11, 3, new QTableWidgetItem(QString::number(m_oData.status_return_level())));
    ui->cbReturnLevel->setCurrentIndex(m_oData.status_return_level());

    ui->tawControlTable->setItem(12, 3, new QTableWidgetItem(QString::number(m_oData.alarm_led())));
    // TODO handle swSelectedControl Page

    ui->tawControlTable->setItem(13, 3, new QTableWidgetItem(QString::number(m_oData.alarm_shutdown())));
    // TODO handle swSelectedControl Page

    ui->tawControlTable->setItem(14, 3, new QTableWidgetItem(QString::number(m_oData.torque_enable())));
    if (m_oData.torque_enable() == true)
    {
        ui->rbTEON->setChecked(true);
        ui->rbTEOFF->setChecked(false);
    }
    else
    {
        ui->rbTEON->setChecked(false);
        ui->rbTEOFF->setChecked(true);
    }


    ui->tawControlTable->setItem(15, 3, new QTableWidgetItem(QString::number(m_oData.led())));
    if (m_oData.torque_enable() == true)
    {
        ui->rbLEDON->setChecked(true);
        ui->rbLEDOFF->setChecked(false);
    }
    else
    {
        ui->rbLEDON->setChecked(false);
        ui->rbLEDOFF->setChecked(true);
    }

    ui->tawControlTable->setItem(16, 3, new QTableWidgetItem(QString::number(m_oData.d_gain())));
    ui->sbDG->setValue(m_oData.d_gain());

    ui->tawControlTable->setItem(17, 3, new QTableWidgetItem(QString::number(m_oData.i_gain())));
    ui->sbIG->setValue(m_oData.i_gain());

    ui->tawControlTable->setItem(18, 3, new QTableWidgetItem(QString::number(m_oData.p_gain())));
    ui->sbPG->setValue(m_oData.p_gain());

    ui->tawControlTable->setItem(19, 3, new QTableWidgetItem(QString::number(m_oData.goal_position_l())));
    ui->dialGoalPosition->setValue(m_oData.goal_position_l());

    ui->tawControlTable->setItem(20, 3, new QTableWidgetItem(QString::number(m_oData.moving_speed_l())));
    ui->vsMovingSpeed->setValue(m_oData.moving_speed_l());

    ui->tawControlTable->setItem(21, 3, new QTableWidgetItem(QString::number(m_oData.torque_limit_l())));
    ui->vsTorqueLimit->setValue(m_oData.torque_limit_l());

    ui->tawControlTable->setItem(22, 3, new QTableWidgetItem(QString::number(m_oData.present_position_l())));
    ui->dialPresentPosition->setValue(m_oData.present_position_l());

    ui->tawControlTable->setItem(23, 3, new QTableWidgetItem(QString::number(m_oData.present_speed_l())));
    if (0 <= m_oData.present_position_l() && m_oData.present_speed_l() <= 1023)
    {
        ui->rbPSCW->setChecked(false);
        ui->rbPSCCW->setChecked(true);
    }
    else
    {
        ui->rbPSCW->setChecked(true);
        ui->rbPSCCW->setChecked(false);
    }
    ui->lblPresentSpeedValue->setText(QString::number(m_oData.present_speed_l()));

    ui->tawControlTable->setItem(24, 3, new QTableWidgetItem(QString::number(m_oData.present_load_l())));
    ui->tawControlTable->setItem(25, 3, new QTableWidgetItem(QString::number(m_oData.present_voltage())));
    ui->tawControlTable->setItem(26, 3, new QTableWidgetItem(QString::number(m_oData.present_temp())));
    ui->tawControlTable->setItem(27, 3, new QTableWidgetItem(QString::number(m_oData.registered())));
    ui->tawControlTable->setItem(28, 3, new QTableWidgetItem(QString::number(m_oData.moving())));
    ui->tawControlTable->setItem(29, 3, new QTableWidgetItem(QString::number(m_oData.lock())));
    ui->tawControlTable->setItem(30, 3, new QTableWidgetItem(QString::number(m_oData.punch_l())));
    ui->tawControlTable->setItem(31, 3, new QTableWidgetItem(QString::number(m_oData.goal_acceleration())));
}

void MainWindow::initStackedWidgetConnects()
{
    connect(ui->cbID, SIGNAL(currentIndexChanged(int)), this, SLOT(slotValueChanged()));
    connect(ui->cbBaudrate, SIGNAL(currentIndexChanged(int)), this, SLOT(slotValueChanged()));
    connect(ui->cbReturnDelayTime, SIGNAL(currentIndexChanged(int)), this, SLOT(slotValueChanged()));

    connect(ui->vsCWAngleLimit, SIGNAL(valueChanged(int)), this, SLOT(slotValueChanged()));
    connect(ui->sbCWAngleLimit, SIGNAL(valueChanged(int)), this, SLOT(slotValueChanged()));

    connect(ui->vsCCWAngleLimit, SIGNAL(valueChanged(int)), this, SLOT(slotValueChanged()));
    connect(ui->sbCCWAngleLimit, SIGNAL(valueChanged(int)), this, SLOT(slotValueChanged()));

    //connect(ui->rbLEDON, SIGNAL(clicked()), this, SLOT(slotValueChanged()));

    connect(ui->dialGoalPosition, SIGNAL(valueChanged(int)), this, SLOT(slotValueChanged()));
}

void MainWindow::data()
{
    m_oData.set_model_number_l(ui->tawControlTable->item(0, 3)->text().toInt());
    m_oData.set_firmware_version(ui->tawControlTable->item(1, 3)->text().toInt());

    m_oData.set_id(ui->cbID->currentText().toInt());
    m_oData.set_baud_rate(ui->cbBaudrate->currentText().toInt());
    m_oData.set_return_delay_time(ui->cbReturnDelayTime->currentText().toInt());
    m_oData.set_cw_angle_limit_l(ui->vsCWAngleLimit->value());
    m_oData.set_ccw_angle_limit_l(ui->vsCCWAngleLimit->value());
    m_oData.set_highest_temp_limit(ui->vsTemperatureLimit->value());
    m_oData.set_lowest_voltage_limit(ui->vsLowestVoltageLimit->value());
    m_oData.set_highest_voltage_limit(ui->vsHighestVoltageLimit->value());
    m_oData.set_max_torque_l(ui->vsMaxTorque->value());
    m_oData.set_status_return_level(ui->cbReturnLevel->currentIndex());
    m_oData.set_alarm_led(getAlarmLED());
    m_oData.set_alarm_shutdown(getAlarmShutdown());
    m_oData.set_torque_enable(ui->rbTEON->isChecked());
    m_oData.set_led(ui->rbLEDON->isChecked());
    m_oData.set_d_gain(ui->sbDG->value());
    m_oData.set_i_gain(ui->sbIG->value());
    m_oData.set_p_gain(ui->sbPG->value());
    qDebug() << ui->dialGoalPosition->value();
    m_oData.set_goal_position_l(ui->dialGoalPosition->value());
    qDebug() << m_oData.goal_position_l();
    m_oData.set_moving_speed_l(ui->vsMovingSpeed->value());
    m_oData.set_torque_limit_l(ui->vsTorqueLimit->value());
    m_oData.set_present_position_l(ui->dialPresentPosition->value());


    ui->tawControlTable->setItem(22, 3, new QTableWidgetItem(QString::number(m_oData.present_position_l())));
    ui->tawControlTable->setItem(23, 3, new QTableWidgetItem(QString::number(m_oData.present_speed_l())));
    ui->tawControlTable->setItem(24, 3, new QTableWidgetItem(QString::number(m_oData.present_load_l())));
    ui->tawControlTable->setItem(25, 3, new QTableWidgetItem(QString::number(m_oData.present_voltage())));
    ui->tawControlTable->setItem(26, 3, new QTableWidgetItem(QString::number(m_oData.present_temp())));
    ui->tawControlTable->setItem(27, 3, new QTableWidgetItem(QString::number(m_oData.registered())));
    ui->tawControlTable->setItem(28, 3, new QTableWidgetItem(QString::number(m_oData.moving())));
    ui->tawControlTable->setItem(29, 3, new QTableWidgetItem(QString::number(m_oData.lock())));
    ui->tawControlTable->setItem(30, 3, new QTableWidgetItem(QString::number(m_oData.punch_l())));
    ui->tawControlTable->setItem(31, 3, new QTableWidgetItem(QString::number(m_oData.goal_acceleration())));
}

int MainWindow::getAlarmLED()
{
    return ui->cbALInstruction->isChecked()*64 + ui->cbALOverload->isChecked()*32 + ui->cbALChecksum->isChecked()*16 +
            ui->cbALRange->isChecked()*8 + ui->cbALOverheating->isChecked()*4 + ui->cbALAngleLimit->isChecked()*2 + ui->cbALInputVoltage->isChecked();
}

int MainWindow::getAlarmShutdown()
{
    return ui->cbASInstruction->isChecked()*64 + ui->cbASOverload->isChecked()*32 + ui->cbASChecksum->isChecked()*16 +
            ui->cbASRange->isChecked()*8 + ui->cbASOverheating->isChecked()*4 + ui->cbASAngleLimit->isChecked()*2 + ui->cbASInputVoltage->isChecked();
}

void MainWindow::set_data()
{

}

void MainWindow::UpdateData(const Data &coData)
{

}

void MainWindow::set_connection(const int &ciConnection)
{

}

void MainWindow::connectToDynamixel(int ittyUSBPort, int iBaudRate) const
{
    if (dxl_initialize(ittyUSBPort, iBaudRate) == 0)    // TODO MessageBox
    {
        qDebug() << "Failed to open USB2Dynamixel!\n";
        qDebug() << "Press Enter key to terminate...\n";
    }
    else
    {
        qDebug() << "Succeed to open USB2Dynamixel!\n";

        QString qsBaudRate = "Baud Rate: " + QString::number(iBaudRate);
        QTreeWidgetItem* qtwiBaudRate = new QTreeWidgetItem;

        if (ui->trwFoundDynamixel->findItems(qsBaudRate, Qt::MatchExactly).isEmpty())
        {
            qtwiBaudRate->setText(0, qsBaudRate);
            ui->trwFoundDynamixel->addTopLevelItem(qtwiBaudRate);
        }


        /***** Check the existence of Dynamixel with specific ID *****/
        for (int iID = 0; iID <= 253; ++iID)
        {
            ui->lSearching->setText(QString::number(iID));
            ui->proBarSearching->setValue(static_cast<int>(static_cast<double>(iID)/253*100));
            ui->proBarSearching->repaint();
            QApplication::processEvents();

            dxl_ping(iID);
            if(dxl_get_result() == COMM_RXSUCCESS)
            {
                qDebug() << "Found Dynamixel with ID: " << iID;

                QTreeWidgetItem* qtwiDynamixel = new QTreeWidgetItem;
                qtwiDynamixel->setText(0, "Dynamixel ID: " + QString::number(iID));
                qtwiBaudRate->addChild(qtwiDynamixel);
            }
        }
    }
}
