#include <QtGui/QApplication>
#include <QDebug>

#include <QString>
#include <QFile>

#include "mainwindow.h"
#include "dynamixel.h"
#include "forcesensor.h"
#include "data.hpp"
#include "servo.hpp"

int main(int argc, char *argv[])
{
    // Kill all previous connections
    dxl_terminate();

    // Init Qt main window
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    // Var for servo init
    int baudnum = 1;
    int deviceIndex = 0;
    int id = 0;

    // Servo object
    //Servo servo(id);
    Servo servo;

    // Contains all caputred data
    Data data;
    //double load = 0.0;

    // Set connection to servo to false
    w.set_connection(0);

    bool init = true;
    bool connect = false;

    // Init force sensor
    init_readforce();

    //int time_stamp = 1;

    // MainWindow.kExit() returns true if the exit button is hit
    while(w.exit() != true) {

        // Update data in UI
        w.UpdateData();

        // Check if the power button is hit and try to establish the servo connection
        if(w.power() == true && init == true) {
            if (dxl_initialize(deviceIndex, baudnum) == 0) {
                w.set_connection(1);
            } else {
                w.set_connection(2);
                init = false;
                connect = true;
            }
            // Terminate all servo connections if the power is turned off
        } else if (w.power() == false && init == false) {
            dxl_terminate();
            w.set_connection(0);
            init = true;
            connect = false;
        }

        if(connect == true && dxl_get_rxpacket_error(ERRBIT_OVERHEAT) != 1) {

            // Get data from UI
            data = w.data();

            //qDebug() << load;

            // Write to servo
            servo.write_data(data);//, load);

            //Read data from servo
            data = servo.receive_data();

            //            load = data.present_load_l();

            data.set_force(readforce());

            // Send to UI
            w.set_data(data);


            // Save to file
            QString str = "set" + QString((int)(data.save_number()));
            //
            QFile file(str);
            file.open(QIODevice::Append | QIODevice::Text);
            //
            QTextStream out(&file);
            out << data.force() << "   " << data.present_position_l() << "\n";
            //
            file.close();


            usleep(300);

        } else if (dxl_get_rxpacket_error(ERRBIT_OVERHEAT) == 1) {
            w.set_connection(3);

        }

        a.processEvents();
    }

    // Terminate all servo connections
    dxl_terminate();

    // Terminate force sensor
    uninit_readforce();

    return 0;
}
