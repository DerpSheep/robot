#include "window.h"
#include "main.h"
#include "robotview.h"
#include "ui_window.h"

Window::Window(QWidget *parent) : QDialog(parent), ui(new Ui::Window) {
    ui->setupUi(this);
}

Window::~Window() {
    delete ui;
}

void Window::on_ManualGPIOToggle_toggled(bool checked) {
    ui->Pin1Selector->setEnabled(checked);
    ui->Pin2Selector->setEnabled(checked);
    ui->Pin3Selector->setEnabled(checked);
    ui->Pin4Selector->setEnabled(checked);
    ui->Pin5Selector->setEnabled(checked);
    ui->Pin6Selector->setEnabled(checked);
    ui->Pin7Selector->setEnabled(checked);
    ui->Pin8Selector->setEnabled(checked);
    ui->Pin9Selector->setEnabled(checked);
    ui->Pin10Selector->setEnabled(checked);
    ui->GPIODelaySelector->setEnabled(checked);
}

void Window::on_ManualControlToggle_toggled(bool checked) {
    ui->ManualForward->setEnabled(checked);
    ui->ManualBackward->setEnabled(checked);
    ui->ManualTurnLeft->setEnabled(checked);
    ui->ManualTurnRight->setEnabled(checked);
    ui->ManualUseArrowKeys->setEnabled(checked);
}

void Window::on_AIMotorSpeedSlider_sliderMoved(int position) {
    ui->AIMotorSpeedIndicator->setText(tr("%1 RPM").arg(ceil(position * 3.13)));
}

void Window::on_ManualMotorSpeedSlider_sliderMoved(int position) {
    ui->ManualMotorSpeedIndicator->setText(tr("%1 RPM").arg(ceil(position * 3.13)));
}

void Window::on_RobotViewButton_clicked() {
    //Show robot view GUI
    RobotView::showScene();
}
