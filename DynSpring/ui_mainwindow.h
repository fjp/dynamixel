/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Fri May 24 19:50:13 2013
**      by: Qt User Interface Compiler version 4.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "../src/qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QFrame *frame;
    QGridLayout *gridLayout;
    QLabel *label_18;
    QLabel *label_23;
    QLabel *label_28;
    QSpacerItem *verticalSpacer_2;
    QLabel *label_6;
    QSpacerItem *horizontalSpacer_2;
    QSlider *hs_cw_angle_limit_l;
    QLabel *l_cw_angle_limit_l;
    QLabel *label_13;
    QSlider *hs_ccw_angle_limit_l;
    QLabel *l_ccw_angle_limit_l;
    QLabel *label_11;
    QSlider *hs_lowest_voltage_limit;
    QLabel *l_lowest_voltage_limit;
    QLabel *label_14;
    QSlider *hs_highest_voltage_limit;
    QSlider *hs_max_torque_l;
    QLabel *l_highest_voltage_limit;
    QLabel *label_44;
    QSlider *hs_torque_enable;
    QLabel *l_max_torque_l;
    QLabel *label_38;
    QSlider *hs_d_gain;
    QLabel *l_torque_enable;
    QLabel *label_43;
    QSlider *hs_i_gain;
    QLabel *l_d_gain;
    QLabel *label_45;
    QSlider *hs_p_gain;
    QLabel *l_i_gain;
    QLabel *l_p_gain;
    QLabel *label_42;
    QSlider *hs_ccw_compliance_slope;
    QLabel *label_34;
    QLabel *l_ccw_compliance_slope;
    QLabel *label_33;
    QSlider *hs_goal_pos_l;
    QLabel *l_goal_pos_l;
    QLabel *label_46;
    QSpacerItem *horizontalSpacer_4;
    QLabel *l_move_speed_l;
    QLabel *label_48;
    QSlider *hs_torque_limit_l;
    QLabel *l_torque_limit_l;
    QLabel *label_25;
    QSlider *hs_lock;
    QLabel *l_lock;
    QLabel *label_27;
    QSlider *hs_punch_l;
    QLabel *l_punch_l;
    QLabel *label_26;
    QSlider *hs_goal_acceleration;
    QLabel *l_goal_acceleration;
    QSlider *hs_move_speed_l;
    QFrame *frame_2;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridR;
    QLabel *label_19;
    QLabel *label_17;
    QLabel *label_31;
    QLabel *label_22;
    QLabel *label_29;
    QLabel *label_21;
    QLabel *label_24;
    QLabel *label_20;
    QLabel *label_16;
    QLabel *label_12;
    QLabel *l_present_speed_l;
    QLabel *l_present_speed_h;
    QLabel *l_present_load_l;
    QLabel *l_present_load_h;
    QLabel *l_present_pos_l;
    QLabel *l_present_pos_h;
    QLabel *l_present_voltage;
    QLabel *l_registered;
    QLabel *l_present_temp;
    QLabel *l_moving;
    QLabel *label_32;
    QLabel *label_30;
    QSpacerItem *verticalSpacer;
    QLabel *label_35;
    QSpacerItem *horizontalSpacer_3;
    QLabel *l_dynamixel_id;
    QFrame *frame_3;
    QPushButton *pbExit;
    QFrame *line_9;
    QSpinBox *sbNumber;
    QLabel *l_moving_2;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_36;
    QSpacerItem *horizontalSpacer;
    QSpinBox *sbID;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *le_connection;
    QLabel *lPower;
    QPushButton *pbPower;
    QFrame *f_plot;
    QCustomPlot *cp_plot;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1910, 858);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        frame = new QFrame(centralWidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(10, 10, 691, 831));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(frame);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_18 = new QLabel(frame);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        QFont font;
        font.setFamily(QString::fromUtf8("Bitstream Charter"));
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        label_18->setFont(font);
        label_18->setLayoutDirection(Qt::LeftToRight);
        label_18->setTextFormat(Qt::AutoText);
        label_18->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_18, 0, 0, 1, 1);

        label_23 = new QLabel(frame);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setFont(font);
        label_23->setLayoutDirection(Qt::LeftToRight);
        label_23->setTextFormat(Qt::AutoText);
        label_23->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_23, 0, 2, 1, 1);

        label_28 = new QLabel(frame);
        label_28->setObjectName(QString::fromUtf8("label_28"));
        label_28->setFont(font);
        label_28->setLayoutDirection(Qt::LeftToRight);
        label_28->setTextFormat(Qt::AutoText);
        label_28->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_28, 0, 4, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 13, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer_2, 1, 2, 1, 1);

        label_6 = new QLabel(frame);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Bitstream Charter"));
        font1.setPointSize(12);
        label_6->setFont(font1);
        label_6->setLayoutDirection(Qt::RightToLeft);

        gridLayout->addWidget(label_6, 2, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 2, 1, 1, 1);

        hs_cw_angle_limit_l = new QSlider(frame);
        hs_cw_angle_limit_l->setObjectName(QString::fromUtf8("hs_cw_angle_limit_l"));
        hs_cw_angle_limit_l->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(hs_cw_angle_limit_l->sizePolicy().hasHeightForWidth());
        hs_cw_angle_limit_l->setSizePolicy(sizePolicy);
        hs_cw_angle_limit_l->setMaximum(4095);
        hs_cw_angle_limit_l->setValue(800);
        hs_cw_angle_limit_l->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(hs_cw_angle_limit_l, 2, 2, 1, 1);

        l_cw_angle_limit_l = new QLabel(frame);
        l_cw_angle_limit_l->setObjectName(QString::fromUtf8("l_cw_angle_limit_l"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(l_cw_angle_limit_l->sizePolicy().hasHeightForWidth());
        l_cw_angle_limit_l->setSizePolicy(sizePolicy1);
        l_cw_angle_limit_l->setMinimumSize(QSize(37, 20));
        l_cw_angle_limit_l->setFont(font1);

        gridLayout->addWidget(l_cw_angle_limit_l, 2, 4, 1, 1);

        label_13 = new QLabel(frame);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setFont(font1);
        label_13->setLayoutDirection(Qt::RightToLeft);

        gridLayout->addWidget(label_13, 3, 0, 1, 1);

        hs_ccw_angle_limit_l = new QSlider(frame);
        hs_ccw_angle_limit_l->setObjectName(QString::fromUtf8("hs_ccw_angle_limit_l"));
        hs_ccw_angle_limit_l->setEnabled(true);
        sizePolicy.setHeightForWidth(hs_ccw_angle_limit_l->sizePolicy().hasHeightForWidth());
        hs_ccw_angle_limit_l->setSizePolicy(sizePolicy);
        hs_ccw_angle_limit_l->setMaximum(4095);
        hs_ccw_angle_limit_l->setValue(3248);
        hs_ccw_angle_limit_l->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(hs_ccw_angle_limit_l, 3, 2, 1, 1);

        l_ccw_angle_limit_l = new QLabel(frame);
        l_ccw_angle_limit_l->setObjectName(QString::fromUtf8("l_ccw_angle_limit_l"));
        sizePolicy1.setHeightForWidth(l_ccw_angle_limit_l->sizePolicy().hasHeightForWidth());
        l_ccw_angle_limit_l->setSizePolicy(sizePolicy1);
        l_ccw_angle_limit_l->setMinimumSize(QSize(37, 20));
        l_ccw_angle_limit_l->setFont(font1);

        gridLayout->addWidget(l_ccw_angle_limit_l, 3, 4, 1, 1);

        label_11 = new QLabel(frame);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setFont(font1);
        label_11->setLayoutDirection(Qt::RightToLeft);

        gridLayout->addWidget(label_11, 4, 0, 1, 1);

        hs_lowest_voltage_limit = new QSlider(frame);
        hs_lowest_voltage_limit->setObjectName(QString::fromUtf8("hs_lowest_voltage_limit"));
        hs_lowest_voltage_limit->setEnabled(true);
        sizePolicy.setHeightForWidth(hs_lowest_voltage_limit->sizePolicy().hasHeightForWidth());
        hs_lowest_voltage_limit->setSizePolicy(sizePolicy);
        hs_lowest_voltage_limit->setMinimum(50);
        hs_lowest_voltage_limit->setMaximum(250);
        hs_lowest_voltage_limit->setValue(60);
        hs_lowest_voltage_limit->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(hs_lowest_voltage_limit, 4, 2, 1, 1);

        l_lowest_voltage_limit = new QLabel(frame);
        l_lowest_voltage_limit->setObjectName(QString::fromUtf8("l_lowest_voltage_limit"));
        sizePolicy1.setHeightForWidth(l_lowest_voltage_limit->sizePolicy().hasHeightForWidth());
        l_lowest_voltage_limit->setSizePolicy(sizePolicy1);
        l_lowest_voltage_limit->setMinimumSize(QSize(37, 20));
        l_lowest_voltage_limit->setFont(font1);

        gridLayout->addWidget(l_lowest_voltage_limit, 4, 4, 1, 1);

        label_14 = new QLabel(frame);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setFont(font1);
        label_14->setLayoutDirection(Qt::RightToLeft);

        gridLayout->addWidget(label_14, 5, 0, 1, 1);

        hs_highest_voltage_limit = new QSlider(frame);
        hs_highest_voltage_limit->setObjectName(QString::fromUtf8("hs_highest_voltage_limit"));
        hs_highest_voltage_limit->setEnabled(true);
        sizePolicy.setHeightForWidth(hs_highest_voltage_limit->sizePolicy().hasHeightForWidth());
        hs_highest_voltage_limit->setSizePolicy(sizePolicy);
        hs_highest_voltage_limit->setMinimum(50);
        hs_highest_voltage_limit->setMaximum(250);
        hs_highest_voltage_limit->setValue(140);
        hs_highest_voltage_limit->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(hs_highest_voltage_limit, 5, 2, 1, 1);

        hs_max_torque_l = new QSlider(frame);
        hs_max_torque_l->setObjectName(QString::fromUtf8("hs_max_torque_l"));
        hs_max_torque_l->setEnabled(true);
        sizePolicy.setHeightForWidth(hs_max_torque_l->sizePolicy().hasHeightForWidth());
        hs_max_torque_l->setSizePolicy(sizePolicy);
        hs_max_torque_l->setMaximum(1023);
        hs_max_torque_l->setValue(1023);
        hs_max_torque_l->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(hs_max_torque_l, 6, 2, 1, 1);

        l_highest_voltage_limit = new QLabel(frame);
        l_highest_voltage_limit->setObjectName(QString::fromUtf8("l_highest_voltage_limit"));
        sizePolicy1.setHeightForWidth(l_highest_voltage_limit->sizePolicy().hasHeightForWidth());
        l_highest_voltage_limit->setSizePolicy(sizePolicy1);
        l_highest_voltage_limit->setMinimumSize(QSize(37, 20));
        l_highest_voltage_limit->setFont(font1);

        gridLayout->addWidget(l_highest_voltage_limit, 5, 4, 1, 1);

        label_44 = new QLabel(frame);
        label_44->setObjectName(QString::fromUtf8("label_44"));
        label_44->setFont(font1);
        label_44->setLayoutDirection(Qt::RightToLeft);

        gridLayout->addWidget(label_44, 6, 0, 1, 1);

        hs_torque_enable = new QSlider(frame);
        hs_torque_enable->setObjectName(QString::fromUtf8("hs_torque_enable"));
        sizePolicy.setHeightForWidth(hs_torque_enable->sizePolicy().hasHeightForWidth());
        hs_torque_enable->setSizePolicy(sizePolicy);
        hs_torque_enable->setMaximum(1);
        hs_torque_enable->setValue(1);
        hs_torque_enable->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(hs_torque_enable, 7, 2, 1, 1);

        l_max_torque_l = new QLabel(frame);
        l_max_torque_l->setObjectName(QString::fromUtf8("l_max_torque_l"));
        sizePolicy1.setHeightForWidth(l_max_torque_l->sizePolicy().hasHeightForWidth());
        l_max_torque_l->setSizePolicy(sizePolicy1);
        l_max_torque_l->setMinimumSize(QSize(37, 20));
        l_max_torque_l->setFont(font1);

        gridLayout->addWidget(l_max_torque_l, 6, 4, 1, 1);

        label_38 = new QLabel(frame);
        label_38->setObjectName(QString::fromUtf8("label_38"));
        label_38->setFont(font1);
        label_38->setLayoutDirection(Qt::RightToLeft);

        gridLayout->addWidget(label_38, 7, 0, 1, 1);

        hs_d_gain = new QSlider(frame);
        hs_d_gain->setObjectName(QString::fromUtf8("hs_d_gain"));
        sizePolicy.setHeightForWidth(hs_d_gain->sizePolicy().hasHeightForWidth());
        hs_d_gain->setSizePolicy(sizePolicy);
        hs_d_gain->setMaximum(255);
        hs_d_gain->setValue(10);
        hs_d_gain->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(hs_d_gain, 8, 2, 1, 1);

        l_torque_enable = new QLabel(frame);
        l_torque_enable->setObjectName(QString::fromUtf8("l_torque_enable"));
        sizePolicy1.setHeightForWidth(l_torque_enable->sizePolicy().hasHeightForWidth());
        l_torque_enable->setSizePolicy(sizePolicy1);
        l_torque_enable->setMinimumSize(QSize(37, 20));
        l_torque_enable->setFont(font1);

        gridLayout->addWidget(l_torque_enable, 7, 4, 1, 1);

        label_43 = new QLabel(frame);
        label_43->setObjectName(QString::fromUtf8("label_43"));
        label_43->setFont(font1);
        label_43->setLayoutDirection(Qt::RightToLeft);

        gridLayout->addWidget(label_43, 8, 0, 1, 1);

        hs_i_gain = new QSlider(frame);
        hs_i_gain->setObjectName(QString::fromUtf8("hs_i_gain"));
        sizePolicy.setHeightForWidth(hs_i_gain->sizePolicy().hasHeightForWidth());
        hs_i_gain->setSizePolicy(sizePolicy);
        hs_i_gain->setMaximum(255);
        hs_i_gain->setValue(0);
        hs_i_gain->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(hs_i_gain, 9, 2, 1, 1);

        l_d_gain = new QLabel(frame);
        l_d_gain->setObjectName(QString::fromUtf8("l_d_gain"));
        sizePolicy1.setHeightForWidth(l_d_gain->sizePolicy().hasHeightForWidth());
        l_d_gain->setSizePolicy(sizePolicy1);
        l_d_gain->setMinimumSize(QSize(37, 20));
        l_d_gain->setFont(font1);

        gridLayout->addWidget(l_d_gain, 8, 4, 1, 1);

        label_45 = new QLabel(frame);
        label_45->setObjectName(QString::fromUtf8("label_45"));
        label_45->setFont(font1);
        label_45->setLayoutDirection(Qt::RightToLeft);

        gridLayout->addWidget(label_45, 9, 0, 1, 1);

        hs_p_gain = new QSlider(frame);
        hs_p_gain->setObjectName(QString::fromUtf8("hs_p_gain"));
        sizePolicy.setHeightForWidth(hs_p_gain->sizePolicy().hasHeightForWidth());
        hs_p_gain->setSizePolicy(sizePolicy);
        hs_p_gain->setMaximum(255);
        hs_p_gain->setValue(60);
        hs_p_gain->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(hs_p_gain, 10, 2, 1, 1);

        l_i_gain = new QLabel(frame);
        l_i_gain->setObjectName(QString::fromUtf8("l_i_gain"));
        sizePolicy1.setHeightForWidth(l_i_gain->sizePolicy().hasHeightForWidth());
        l_i_gain->setSizePolicy(sizePolicy1);
        l_i_gain->setMinimumSize(QSize(37, 20));
        l_i_gain->setFont(font1);

        gridLayout->addWidget(l_i_gain, 9, 4, 1, 1);

        l_p_gain = new QLabel(frame);
        l_p_gain->setObjectName(QString::fromUtf8("l_p_gain"));
        sizePolicy1.setHeightForWidth(l_p_gain->sizePolicy().hasHeightForWidth());
        l_p_gain->setSizePolicy(sizePolicy1);
        l_p_gain->setMinimumSize(QSize(37, 20));
        l_p_gain->setFont(font1);

        gridLayout->addWidget(l_p_gain, 10, 4, 1, 1);

        label_42 = new QLabel(frame);
        label_42->setObjectName(QString::fromUtf8("label_42"));
        label_42->setFont(font1);
        label_42->setLayoutDirection(Qt::RightToLeft);

        gridLayout->addWidget(label_42, 10, 0, 1, 1);

        hs_ccw_compliance_slope = new QSlider(frame);
        hs_ccw_compliance_slope->setObjectName(QString::fromUtf8("hs_ccw_compliance_slope"));
        hs_ccw_compliance_slope->setEnabled(false);
        sizePolicy.setHeightForWidth(hs_ccw_compliance_slope->sizePolicy().hasHeightForWidth());
        hs_ccw_compliance_slope->setSizePolicy(sizePolicy);
        hs_ccw_compliance_slope->setMaximum(255);
        hs_ccw_compliance_slope->setValue(32);
        hs_ccw_compliance_slope->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(hs_ccw_compliance_slope, 11, 2, 1, 1);

        label_34 = new QLabel(frame);
        label_34->setObjectName(QString::fromUtf8("label_34"));
        label_34->setFont(font1);
        label_34->setLayoutDirection(Qt::RightToLeft);

        gridLayout->addWidget(label_34, 11, 0, 1, 1);

        l_ccw_compliance_slope = new QLabel(frame);
        l_ccw_compliance_slope->setObjectName(QString::fromUtf8("l_ccw_compliance_slope"));
        sizePolicy1.setHeightForWidth(l_ccw_compliance_slope->sizePolicy().hasHeightForWidth());
        l_ccw_compliance_slope->setSizePolicy(sizePolicy1);
        l_ccw_compliance_slope->setMinimumSize(QSize(37, 20));
        l_ccw_compliance_slope->setFont(font1);

        gridLayout->addWidget(l_ccw_compliance_slope, 11, 4, 1, 1);

        label_33 = new QLabel(frame);
        label_33->setObjectName(QString::fromUtf8("label_33"));
        label_33->setFont(font1);
        label_33->setLayoutDirection(Qt::RightToLeft);

        gridLayout->addWidget(label_33, 12, 0, 1, 1);

        hs_goal_pos_l = new QSlider(frame);
        hs_goal_pos_l->setObjectName(QString::fromUtf8("hs_goal_pos_l"));
        sizePolicy.setHeightForWidth(hs_goal_pos_l->sizePolicy().hasHeightForWidth());
        hs_goal_pos_l->setSizePolicy(sizePolicy);
        hs_goal_pos_l->setMinimum(0);
        hs_goal_pos_l->setMaximum(4095);
        hs_goal_pos_l->setValue(2048);
        hs_goal_pos_l->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(hs_goal_pos_l, 12, 2, 1, 1);

        l_goal_pos_l = new QLabel(frame);
        l_goal_pos_l->setObjectName(QString::fromUtf8("l_goal_pos_l"));
        sizePolicy1.setHeightForWidth(l_goal_pos_l->sizePolicy().hasHeightForWidth());
        l_goal_pos_l->setSizePolicy(sizePolicy1);
        l_goal_pos_l->setMinimumSize(QSize(37, 20));
        l_goal_pos_l->setFont(font1);

        gridLayout->addWidget(l_goal_pos_l, 12, 4, 1, 1);

        label_46 = new QLabel(frame);
        label_46->setObjectName(QString::fromUtf8("label_46"));
        label_46->setFont(font1);
        label_46->setLayoutDirection(Qt::RightToLeft);

        gridLayout->addWidget(label_46, 13, 0, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 12, 3, 1, 1);

        l_move_speed_l = new QLabel(frame);
        l_move_speed_l->setObjectName(QString::fromUtf8("l_move_speed_l"));
        sizePolicy1.setHeightForWidth(l_move_speed_l->sizePolicy().hasHeightForWidth());
        l_move_speed_l->setSizePolicy(sizePolicy1);
        l_move_speed_l->setMinimumSize(QSize(37, 20));
        l_move_speed_l->setFont(font1);

        gridLayout->addWidget(l_move_speed_l, 13, 4, 1, 1);

        label_48 = new QLabel(frame);
        label_48->setObjectName(QString::fromUtf8("label_48"));
        label_48->setFont(font1);
        label_48->setLayoutDirection(Qt::RightToLeft);

        gridLayout->addWidget(label_48, 14, 0, 1, 1);

        hs_torque_limit_l = new QSlider(frame);
        hs_torque_limit_l->setObjectName(QString::fromUtf8("hs_torque_limit_l"));
        sizePolicy.setHeightForWidth(hs_torque_limit_l->sizePolicy().hasHeightForWidth());
        hs_torque_limit_l->setSizePolicy(sizePolicy);
        hs_torque_limit_l->setMinimum(0);
        hs_torque_limit_l->setMaximum(1023);
        hs_torque_limit_l->setValue(1023);
        hs_torque_limit_l->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(hs_torque_limit_l, 14, 2, 1, 1);

        l_torque_limit_l = new QLabel(frame);
        l_torque_limit_l->setObjectName(QString::fromUtf8("l_torque_limit_l"));
        sizePolicy1.setHeightForWidth(l_torque_limit_l->sizePolicy().hasHeightForWidth());
        l_torque_limit_l->setSizePolicy(sizePolicy1);
        l_torque_limit_l->setMinimumSize(QSize(37, 20));
        l_torque_limit_l->setFont(font1);

        gridLayout->addWidget(l_torque_limit_l, 14, 4, 1, 1);

        label_25 = new QLabel(frame);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        label_25->setFont(font1);
        label_25->setLayoutDirection(Qt::RightToLeft);

        gridLayout->addWidget(label_25, 15, 0, 1, 1);

        hs_lock = new QSlider(frame);
        hs_lock->setObjectName(QString::fromUtf8("hs_lock"));
        hs_lock->setEnabled(false);
        sizePolicy.setHeightForWidth(hs_lock->sizePolicy().hasHeightForWidth());
        hs_lock->setSizePolicy(sizePolicy);
        hs_lock->setMaximum(1);
        hs_lock->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(hs_lock, 15, 2, 1, 1);

        l_lock = new QLabel(frame);
        l_lock->setObjectName(QString::fromUtf8("l_lock"));
        sizePolicy1.setHeightForWidth(l_lock->sizePolicy().hasHeightForWidth());
        l_lock->setSizePolicy(sizePolicy1);
        l_lock->setMinimumSize(QSize(37, 20));
        l_lock->setFont(font1);

        gridLayout->addWidget(l_lock, 15, 4, 1, 1);

        label_27 = new QLabel(frame);
        label_27->setObjectName(QString::fromUtf8("label_27"));
        label_27->setFont(font1);
        label_27->setLayoutDirection(Qt::RightToLeft);

        gridLayout->addWidget(label_27, 16, 0, 1, 1);

        hs_punch_l = new QSlider(frame);
        hs_punch_l->setObjectName(QString::fromUtf8("hs_punch_l"));
        sizePolicy.setHeightForWidth(hs_punch_l->sizePolicy().hasHeightForWidth());
        hs_punch_l->setSizePolicy(sizePolicy);
        hs_punch_l->setMinimum(32);
        hs_punch_l->setMaximum(1023);
        hs_punch_l->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(hs_punch_l, 16, 2, 1, 1);

        l_punch_l = new QLabel(frame);
        l_punch_l->setObjectName(QString::fromUtf8("l_punch_l"));
        sizePolicy1.setHeightForWidth(l_punch_l->sizePolicy().hasHeightForWidth());
        l_punch_l->setSizePolicy(sizePolicy1);
        l_punch_l->setMinimumSize(QSize(37, 20));
        l_punch_l->setFont(font1);

        gridLayout->addWidget(l_punch_l, 16, 4, 1, 1);

        label_26 = new QLabel(frame);
        label_26->setObjectName(QString::fromUtf8("label_26"));
        label_26->setFont(font1);
        label_26->setLayoutDirection(Qt::RightToLeft);

        gridLayout->addWidget(label_26, 17, 0, 1, 1);

        hs_goal_acceleration = new QSlider(frame);
        hs_goal_acceleration->setObjectName(QString::fromUtf8("hs_goal_acceleration"));
        sizePolicy.setHeightForWidth(hs_goal_acceleration->sizePolicy().hasHeightForWidth());
        hs_goal_acceleration->setSizePolicy(sizePolicy);
        hs_goal_acceleration->setMinimum(0);
        hs_goal_acceleration->setMaximum(1023);
        hs_goal_acceleration->setValue(0);
        hs_goal_acceleration->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(hs_goal_acceleration, 17, 2, 1, 1);

        l_goal_acceleration = new QLabel(frame);
        l_goal_acceleration->setObjectName(QString::fromUtf8("l_goal_acceleration"));
        sizePolicy1.setHeightForWidth(l_goal_acceleration->sizePolicy().hasHeightForWidth());
        l_goal_acceleration->setSizePolicy(sizePolicy1);
        l_goal_acceleration->setMinimumSize(QSize(37, 20));
        l_goal_acceleration->setFont(font1);

        gridLayout->addWidget(l_goal_acceleration, 17, 4, 1, 1);

        hs_move_speed_l = new QSlider(frame);
        hs_move_speed_l->setObjectName(QString::fromUtf8("hs_move_speed_l"));
        sizePolicy.setHeightForWidth(hs_move_speed_l->sizePolicy().hasHeightForWidth());
        hs_move_speed_l->setSizePolicy(sizePolicy);
        hs_move_speed_l->setMaximum(1023);
        hs_move_speed_l->setValue(1023);
        hs_move_speed_l->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(hs_move_speed_l, 13, 2, 1, 1);

        frame_2 = new QFrame(centralWidget);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setGeometry(QRect(720, 10, 361, 361));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        gridLayoutWidget_2 = new QWidget(frame_2);
        gridLayoutWidget_2->setObjectName(QString::fromUtf8("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(10, 10, 341, 338));
        gridR = new QGridLayout(gridLayoutWidget_2);
        gridR->setSpacing(6);
        gridR->setContentsMargins(11, 11, 11, 11);
        gridR->setObjectName(QString::fromUtf8("gridR"));
        gridR->setContentsMargins(0, 0, 0, 0);
        label_19 = new QLabel(gridLayoutWidget_2);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setFont(font1);
        label_19->setLayoutDirection(Qt::RightToLeft);

        gridR->addWidget(label_19, 4, 0, 1, 1);

        label_17 = new QLabel(gridLayoutWidget_2);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setFont(font1);
        label_17->setLayoutDirection(Qt::RightToLeft);

        gridR->addWidget(label_17, 5, 0, 1, 1);

        label_31 = new QLabel(gridLayoutWidget_2);
        label_31->setObjectName(QString::fromUtf8("label_31"));
        label_31->setFont(font1);
        label_31->setLayoutDirection(Qt::RightToLeft);

        gridR->addWidget(label_31, 6, 0, 1, 1);

        label_22 = new QLabel(gridLayoutWidget_2);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setFont(font1);
        label_22->setLayoutDirection(Qt::RightToLeft);

        gridR->addWidget(label_22, 7, 0, 1, 1);

        label_29 = new QLabel(gridLayoutWidget_2);
        label_29->setObjectName(QString::fromUtf8("label_29"));
        label_29->setFont(font1);
        label_29->setLayoutDirection(Qt::RightToLeft);

        gridR->addWidget(label_29, 10, 0, 1, 1);

        label_21 = new QLabel(gridLayoutWidget_2);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setFont(font1);
        label_21->setLayoutDirection(Qt::RightToLeft);

        gridR->addWidget(label_21, 11, 0, 1, 1);

        label_24 = new QLabel(gridLayoutWidget_2);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setFont(font1);
        label_24->setLayoutDirection(Qt::RightToLeft);

        gridR->addWidget(label_24, 12, 0, 1, 1);

        label_20 = new QLabel(gridLayoutWidget_2);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setFont(font1);
        label_20->setLayoutDirection(Qt::RightToLeft);

        gridR->addWidget(label_20, 13, 0, 1, 1);

        label_16 = new QLabel(gridLayoutWidget_2);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setFont(font1);
        label_16->setLayoutDirection(Qt::RightToLeft);

        gridR->addWidget(label_16, 9, 0, 1, 1);

        label_12 = new QLabel(gridLayoutWidget_2);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setFont(font1);
        label_12->setLayoutDirection(Qt::RightToLeft);

        gridR->addWidget(label_12, 8, 0, 1, 1);

        l_present_speed_l = new QLabel(gridLayoutWidget_2);
        l_present_speed_l->setObjectName(QString::fromUtf8("l_present_speed_l"));
        sizePolicy1.setHeightForWidth(l_present_speed_l->sizePolicy().hasHeightForWidth());
        l_present_speed_l->setSizePolicy(sizePolicy1);
        l_present_speed_l->setMinimumSize(QSize(37, 20));
        l_present_speed_l->setFont(font1);

        gridR->addWidget(l_present_speed_l, 4, 2, 1, 1);

        l_present_speed_h = new QLabel(gridLayoutWidget_2);
        l_present_speed_h->setObjectName(QString::fromUtf8("l_present_speed_h"));
        sizePolicy1.setHeightForWidth(l_present_speed_h->sizePolicy().hasHeightForWidth());
        l_present_speed_h->setSizePolicy(sizePolicy1);
        l_present_speed_h->setMinimumSize(QSize(37, 20));
        l_present_speed_h->setFont(font1);

        gridR->addWidget(l_present_speed_h, 5, 2, 1, 1);

        l_present_load_l = new QLabel(gridLayoutWidget_2);
        l_present_load_l->setObjectName(QString::fromUtf8("l_present_load_l"));
        sizePolicy1.setHeightForWidth(l_present_load_l->sizePolicy().hasHeightForWidth());
        l_present_load_l->setSizePolicy(sizePolicy1);
        l_present_load_l->setMinimumSize(QSize(37, 20));
        l_present_load_l->setFont(font1);

        gridR->addWidget(l_present_load_l, 6, 2, 1, 1);

        l_present_load_h = new QLabel(gridLayoutWidget_2);
        l_present_load_h->setObjectName(QString::fromUtf8("l_present_load_h"));
        sizePolicy1.setHeightForWidth(l_present_load_h->sizePolicy().hasHeightForWidth());
        l_present_load_h->setSizePolicy(sizePolicy1);
        l_present_load_h->setMinimumSize(QSize(37, 20));
        l_present_load_h->setFont(font1);

        gridR->addWidget(l_present_load_h, 7, 2, 1, 1);

        l_present_pos_l = new QLabel(gridLayoutWidget_2);
        l_present_pos_l->setObjectName(QString::fromUtf8("l_present_pos_l"));
        sizePolicy1.setHeightForWidth(l_present_pos_l->sizePolicy().hasHeightForWidth());
        l_present_pos_l->setSizePolicy(sizePolicy1);
        l_present_pos_l->setMinimumSize(QSize(37, 20));
        l_present_pos_l->setFont(font1);

        gridR->addWidget(l_present_pos_l, 8, 2, 1, 1);

        l_present_pos_h = new QLabel(gridLayoutWidget_2);
        l_present_pos_h->setObjectName(QString::fromUtf8("l_present_pos_h"));
        sizePolicy1.setHeightForWidth(l_present_pos_h->sizePolicy().hasHeightForWidth());
        l_present_pos_h->setSizePolicy(sizePolicy1);
        l_present_pos_h->setMinimumSize(QSize(37, 20));
        l_present_pos_h->setFont(font1);

        gridR->addWidget(l_present_pos_h, 9, 2, 1, 1);

        l_present_voltage = new QLabel(gridLayoutWidget_2);
        l_present_voltage->setObjectName(QString::fromUtf8("l_present_voltage"));
        sizePolicy1.setHeightForWidth(l_present_voltage->sizePolicy().hasHeightForWidth());
        l_present_voltage->setSizePolicy(sizePolicy1);
        l_present_voltage->setMinimumSize(QSize(37, 20));
        l_present_voltage->setFont(font1);

        gridR->addWidget(l_present_voltage, 10, 2, 1, 1);

        l_registered = new QLabel(gridLayoutWidget_2);
        l_registered->setObjectName(QString::fromUtf8("l_registered"));
        sizePolicy1.setHeightForWidth(l_registered->sizePolicy().hasHeightForWidth());
        l_registered->setSizePolicy(sizePolicy1);
        l_registered->setMinimumSize(QSize(37, 20));
        l_registered->setFont(font1);

        gridR->addWidget(l_registered, 11, 2, 1, 1);

        l_present_temp = new QLabel(gridLayoutWidget_2);
        l_present_temp->setObjectName(QString::fromUtf8("l_present_temp"));
        sizePolicy1.setHeightForWidth(l_present_temp->sizePolicy().hasHeightForWidth());
        l_present_temp->setSizePolicy(sizePolicy1);
        l_present_temp->setMinimumSize(QSize(37, 20));
        l_present_temp->setFont(font1);

        gridR->addWidget(l_present_temp, 12, 2, 1, 1);

        l_moving = new QLabel(gridLayoutWidget_2);
        l_moving->setObjectName(QString::fromUtf8("l_moving"));
        sizePolicy1.setHeightForWidth(l_moving->sizePolicy().hasHeightForWidth());
        l_moving->setSizePolicy(sizePolicy1);
        l_moving->setMinimumSize(QSize(37, 20));
        l_moving->setFont(font1);

        gridR->addWidget(l_moving, 13, 2, 1, 1);

        label_32 = new QLabel(gridLayoutWidget_2);
        label_32->setObjectName(QString::fromUtf8("label_32"));
        sizePolicy1.setHeightForWidth(label_32->sizePolicy().hasHeightForWidth());
        label_32->setSizePolicy(sizePolicy1);
        label_32->setMinimumSize(QSize(214, 30));
        label_32->setFont(font);
        label_32->setLayoutDirection(Qt::LeftToRight);
        label_32->setTextFormat(Qt::AutoText);
        label_32->setAlignment(Qt::AlignCenter);

        gridR->addWidget(label_32, 1, 0, 1, 1);

        label_30 = new QLabel(gridLayoutWidget_2);
        label_30->setObjectName(QString::fromUtf8("label_30"));
        label_30->setFont(font);
        label_30->setLayoutDirection(Qt::LeftToRight);
        label_30->setTextFormat(Qt::AutoText);
        label_30->setAlignment(Qt::AlignCenter);

        gridR->addWidget(label_30, 1, 2, 1, 1);

        verticalSpacer = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridR->addItem(verticalSpacer, 2, 0, 1, 1);

        label_35 = new QLabel(gridLayoutWidget_2);
        label_35->setObjectName(QString::fromUtf8("label_35"));
        label_35->setFont(font1);
        label_35->setLayoutDirection(Qt::RightToLeft);

        gridR->addWidget(label_35, 3, 0, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridR->addItem(horizontalSpacer_3, 3, 1, 1, 1);

        l_dynamixel_id = new QLabel(gridLayoutWidget_2);
        l_dynamixel_id->setObjectName(QString::fromUtf8("l_dynamixel_id"));
        sizePolicy1.setHeightForWidth(l_dynamixel_id->sizePolicy().hasHeightForWidth());
        l_dynamixel_id->setSizePolicy(sizePolicy1);
        l_dynamixel_id->setMinimumSize(QSize(37, 20));
        l_dynamixel_id->setFont(font1);

        gridR->addWidget(l_dynamixel_id, 3, 2, 1, 1);

        frame_3 = new QFrame(centralWidget);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setGeometry(QRect(720, 380, 361, 141));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        pbExit = new QPushButton(frame_3);
        pbExit->setObjectName(QString::fromUtf8("pbExit"));
        pbExit->setGeometry(QRect(270, 100, 85, 30));
        pbExit->setFont(font1);
        line_9 = new QFrame(frame_3);
        line_9->setObjectName(QString::fromUtf8("line_9"));
        line_9->setGeometry(QRect(-10, 80, 381, 20));
        line_9->setFrameShape(QFrame::HLine);
        line_9->setFrameShadow(QFrame::Sunken);
        sbNumber = new QSpinBox(frame_3);
        sbNumber->setObjectName(QString::fromUtf8("sbNumber"));
        sbNumber->setGeometry(QRect(20, 100, 55, 28));
        l_moving_2 = new QLabel(frame_3);
        l_moving_2->setObjectName(QString::fromUtf8("l_moving_2"));
        l_moving_2->setGeometry(QRect(96, 60, 61, 20));
        sizePolicy1.setHeightForWidth(l_moving_2->sizePolicy().hasHeightForWidth());
        l_moving_2->setSizePolicy(sizePolicy1);
        l_moving_2->setMinimumSize(QSize(37, 20));
        l_moving_2->setFont(font1);
        widget = new QWidget(frame_3);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 10, 341, 67));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_36 = new QLabel(widget);
        label_36->setObjectName(QString::fromUtf8("label_36"));
        label_36->setFont(font1);
        label_36->setLayoutDirection(Qt::RightToLeft);

        horizontalLayout->addWidget(label_36);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        sbID = new QSpinBox(widget);
        sbID->setObjectName(QString::fromUtf8("sbID"));
        sbID->setMaximum(254);

        horizontalLayout->addWidget(sbID);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        le_connection = new QLineEdit(widget);
        le_connection->setObjectName(QString::fromUtf8("le_connection"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(235);
        sizePolicy2.setVerticalStretch(27);
        sizePolicy2.setHeightForWidth(le_connection->sizePolicy().hasHeightForWidth());
        le_connection->setSizePolicy(sizePolicy2);

        horizontalLayout_2->addWidget(le_connection);

        lPower = new QLabel(widget);
        lPower->setObjectName(QString::fromUtf8("lPower"));
        lPower->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 0, 0);"));
        lPower->setScaledContents(false);

        horizontalLayout_2->addWidget(lPower);

        pbPower = new QPushButton(widget);
        pbPower->setObjectName(QString::fromUtf8("pbPower"));
        pbPower->setFont(font1);

        horizontalLayout_2->addWidget(pbPower);


        verticalLayout->addLayout(horizontalLayout_2);

        f_plot = new QFrame(centralWidget);
        f_plot->setObjectName(QString::fromUtf8("f_plot"));
        f_plot->setGeometry(QRect(1100, 10, 791, 471));
        f_plot->setFrameShape(QFrame::StyledPanel);
        f_plot->setFrameShadow(QFrame::Raised);
        cp_plot = new QCustomPlot(f_plot);
        cp_plot->setObjectName(QString::fromUtf8("cp_plot"));
        cp_plot->setGeometry(QRect(10, 10, 771, 451));
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        label_18->setText(QApplication::translate("MainWindow", "Name", 0, QApplication::UnicodeUTF8));
        label_23->setText(QApplication::translate("MainWindow", "Set Value", 0, QApplication::UnicodeUTF8));
        label_28->setText(QApplication::translate("MainWindow", "Value", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("MainWindow", "CW Angle Limit Lowest Byte", 0, QApplication::UnicodeUTF8));
        l_cw_angle_limit_l->setText(QApplication::translate("MainWindow", "1337", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("MainWindow", "CCW Angle Limit Lowest Byte", 0, QApplication::UnicodeUTF8));
        l_ccw_angle_limit_l->setText(QApplication::translate("MainWindow", "1337", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("MainWindow", "Lowest Voltage Limit", 0, QApplication::UnicodeUTF8));
        l_lowest_voltage_limit->setText(QApplication::translate("MainWindow", "1337", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("MainWindow", "Highest Voltage Limit", 0, QApplication::UnicodeUTF8));
        l_highest_voltage_limit->setText(QApplication::translate("MainWindow", "1337", 0, QApplication::UnicodeUTF8));
        label_44->setText(QApplication::translate("MainWindow", "Max. Torque", 0, QApplication::UnicodeUTF8));
        l_max_torque_l->setText(QApplication::translate("MainWindow", "1337", 0, QApplication::UnicodeUTF8));
        label_38->setText(QApplication::translate("MainWindow", "Torque Enable", 0, QApplication::UnicodeUTF8));
        l_torque_enable->setText(QApplication::translate("MainWindow", "1337", 0, QApplication::UnicodeUTF8));
        label_43->setText(QApplication::translate("MainWindow", "D Gain", 0, QApplication::UnicodeUTF8));
        l_d_gain->setText(QApplication::translate("MainWindow", "1337", 0, QApplication::UnicodeUTF8));
        label_45->setText(QApplication::translate("MainWindow", "I Gain", 0, QApplication::UnicodeUTF8));
        l_i_gain->setText(QApplication::translate("MainWindow", "1337", 0, QApplication::UnicodeUTF8));
        l_p_gain->setText(QApplication::translate("MainWindow", "1337", 0, QApplication::UnicodeUTF8));
        label_42->setText(QApplication::translate("MainWindow", "P Gain", 0, QApplication::UnicodeUTF8));
        label_34->setText(QApplication::translate("MainWindow", "/* CCW Compliance Slope */", 0, QApplication::UnicodeUTF8));
        l_ccw_compliance_slope->setText(QApplication::translate("MainWindow", "1337", 0, QApplication::UnicodeUTF8));
        label_33->setText(QApplication::translate("MainWindow", "Goal Position", 0, QApplication::UnicodeUTF8));
        l_goal_pos_l->setText(QApplication::translate("MainWindow", "1337", 0, QApplication::UnicodeUTF8));
        label_46->setText(QApplication::translate("MainWindow", "Moving Speed", 0, QApplication::UnicodeUTF8));
        l_move_speed_l->setText(QApplication::translate("MainWindow", "1337", 0, QApplication::UnicodeUTF8));
        label_48->setText(QApplication::translate("MainWindow", "Torque Limit", 0, QApplication::UnicodeUTF8));
        l_torque_limit_l->setText(QApplication::translate("MainWindow", "1337", 0, QApplication::UnicodeUTF8));
        label_25->setText(QApplication::translate("MainWindow", "Lock", 0, QApplication::UnicodeUTF8));
        l_lock->setText(QApplication::translate("MainWindow", "1337", 0, QApplication::UnicodeUTF8));
        label_27->setText(QApplication::translate("MainWindow", "Punch", 0, QApplication::UnicodeUTF8));
        l_punch_l->setText(QApplication::translate("MainWindow", "1337", 0, QApplication::UnicodeUTF8));
        label_26->setText(QApplication::translate("MainWindow", "Goal Acceleration", 0, QApplication::UnicodeUTF8));
        l_goal_acceleration->setText(QApplication::translate("MainWindow", "1337", 0, QApplication::UnicodeUTF8));
        label_19->setText(QApplication::translate("MainWindow", "Present Speed Lowest Byte", 0, QApplication::UnicodeUTF8));
        label_17->setText(QApplication::translate("MainWindow", "Present Speed Highest Byte", 0, QApplication::UnicodeUTF8));
        label_31->setText(QApplication::translate("MainWindow", "Present Load Lowest Byte", 0, QApplication::UnicodeUTF8));
        label_22->setText(QApplication::translate("MainWindow", "Present Load Highest Byte", 0, QApplication::UnicodeUTF8));
        label_29->setText(QApplication::translate("MainWindow", "Present Voltage", 0, QApplication::UnicodeUTF8));
        label_21->setText(QApplication::translate("MainWindow", "Registered", 0, QApplication::UnicodeUTF8));
        label_24->setText(QApplication::translate("MainWindow", "Present Temperature", 0, QApplication::UnicodeUTF8));
        label_20->setText(QApplication::translate("MainWindow", "Moving", 0, QApplication::UnicodeUTF8));
        label_16->setText(QApplication::translate("MainWindow", "Present Position Highest Byte", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("MainWindow", "Present Position Lowest Byte", 0, QApplication::UnicodeUTF8));
        l_present_speed_l->setText(QApplication::translate("MainWindow", "1337", 0, QApplication::UnicodeUTF8));
        l_present_speed_h->setText(QApplication::translate("MainWindow", "1337", 0, QApplication::UnicodeUTF8));
        l_present_load_l->setText(QApplication::translate("MainWindow", "1337", 0, QApplication::UnicodeUTF8));
        l_present_load_h->setText(QApplication::translate("MainWindow", "1337", 0, QApplication::UnicodeUTF8));
        l_present_pos_l->setText(QApplication::translate("MainWindow", "1337", 0, QApplication::UnicodeUTF8));
        l_present_pos_h->setText(QApplication::translate("MainWindow", "1337", 0, QApplication::UnicodeUTF8));
        l_present_voltage->setText(QApplication::translate("MainWindow", "1337", 0, QApplication::UnicodeUTF8));
        l_registered->setText(QApplication::translate("MainWindow", "1337", 0, QApplication::UnicodeUTF8));
        l_present_temp->setText(QApplication::translate("MainWindow", "1337", 0, QApplication::UnicodeUTF8));
        l_moving->setText(QApplication::translate("MainWindow", "1337", 0, QApplication::UnicodeUTF8));
        label_32->setText(QApplication::translate("MainWindow", "Name", 0, QApplication::UnicodeUTF8));
        label_30->setText(QApplication::translate("MainWindow", "Value", 0, QApplication::UnicodeUTF8));
        label_35->setText(QApplication::translate("MainWindow", "Dynamixel ID", 0, QApplication::UnicodeUTF8));
        l_dynamixel_id->setText(QApplication::translate("MainWindow", "1337", 0, QApplication::UnicodeUTF8));
        pbExit->setText(QApplication::translate("MainWindow", "Exit", 0, QApplication::UnicodeUTF8));
        l_moving_2->setText(QString());
        label_36->setText(QApplication::translate("MainWindow", "Dynamixel ID", 0, QApplication::UnicodeUTF8));
        le_connection->setText(QApplication::translate("MainWindow", "No device connected", 0, QApplication::UnicodeUTF8));
        lPower->setText(QString());
        pbPower->setText(QApplication::translate("MainWindow", "Power on", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
