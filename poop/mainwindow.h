#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QPainterPath>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_get_place_key_clicked();
    void on_get_attack_key_clicked();
    void on_toggle_stateChanged(int arg1);
    void on_humanize_stateChanged(int arg1);
    void on_cps_attack_valueChanged(int value);
    void on_cps_place_valueChanged(int value);

protected:
    void paintEvent (QPaintEvent * event)
    {
         QPainter painter (this);
         painter.setRenderHint (QPainter::Antialiasing); // Anti-aliasing;
         painter.setBrush (QBrush (QColor("#2C2F33")));
         painter.setPen (Qt :: transparent);
         QRect rect = this-> rect ();
         rect.setWidth (rect.width ()-1);
         rect.setHeight (rect.height ()-1);

         painter.drawRoundedRect (rect, 6, 6);

         QWidget :: paintEvent (event);
    }

    //void mousePressEvent(QMouseEvent *evt);
    //void mouseMoveEvent(QMouseEvent *evt);

private:
    Ui::MainWindow *ui;

    QPoint oldPos;
};
#endif // MAINWINDOW_H
