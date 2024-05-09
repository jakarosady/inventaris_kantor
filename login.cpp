#include "login.h"
#include "ui_login.h"
#include <QMessageBox>
#include "inventariskantor.h"
#include "admin.h"
#include <mainwindow.h>

login::login(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::login)
{
    ui->setupUi(this);
}

login::~login()
{
    delete ui;
}

void login::on_pushButton_Login_2_clicked()
{

    QString UserName = ui->lineEdit_User_Name_2->text();
    QString Password = ui->lineEdit_Password_2->text();
    if (UserName == "kelompok3" && Password == "kelompok123")
    {
        QMessageBox::information(this,"Qt kelompo3", "Login berhasil,");
        this->hide();
        inventariskantor *inventariskantor = new class inventariskantor ();
        inventariskantor->show();
    }
    else
    {
        QMessageBox::information(this,"Qt kelompok3", "silakan masukan password dan username yang valid");
    }
}


void login::on_pushButton_Cancel_2_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this,"Qt kelompok3", "apakah kamu yakin untuk keluar dari aplikasi",QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::Yes)
    {
        QApplication::quit();
    }
}


void login::on_pushButton_clicked()
{
    QMessageBox::StandardButton reply = QMessageBox::question(this, "Confirmation", "Are you sure?", QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::Yes)
    {
        this->hide();
        admin *admin = new class admin();
        admin->show();
    }
}


void login::on_pushButton_2_clicked()
{
    QMessageBox::StandardButton reply = QMessageBox::question(this, "Confirmation", "Are you sure?", QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::Yes)
    {
        this->hide();
        QMainWindow *m = new MainWindow();
        m->show();
    }
}

