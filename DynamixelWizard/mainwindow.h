#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QComboBox>
#include <QDebug>

#include "dynamixel.h"
#include "data.h"

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
    void slotConnect(void);
    
private:
    Ui::MainWindow *m_pUi;

    QComboBox* m_cbUSBPort;

    Data* m_oData;

    int m_iConnection;
};

#endif // MAINWINDOW_H
