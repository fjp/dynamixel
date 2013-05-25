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

            /***** Check the existence of Dynamixel with specific ID *****/
            for (int iID = 0; iID < 253; ++iID)
            {
                m_pUi->lSearching->setText(QString::number(iID));
                m_pUi->proBarSearching->setValue(iID/253*100);
                m_pUi->proBarSearching->repaint();
                qApp->processEvents();  // TODO How to properly Update progressBar? (QThread?!)

                dxl_ping(iID);
                if(dxl_get_result() == COMM_RXSUCCESS)
                {
                    qDebug() << "Found Dynamixel with ID: " << iID;

//                    QTreeWidgetItem* qtwiBaudRate = new QTreeWidgetItem;
//                    qtwiBaudRate->setText(1, "Dynamixel ID: " + QString::number(iID));  // TODO setText of Item correct
//                    m_pUi->twFoundDynamixel->addTopLevelItem(qtwiBaudRate);

                    QList<QTreeWidgetItem *> items;
                    for (int i = 0; i < 10; ++i)
                        items.append(new QTreeWidgetItem((QTreeWidget*)0, QStringList(QString("item: %1").arg(i))));
                    m_pUi->twFoundDynamixel->insertTopLevelItems(0, items);
                }

            }

        }

    }




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
