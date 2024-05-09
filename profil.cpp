#include "profil.h"
#include "ui_profil.h"
#include "mainwindow.h"
#include <QMessageBox>

profil::profil(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::profil)
{
    ui->setupUi(this);
    QPixmap bc("C:/Users/ASUS/Downloads/bahan qt/New folder/profil");
    ui->label_bc->setPixmap(bc);
}

profil::~profil()
{
    delete ui;
}

void profil::on_pushButton_clicked()
{
    QMessageBox::StandardButton reply = QMessageBox::question(this, "Confirmation", "Are you sure?", QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::Yes)
    {
        this->hide();
        QMainWindow *m = new MainWindow();
        m->show();
    }
}

