#ifndef ADMIN_H
#define ADMIN_H

#include <QMainWindow>

namespace Ui {
class admin;
}

class admin : public QMainWindow
{
    Q_OBJECT

public:
    explicit admin(QWidget *parent = nullptr);
    ~admin();

private slots:
    void on_pushButton_Login_3_clicked();

    void on_pushButton_Cancel_3_clicked();

    void on_pushButton_clicked();

private:
    Ui::admin *ui;


};

#endif // ADMIN_H
