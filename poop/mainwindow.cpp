#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "config.h"

#include <iostream>
#include <windows.h>
#include <thread>
#include <QMouseEvent>

QVector<QString> key_names {
    "Error", "M1", "M2", "Break", "M3", "M4", "M5",
    "Error", "BACKSPACE", "TAB", "Error", "Error", "Error", "ENTER", "Error", "Error", "SHIFT",
    "CTRL", "ALT", "PAUSE", "CAPS LOCK", "Error", "Error", "Error", "Error", "Error", "Error",
    "Error", "Error", "Error", "Error", "Error", "SPACEBAR", "PG UP", "PG DOWN", "END", "HOME", "Left",
    "Up", "Right", "Down", "Error", "Print", "Error", "Print Screen", "Insert", "Delete", "Error", "0", "1",
    "2", "3", "4", "5", "6", "7", "8", "9", "Error", "Error", "Error", "Error", "Error", "Error",
    "Error", "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U",
    "V", "W", "X", "Y", "Z", "Left Windows", "Right Windows", "Error", "Error", "Error", "NUM 0", "NUM 1",
    "NUM 2", "NUM 3", "NUM 4", "NUM 5", "NUM 6", "NUM 7", "NUM 8", "NUM 9", "*", "+", "_", "-", ".", "/", "F1", "F2", "F3",
    "F4", "F5", "F6", "F7", "F8", "F9", "F10", "F11", "F12", "F13", "F14", "F15", "F16", "F17", "F18", "F19", "F20", "F21",
    "F22", "F23", "F24", "Error", "Error", "Error", "Error", "Error", "Error", "Error", "Error",
    "NUM LOCK", "SCROLL LOCK", "Error", "Error", "Error", "Error", "Error", "Error", "Error",
    "Error", "Error", "Error", "Error", "Error", "Error", "Error", "LSHIFT", "RSHIFT", "LCONTROL",
    "RCONTROL", "LMENU", "RMENU", "Error", "Error", "Error", "Error", "Error", "Error", "Error",
    "Error", "Error", "Error", "Next Track", "Previous Track", "Stop", "Play/Pause", "Error", "Error",
    "Error", "Error", "Error", "Error", ";", "+", ",", "-", ".", "/?", "~", "Error", "Error",
    "Error", "Error", "Error", "Error", "Error", "Error", "Error", "Error", "Error",
    "Error", "Error", "Error", "Error", "Error", "Error", "Error", "Error", "Error",
    "Error", "Error", "Error", "Error", "Error", "Error", "[{", "\\|", "}]", "'\"", "Error",
    "Error", "Error", "Error", "Error", "Error", "Error", "Error", "Error", "Error",
    "Error", "Error", "Error", "Error", "Error", "Error", "Error", "Error", "Error",
    "Error", "Error", "Error", "Error", "Error", "Error", "Error", "Error", "Error",
    "Error", "Error"
};

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

/*
void MainWindow::mousePressEvent(QMouseEvent *evt) {
    oldPos = evt->globalPos() - pos();
}

void MainWindow::mouseMoveEvent(QMouseEvent *evt) {
    move(evt->globalPos() - oldPos);
}
*/

void MainWindow::on_get_place_key_clicked()
{
    int res = 0;
    int reset = 0;

    while(!res){
        for(int i = 3; i < 256; i++){
            if(i == VK_SPACE)
                continue;

            if ( GetAsyncKeyState(i) & 1)
                res = i;
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }

    reset = 0;

    while(reset != 252){
        reset = 0;

        for(int i = 3; i < 256; i++) {
            if (!GetAsyncKeyState(i))
                reset++;
        }
    }

    if (res){
        config.place_key = res;
        ui->get_place_key->setText(key_names[res]);
    }
}

void MainWindow::on_get_attack_key_clicked()
{
    int res = 0;
    int reset = 0;

    while(!res){
        for(int i = 3; i < 256; i++){
            if(i == VK_SPACE)
                continue;

            if ( GetAsyncKeyState(i) & 1)
                res = i;
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }

    reset = 0;

    while(reset != 252){
        reset = 0;

        for(int i = 3; i < 256; i++) {
            if (!GetAsyncKeyState(i))
                reset++;
        }
    }

    if (res){
        config.attack_key = res;
        ui->get_attack_key->setText(key_names[res]);
    }
}

void MainWindow::on_toggle_stateChanged(int toggle)
{
    config.toggle = toggle;
}

void MainWindow::on_humanize_stateChanged(int humanize)
{
    config.humanize = humanize;
}

void MainWindow::on_cps_attack_valueChanged(int cps_attack)
{
    config.attack_cps = cps_attack;
    ui->attack_label->setText("Attack CPS (" + QString::number(cps_attack) + ")");
}

void MainWindow::on_cps_place_valueChanged(int cps_place)
{
    config.place_cps = cps_place;
    ui->place_label->setText("Place CPS (" + QString::number(cps_place) + ")");
}
