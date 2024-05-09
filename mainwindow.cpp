#include "mainwindow.h"
#include "login.h"
#include "ui_mainwindow.h"'
#include "profil.h"
#include <QMessageBox>
#include <QPixmap>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix ("C:/Users/ASUS/Downloads/bahan qt/New folder/download");
    ui->label_pic->setPixmap(pix);

    QPixmap prof ("C:/Users/ASUS/Downloads/bahan qt/New folder/prof");
    ui->label_prof->setPixmap(prof);


    QPixmap bc ("C:/Users/ASUS/Downloads/bahan qt/New folder/bc");
    ui->label_bc->setPixmap(bc);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QMessageBox::StandardButton reply = QMessageBox::question(this, "Confirmation", "Are you sure?", QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        this->hide();
        login *p = new login();
        p->show();
    }
}


void MainWindow::on_pushButton_prof_clicked()
{
    QMessageBox::StandardButton reply = QMessageBox::question(this, "Confirmation", "Are you sure?", QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        this->hide();
        profil *p = new profil();
        p->show();
    }
}

