#ifndef INVENTARISADMIN_H
#define INVENTARISADMIN_H

#include <QMainWindow>
#include <QList>
#include <QTableWidgetItem>
#include <QDialog>

namespace Ui {
class inventarisadmin;
}

// Definisikan struct untuk menyimpan informasi item
struct Item {
    QString kode;
    QString nama;
    int jumlah;
    QString kategori;
    QString merek;
};

class inventarisadmin : public QMainWindow
{
    Q_OBJECT

public:
    explicit inventarisadmin(QWidget *parent = nullptr);
    ~inventarisadmin();



private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void displayData(); // Menambahkan implementasi untuk displayData
    void on_pushButtonCari_clicked();
    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_tableWidget_cellActivated(int row, int column);

private:
    Ui::inventarisadmin *ui;
    QList<Item> dataArray; // Menggunakan QList dari struct Item

    // Deklarasi prototipe binarySearch
    int binarySearch(const QList<Item> &array, const QString &key);
};

#endif // INVENTARISADMIN_H
