#ifndef INVENTARISKANTOR_H
#define INVENTARISKANTOR_H

#include <QMainWindow>
#include <QList>
#include <QTableWidgetItem>
#include <QDialog>

namespace Ui {
class inventariskantor;
}

// Definisikan struct untuk menyimpan informasi item
struct Item {
    QString kode;
    QString nama;
    int jumlah;
    QString kategori;
    QString merek;
};

class inventariskantor : public QMainWindow
{
    Q_OBJECT

public:
    explicit inventariskantor(QWidget *parent = nullptr);
    ~inventariskantor();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void displayData(); // Menambahkan implementasi untuk displayData
    void on_pushButtonCari_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_tableWidget_cellActivated(int row, int column);

private:
    Ui::inventariskantor *ui;
    QList<Item> dataArray; // Menggunakan QList dari struct Item

    // Deklarasi prototipe binarySearch
    int binarySearch(const QList<Item> &array, const QString &key);
};

#endif // INVENTARISKANTOR_H
