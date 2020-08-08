#include "mainwindow.h"
#include "../easyimage.h"
#include "ui_mainwindow.h"
#include <QtConcurrent/QtConcurrent>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->EasyImage_Show->setScaledContents(true);
    ui->ImagePathEdit->setText("https://upload.wikimedia.org/wikipedia/commons/thumb/0/0b/Qt_logo_2016.svg/320px-Qt_logo_2016.svg.png");
    LoadImage();
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::LoadImage()
{
    if (ui->checkBox->isChecked())
    {
        ui->EasyImage_Show->setScaledContents(true);
    }
    else
    {
        ui->EasyImage_Show->setScaledContents(false);
    }
    QtConcurrent::run([=](){
        ui->EasyImage_Show->setPixmap(EasyImage().getImages(ui->ImagePathEdit->toPlainText()));
    });
}
void MainWindow::on_pushButton_clicked(bool checked)
{
    LoadImage();
}
