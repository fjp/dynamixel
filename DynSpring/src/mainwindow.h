#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "data.hpp"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

    // Return functions
    bool exit() const;
    bool power() const;
    Data data() const;

    // Read all UI information and save them to the data storage
    void UpdateData();

    // Write information to UI
    void set_data(Data const& data);
    void set_connection(int const& connection);

protected:
    void changeEvent(QEvent *e);

private:
    Ui::MainWindow *ui_;

    void setup_plot();

    bool exit_;
    bool power_;
    int connection_;

    Data data_;

    QVector<double> *time_;
    QVector<double> *force_;

private slots:
    void set_exit();
    void set_power_on_off();

};




#endif // MAINWINDOW_H
