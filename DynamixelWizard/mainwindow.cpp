#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QApplication>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    m_pUi(new Ui::MainWindow)
{
    m_pUi->setupUi(this);

    m_cbUSBPort = new QComboBox(this);
    m_cbUSBPort->addItem("0");

    m_pUi->mainToolBar->addWidget(m_cbUSBPort);
    m_pUi->mainToolBar->addSeparator();
    m_pUi->mainToolBar->addAction("Connect", this, SLOT(slotConnect()));
    //ui->mainToolBar->addAction()

    m_pUi->tawControlTable->resizeColumnsToContents();

    // TODO single click not working
    connect(m_pUi->trwFoundDynamixel, SIGNAL(itemActivated(QTreeWidgetItem*, int)), this, SLOT(slotDynamixelSelected(QTreeWidgetItem*, int)));
    // TODO single click not working; omit int row (second int)
    connect(m_pUi->tawControlTable, SIGNAL(cellActivated(int,int)), this, SLOT(slotSelectedControl(int,int)));

}

MainWindow::~MainWindow()
{
    delete m_pUi;
}

void MainWindow::slotConnect()
{
    const int iNumofBaudRates = 2; // TODO set to 10; implement qtableview with specific BaudRates to check
    m_pUi->swMain->setCurrentWidget(m_pUi->pageConnection);
    // qvector initializer lists not availabe in C++98
    //QVector<int> testsData { 1, 2, 10, 42, 50, 123  };
    //QVector<int> qvBaudRate(10);
    //qvBaudRate = {0, 1, 3, 4, 7, 9, 16, 34, 103, 207};
    int iBaudRate[iNumofBaudRates] = {0, 1}; //, 3, 4, 7, 9, 16, 34, 103, 207};
    int ittyUSB = m_cbUSBPort->itemData(m_cbUSBPort->currentIndex()).toInt();
    int iCommStatus;

    for (int i = 0; i < iNumofBaudRates; i++)
    {
        qDebug() << "BaudRate: " << iBaudRate[i];

        /***** Open USB2Dynamixel with current BaudRate iBaudRate *****/
        if (dxl_initialize(ittyUSB, iBaudRate[i]) == 0)
        {
            qDebug() << "Failed to open USB2Dynamixel!\n";
            qDebug() << "Press Enter key to terminate...\n";
        }
        else
        {
            qDebug() << "Succeed to open USB2Dynamixel!\n";

            QString qsBaudRate = "Baud Rate: " + QString::number(iBaudRate[i]);
            QTreeWidgetItem* qtwiBaudRate = new QTreeWidgetItem;

            if (m_pUi->trwFoundDynamixel->findItems(qsBaudRate, Qt::MatchExactly).isEmpty())
            {
                qtwiBaudRate->setText(0, qsBaudRate);
                m_pUi->trwFoundDynamixel->addTopLevelItem(qtwiBaudRate);
                QApplication::processEvents();
            }


            /***** Check the existence of Dynamixel with specific ID *****/
            for (int iID = 0; iID <= 253; ++iID)
            {
                m_pUi->lSearching->setText(QString::number(iID));
                m_pUi->proBarSearching->setValue(static_cast<int>(static_cast<double>(iID)/253*100));
                m_pUi->proBarSearching->repaint();
               // qApp->processEvents();  // TODO How to properly Update progressBar? (QThread?!)
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
}

void MainWindow::slotDynamixelSelected(QTreeWidgetItem* qtwiItem, int iColumn)
{
    qDebug() << qtwiItem << iColumn;

    m_pUi->swMain->setCurrentWidget(m_pUi->pageSettings);

    // extract ID from QString "Dynamixel ID: 1" -> .at(2)
    int iID = qtwiItem->text(0).split(" ").at(2).toInt();

    qDebug() << "Dynamixel with ID" << iID << "clicked";

    Servo servo(iID);

    m_oData = servo.receive_data();

    qDebug() << "ID:" << m_oData.id();

    m_pUi->tawControlTable->setItem(0, 3, new QTableWidgetItem(QString::number(m_oData.model_number_l())));
    m_pUi->tawControlTable->setItem(1, 3, new QTableWidgetItem(QString::number(m_oData.firmware_version())));
    m_pUi->tawControlTable->setItem(2, 3, new QTableWidgetItem(QString::number(m_oData.id()))); //TODO ID from 256 to ... instead of 0 to ...?
    m_pUi->tawControlTable->setItem(3, 3, new QTableWidgetItem(QString::number(m_oData.baud_rate())));
    m_pUi->tawControlTable->setItem(4, 3, new QTableWidgetItem(QString::number(m_oData.return_delay_time())));
    m_pUi->tawControlTable->setItem(5, 3, new QTableWidgetItem(QString::number(m_oData.cw_angle_limit_l())));
    m_pUi->tawControlTable->setItem(6, 3, new QTableWidgetItem(QString::number(m_oData.ccw_angle_limit_l())));
    m_pUi->tawControlTable->setItem(7, 3, new QTableWidgetItem(QString::number(m_oData.highest_temp_limit())));
    m_pUi->tawControlTable->setItem(8, 3, new QTableWidgetItem(QString::number(m_oData.lowest_voltage_limit())));
    m_pUi->tawControlTable->setItem(9, 3, new QTableWidgetItem(QString::number(m_oData.highest_voltage_limit())));
    m_pUi->tawControlTable->setItem(10, 3, new QTableWidgetItem(QString::number(m_oData.max_torque_l())));
    m_pUi->tawControlTable->setItem(11, 3, new QTableWidgetItem(QString::number(m_oData.status_return_level())));
    m_pUi->tawControlTable->setItem(12, 3, new QTableWidgetItem(QString::number(m_oData.alarm_led())));
    m_pUi->tawControlTable->setItem(13, 3, new QTableWidgetItem(QString::number(m_oData.alarm_shutdown())));
    m_pUi->tawControlTable->setItem(14, 3, new QTableWidgetItem(QString::number(m_oData.torque_enable())));
    m_pUi->tawControlTable->setItem(15, 3, new QTableWidgetItem(QString::number(m_oData.led())));
    m_pUi->tawControlTable->setItem(16, 3, new QTableWidgetItem(QString::number(m_oData.d_gain())));
    m_pUi->tawControlTable->setItem(17, 3, new QTableWidgetItem(QString::number(m_oData.i_gain())));
    m_pUi->tawControlTable->setItem(18, 3, new QTableWidgetItem(QString::number(m_oData.p_gain())));
    m_pUi->tawControlTable->setItem(19, 3, new QTableWidgetItem(QString::number(m_oData.goal_position_l())));
    m_pUi->tawControlTable->setItem(20, 3, new QTableWidgetItem(QString::number(m_oData.moving_speed_l())));
    m_pUi->tawControlTable->setItem(21, 3, new QTableWidgetItem(QString::number(m_oData.torque_limit_l())));
    m_pUi->tawControlTable->setItem(22, 3, new QTableWidgetItem(QString::number(m_oData.present_position_l())));
    m_pUi->tawControlTable->setItem(23, 3, new QTableWidgetItem(QString::number(m_oData.present_speed_l())));
    m_pUi->tawControlTable->setItem(24, 3, new QTableWidgetItem(QString::number(m_oData.present_load_l())));
    m_pUi->tawControlTable->setItem(25, 3, new QTableWidgetItem(QString::number(m_oData.present_voltage())));
    m_pUi->tawControlTable->setItem(26, 3, new QTableWidgetItem(QString::number(m_oData.present_temp())));
    m_pUi->tawControlTable->setItem(27, 3, new QTableWidgetItem(QString::number(m_oData.registered())));
    m_pUi->tawControlTable->setItem(28, 3, new QTableWidgetItem(QString::number(m_oData.moving())));
    m_pUi->tawControlTable->setItem(29, 3, new QTableWidgetItem(QString::number(m_oData.lock())));
    m_pUi->tawControlTable->setItem(30, 3, new QTableWidgetItem(QString::number(m_oData.punch_l())));
    m_pUi->tawControlTable->setItem(31, 3, new QTableWidgetItem(QString::number(m_oData.goal_acceleration())));


}

void MainWindow::slotSelectedControl(int row, int col)
{
    qDebug() << "Row" << row;
    qDebug() << "Column" << col;

    // TODO sort pages in StackedWidget swSelectedControl accordingly -> page Order in designer
//    switch (row)
//    {
//        case 0:
//    case 1:


//    }

//    m_pUi->swSelectedControl->setCurrentIndex(row);
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
