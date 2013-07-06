#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QComboBox>
#include <QTreeWidget>
#include <QDebug>
#include <QApplication>
#include <QListWidget>
#include <QList>

#include "dynamixel.h"
#include "data.h"
#include "servo.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    // Get Functions
    Data get_data() const;

    // Read all UI information and save them to the data storage
    void set_data();

    // Update UI Values // Write information to UI
    void UpdateData(Data const& coData);

    void set_connection(int const& ciConnection);

    void connectToDynamixel(int ittyUSBPort, int iBaudRate);

private slots:
    /**
     * @brief slotConnect switches the Stacked Widget swMain to the Connect Page
     */
    void slotConnect(void);


    /**
     * @brief slotStartSearching starts sending the ping command to all IDs with the specified Baud Rates
     */
    void slotStartSearching(void);


    void slotDynamixelSelected(QTreeWidgetItem*, int);

    /**
     * @brief slotValueChanged gets called if a value is changed in the StackedWidget swSelectedControl
     */
    void slotValueChanged();



    /**
     * @brief slotSelectedControl switches the Stacked Widget swSelectedControl to the selected Entry in the TableWidget tawControlTable
     */
    void slotSelectedControl(int, int);

    /**
     * @brief slotUpdateData receives Data from selected Dynamixel stored in m_iSelectedDynamixelID and updates the Values of TableWidget tawControlTable
     * and pages in swSelectedControl.
     * gets regularly called after Timer ends.
     */
    void slotUpdateData(void);
    
private:
    /**
     * @brief initStackedWidgetConnects calls the connect functions to give the diffrent pages of StackedWidget swSelectedControl functionality.
     */
    void initStackedWidgetConnects(void);

    /**
     * @brief data gets the current data set in the Ui and stores it in m_oData
     */
    void data(void);

    int getAlarmLED(void);

    int getAlarmShutdown(void);

    Ui::MainWindow *ui;

    QComboBox* m_cbUSBPort;
    int m_ittyUSBPort;

    Data m_oData;

    QList<Servo* > m_qlServoList;
    QList<int* > m_list;

    int m_iConnection;

    int m_iSelectedDynamixelID;

    int m_iSelectedAdress;
};

#endif // MAINWINDOW_H
