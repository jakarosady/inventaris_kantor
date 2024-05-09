#include "admin.h"
#include "ui_admin.h"
#include <QMessageBox>
#include "inventarisadmin.h"
#include "login.h"
admin::admin(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::admin)
{
    ui->setupUi(this);
}

admin::~admin()
{
    delete ui;
}

void admin::on_pushButton_Login_3_clicked()
{
    QString UserName = ui->lineEdit_User_Name_3->text();
    QString Password = ui->lineEdit_Password_3->text();
    if (UserName == "ramadan" && Password == "ramadan123")
    {
        QMessageBox::information(this,"Qt ramadan", "Login Succes,");
        this->hide();
        inventarisadmin *inventarisadmin = new class inventarisadmin();
        inventarisadmin->show();
    }
    else
    {
        QMessageBox::information(this,"Qt ramadan", "please Enter Valid Username Or Password");
    }

}


void admin::on_pushButton_Cancel_3_clicked()
{

}


void admin::on_pushButton_clicked()
{
    QMessageBox::StandardButton reply = QMessageBox::question(this, "Confirmation", "Are you sure?", QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::Yes)
    {
        this->hide();
        login *l = new login();
        l->show();
    }
}

