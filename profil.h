#ifndef PROFIL_H
#define PROFIL_H

#include <QMainWindow>

namespace Ui {
class profil;
}

class profil : public QMainWindow
{
    Q_OBJECT

public:
    explicit profil(QWidget *parent = nullptr);
    ~profil();

private slots:
    void on_pushButton_clicked();

private:
    Ui::profil *ui;
};

#endif // PROFIL_H
