#ifndef WINDOW_H
#define WINDOW_H

#include <QDialog>

namespace Ui {
class Window;
}

class Window : public QDialog {
    Q_OBJECT
    public:
        explicit Window(QWidget *parent = 0);
        ~Window();
private slots:
    void on_ManualGPIOToggle_toggled(bool checked);

    void on_ManualControlToggle_toggled(bool checked);

    void on_AIMotorSpeedSlider_sliderMoved(int position);

    void on_ManualMotorSpeedSlider_sliderMoved(int position);

    void on_RobotViewButton_clicked();

private:
        Ui::Window *ui;
};

#endif // WINDOW_H
