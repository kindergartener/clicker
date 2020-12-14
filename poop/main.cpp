#include "mainwindow.h"
#include <windows.h>
#include <autoclicker.h>
#include <thread>

#include <QApplication>

QString style = R"(
    QMainWindow {
        background-color: #2C2F33;
        color: #dadada;
        border-radius: 10px;
    }

    QWidget {
        color: #dadada;
    }

    QPushButton {
        background-color: #F4F482;
        border-radius: 4px;
        border-color: #F4F482;
        color: #000000;
    }

    QSlider::groove:horizontal {
        height: 8px;
        background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 #2E3236, stop:1 #2E3236);
        border-radius: 4px;
    }

    QSlider::handle::horizontal {
        background-color: #F4F482;
        width: 8px;
        border-radius: 4px;
    }

    QGroupBox {
        background-color: #23272A;
        border-radius: 6px;
        border-color: #F4F482;
    }
)";



int main(int argc, char *argv[])
{
    srand(time(nullptr));

    std::thread autoclicker_thread(clicker::autoclicker);
    autoclicker_thread.detach();

    QApplication a(argc, argv);

    a.setStyleSheet(style);

    MainWindow w;

    w.setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    w.setAttribute(Qt::WA_TranslucentBackground);
    w.show();

    return a.exec();
}
