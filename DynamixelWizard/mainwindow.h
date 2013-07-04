#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QComboBox>
#include <QTreeWidget>
#include <QDebug>

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
     * @brief slotSelectedControl switches the Stacked Widget swSelectedControl to the selected Entry in the TableWidget tawControlTable
     */
    void slotSelectedControl(int, int);
    
private:
    Ui::MainWindow *ui;

    QComboBox* m_cbUSBPort;

    Data m_oData;

    int m_iConnection;
};

#endif // MAINWINDOW_H
