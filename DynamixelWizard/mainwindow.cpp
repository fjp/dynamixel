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

    qDebug() << "slotValueChanged: update data()";
    data();
    //slotUpdateData();

    m_qlServoList[m_iSelectedDynamixelID]->write_data(m_oData);

    //slotUpdateData();
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
    m_oData = m_qlServoList[m_iSelectedDynamixelID]->receive_data();

    qDebug() << "ID:" << m_oData.id();

    ui->tawControlTable->setItem(0, 3, new QTableWidgetItem(QString::number(m_oData.model_number())));
    // TODO update swSelectedControl pages
    ui->tawControlTable->setItem(1, 3, new QTableWidgetItem(QString::number(m_oData.firmware_version())));

    ui->tawControlTable->setItem(2, 3, new QTableWidgetItem(QString::number(m_oData.id())));
    ui->cbID->setCurrentIndex(m_oData.id());

    ui->tawControlTable->setItem(3, 3, new QTableWidgetItem(QString::number(m_oData.baud_rate())));
    ui->tawControlTable->setItem(4, 3, new QTableWidgetItem(QString::number(m_oData.return_delay_time())));
    ui->tawControlTable->setItem(5, 3, new QTableWidgetItem(QString::number(m_oData.cw_angle_limit())));
    ui->vsCWAngleLimit->setValue(m_oData.cw_angle_limit());

    ui->tawControlTable->setItem(6, 3, new QTableWidgetItem(QString::number(m_oData.ccw_angle_limit())));
    ui->vsCCWAngleLimit->setValue(m_oData.ccw_angle_limit());

    ui->tawControlTable->setItem(7, 3, new QTableWidgetItem(QString::number(m_oData.highest_temp_limit())));
    ui->vsTemperatureLimit->setValue(m_oData.highest_temp_limit());

    ui->tawControlTable->setItem(8, 3, new QTableWidgetItem(QString::number(m_oData.lowest_voltage_limit())));
    ui->vsLowestVoltageLimit->setValue(m_oData.lowest_voltage_limit());

    ui->tawControlTable->setItem(9, 3, new QTableWidgetItem(QString::number(m_oData.highest_voltage_limit())));
    ui->vsHighestVoltageLimit->setValue(m_oData.highest_voltage_limit());

    ui->tawControlTable->setItem(10, 3, new QTableWidgetItem(QString::number(m_oData.max_torque())));
    ui->vsMaxTorque->setValue(m_oData.max_torque());
    ui->sbMaxTorque->setValue(m_oData.max_torque());

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

    ui->tawControlTable->setItem(19, 3, new QTableWidgetItem(QString::number(m_oData.goal_position())));
    ui->dialGoalPosition->setValue(m_oData.goal_position());

    ui->tawControlTable->setItem(20, 3, new QTableWidgetItem(QString::number(m_oData.moving_speed())));
    ui->vsMovingSpeed->setValue(m_oData.moving_speed());

    ui->tawControlTable->setItem(21, 3, new QTableWidgetItem(QString::number(m_oData.torque_limit())));
    ui->vsTorqueLimit->setValue(m_oData.torque_limit());

    ui->tawControlTable->setItem(22, 3, new QTableWidgetItem(QString::number(m_oData.present_position())));
    ui->dialPresentPosition->setValue(m_oData.present_position());

    ui->tawControlTable->setItem(23, 3, new QTableWidgetItem(QString::number(m_oData.present_speed())));
    if (0 <= m_oData.present_position() && m_oData.present_speed() <= 1023)
    {
        ui->rbPSCW->setChecked(false);
        ui->rbPSCCW->setChecked(true);
    }
    else
    {
        ui->rbPSCW->setChecked(true);
        ui->rbPSCCW->setChecked(false);
    }
    ui->lblPresentSpeedValue->setText(QString::number(m_oData.present_speed()));

    ui->tawControlTable->setItem(24, 3, new QTableWidgetItem(QString::number(m_oData.present_load())));
    ui->lblPresentLoadValue->setText(QString::number(m_oData.present_load()));

    ui->tawControlTable->setItem(25, 3, new QTableWidgetItem(QString::number(m_oData.present_voltage())));
    ui->lblPresentVoltageValue->setText(QString::number(m_oData.present_voltage()));

    ui->tawControlTable->setItem(26, 3, new QTableWidgetItem(QString::number(m_oData.present_temp())));
    ui->tawControlTable->setItem(27, 3, new QTableWidgetItem(QString::number(m_oData.registered())));
    ui->tawControlTable->setItem(28, 3, new QTableWidgetItem(QString::number(m_oData.moving())));

    ui->tawControlTable->setItem(29, 3, new QTableWidgetItem(QString::number(m_oData.lock())));

    ui->tawControlTable->setItem(30, 3, new QTableWidgetItem(QString::number(m_oData.punch())));
    ui->sbPunch->setValue(m_oData.punch());

    ui->tawControlTable->setItem(31, 3, new QTableWidgetItem(QString::number(m_oData.goal_acceleration())));
    ui->sbGoalAcceleration->setValue(m_oData.goal_acceleration());
}

void MainWindow::initStackedWidgetConnects()
{
    connect(ui->pbIDApply, SIGNAL(clicked()), this, SLOT(slotValueChanged()));

    connect(ui->pbBaudApply, SIGNAL(clicked()), this, SLOT(slotValueChanged()));

    connect(ui->pbReturnDelayTimeApply, SIGNAL(clicked()), this, SLOT(slotValueChanged()));

    connect(ui->pbCWAngleLimitApply, SIGNAL(clicked()), this, SLOT(slotValueChanged()));
    connect(ui->pbCCWAngleLimitApply, SIGNAL(clicked()), this, SLOT(slotValueChanged()));

    connect(ui->pbTemperatureLimitApply, SIGNAL(clicked()), this, SLOT(slotValueChanged()));

    connect(ui->pbLowestVoltageLimitApply, SIGNAL(clicked()), this, SLOT(slotValueChanged()));
    connect(ui->pbHighestVoltageLimitApply, SIGNAL(clicked()), this, SLOT(slotValueChanged()));

    connect(ui->pbMaxTorqueApply, SIGNAL(clicked()), this, SLOT(slotValueChanged()));
    connect(ui->pbReturnLevel, SIGNAL(clicked()), this, SLOT(slotValueChanged()));

    connect(ui->pbAlarmLEDApply, SIGNAL(clicked()), this, SLOT(slotValueChanged()));
    connect(ui->pbAlarmShutdownApply, SIGNAL(clicked()), this, SLOT(slotValueChanged()));

    connect(ui->rbTEON, SIGNAL(clicked()), this, SLOT(slotValueChanged()));
    connect(ui->rbTEOFF, SIGNAL(clicked()), this, SLOT(slotValueChanged())); // TODO handle with toggle

    connect(ui->rbLEDON, SIGNAL(clicked()), this, SLOT(slotValueChanged()));
    connect(ui->rbLEDOFF, SIGNAL(clicked()), this, SLOT(slotValueChanged())); // TODO handle with toggle

    connect(ui->pbDGApply, SIGNAL(clicked()), this, SLOT(slotValueChanged()));
    connect(ui->pbIGApply, SIGNAL(clicked()), this, SLOT(slotValueChanged()));
    connect(ui->pbPGApply, SIGNAL(clicked()), this, SLOT(slotValueChanged()));

    // TODO Goal Pos Center Pos
    connect(ui->dialGoalPosition, SIGNAL(valueChanged(int)), this, SLOT(slotValueChanged()));

    connect(ui->pbMovingSpeedApply, SIGNAL(clicked()), this, SLOT(slotValueChanged()));
    connect(ui->pbTorqueLimitApply, SIGNAL(clicked()), this, SLOT(slotValueChanged()));

    connect(ui->pbLock, SIGNAL(clicked()), this, SLOT(slotValueChanged()));

    connect(ui->pbPunchApply, SIGNAL(clicked()), this, SLOT(slotValueChanged()));

    connect(ui->pbGAApply, SIGNAL(clicked()), this, SLOT(slotValueChanged()));
}

void MainWindow::data()
{
    if (ui->tawControlTable->item(0, 3))
        m_oData.set_model_number(ui->tawControlTable->item(0, 3)->text().toInt());

    if (ui->tawControlTable->item(1, 3))
        m_oData.set_firmware_version(ui->tawControlTable->item(1, 3)->text().toInt());

    m_oData.set_id(ui->cbID->currentText().toInt());
    m_oData.set_baud_rate(ui->cbBaudrate->currentText().toInt());
    m_oData.set_return_delay_time(ui->cbReturnDelayTime->currentText().toInt());
    m_oData.set_cw_angle_limit(ui->vsCWAngleLimit->value());
    m_oData.set_ccw_angle_limit(ui->vsCCWAngleLimit->value());
    m_oData.set_highest_temp_limit(ui->vsTemperatureLimit->value());
    m_oData.set_lowest_voltage_limit(ui->vsLowestVoltageLimit->value());
    m_oData.set_highest_voltage_limit(ui->vsHighestVoltageLimit->value());
    m_oData.set_max_torque(ui->vsMaxTorque->value());
    m_oData.set_status_return_level(ui->cbReturnLevel->currentIndex());
    m_oData.set_alarm_led(getAlarmLED());
    m_oData.set_alarm_shutdown(getAlarmShutdown());
    m_oData.set_torque_enable(ui->rbTEON->isChecked());
    m_oData.set_led(ui->rbLEDON->isChecked());
    m_oData.set_d_gain(ui->sbDG->value());
    m_oData.set_i_gain(ui->sbIG->value());
    m_oData.set_p_gain(ui->sbPG->value());
    m_oData.set_goal_position(ui->dialGoalPosition->value());
    m_oData.set_moving_speed(ui->vsMovingSpeed->value());
    m_oData.set_torque_limit(ui->vsTorqueLimit->value());
    m_oData.set_present_position(ui->dialPresentPosition->value());

    if (ui->tawControlTable->item(22, 3))
        m_oData.set_present_position(ui->tawControlTable->item(22, 3)->text().toInt());

    if (ui->tawControlTable->item(23, 3))
        m_oData.set_present_speed(ui->tawControlTable->item(23, 3)->text().toInt());

    if (ui->tawControlTable->item(24, 3))
        m_oData.set_present_load(ui->tawControlTable->item(24, 3)->text().toInt());

    if (ui->tawControlTable->item(25, 3))
        m_oData.set_present_voltage(ui->tawControlTable->item(25, 3)->text().toInt());

    if (ui->tawControlTable->item(22, 3))
        m_oData.set_present_temp(ui->tawControlTable->item(26, 3)->text().toInt());

    if (ui->tawControlTable->item(27, 3))
        m_oData.set_registered(ui->tawControlTable->item(27, 3)->text().toInt());

    if (ui->tawControlTable->item(28, 3))
        m_oData.set_moving(ui->tawControlTable->item(28, 3)->text().toInt());

    if (ui->tawControlTable->item(29, 3))
        m_oData.set_lock(ui->tawControlTable->item(29, 3)->text().toInt());


    m_oData.set_punch(ui->sbPunch->value());
    m_oData.set_goal_acceleration(ui->sbGoalAcceleration->value());
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

void MainWindow::connectToDynamixel(int ittyUSBPort, int iBaudRate)
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

                // Add to QList
                m_qlServoList.append(new Servo(iID, iBaudRate));

                QTreeWidgetItem* qtwiDynamixel = new QTreeWidgetItem;
                qtwiDynamixel->setText(0, "Dynamixel ID: " + QString::number(iID));
                qtwiBaudRate->addChild(qtwiDynamixel);
            }
        }
    }
}
