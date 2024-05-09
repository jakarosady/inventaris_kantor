#include "inventariskantor.h"
#include "ui_inventariskantor.h"
#include <QMessageBox>
#include "mainwindow.h"

inventariskantor::inventariskantor(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::inventariskantor)
{
    ui->setupUi(this);
}

inventariskantor::~inventariskantor()
{
    delete ui;
}

void inventariskantor::on_pushButton_clicked()
{
    // Mendapatkan input dari pengguna
    QString kode = ui->lineEditKode->text();
    QString nama = ui->lineEditNama->text();
    int jumlah = ui->spinBoxJumlah->value();
    QString kategori = ui->lineEditKategori->text();
    QString merek = ui->lineEditMerek->text();

    // Membuat objek Item baru dan menambahkannya ke dalam dataArray
    Item newItem = {kode, nama, jumlah, kategori, merek};
    dataArray.append(newItem);

    // Membersihkan input setelah ditambahkan ke dataArray
    ui->lineEditKode->clear();
    ui->lineEditNama->clear();
    ui->spinBoxJumlah->setValue(0);
    ui->lineEditKategori->clear();
    ui->lineEditMerek->clear();

    // Menampilkan data setelah ditambahkan
    displayData();
}

void inventariskantor::on_pushButton_2_clicked()
{
    // Proses yang sama seperti pada on_pushButton_clicked()
    QString kode = ui->lineEditKode->text();
    QString nama = ui->lineEditNama->text();
    int jumlah = ui->spinBoxJumlah->value();
    QString kategori = ui->lineEditKategori->text();
    QString merek = ui->lineEditMerek->text();

    Item newItem = {kode, nama, jumlah, kategori, merek};
    dataArray.append(newItem);

    ui->lineEditKode->clear();
    ui->lineEditNama->clear();
    ui->spinBoxJumlah->setValue(0);
    ui->lineEditKategori->clear();
    ui->lineEditMerek->clear();

    displayData();
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this,"Qt r", "apakah kamu yakin untuk keluar dari aplikasi",QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::Yes)
    {
        QApplication::quit();
    }
}

void inventariskantor::displayData()
{
    // Menghapus semua baris sebelum menambahkan data baru
    ui->tableWidget->setRowCount(0);

    // Menampilkan data dalam array ke konsol
    qDebug() << "Data Array:";
    for (int i = 0; i < dataArray.size(); ++i) {
        const Item &item = dataArray.at(i);
        qDebug() << "Kode:" << item.kode;
        qDebug() << "Nama:" << item.nama;
        qDebug() << "Jumlah:" << item.jumlah;
        qDebug() << "Kategori:" << item.kategori;
        qDebug() << "Merek:" << item.merek;
        qDebug() << "-----------------";

        // Menambahkan baris baru ke tabel
        ui->tableWidget->insertRow(ui->tableWidget->rowCount());

        // Menetapkan nilai ke setiap sel dalam tabel
        QTableWidgetItem *kodeItem = new QTableWidgetItem(item.kode);
        ui->tableWidget->setItem(i, 0, kodeItem);

        QTableWidgetItem *namaItem = new QTableWidgetItem(item.nama);
        ui->tableWidget->setItem(i, 1, namaItem);

        QTableWidgetItem *jumlahItem = new QTableWidgetItem(QString::number(item.jumlah));
        ui->tableWidget->setItem(i, 2, jumlahItem);

        QTableWidgetItem *kategoriItem = new QTableWidgetItem(item.kategori);
        ui->tableWidget->setItem(i, 3, kategoriItem);

        QTableWidgetItem *merekItem = new QTableWidgetItem(item.merek);
        ui->tableWidget->setItem(i, 4, merekItem);
    }
}

void inventariskantor::on_pushButtonCari_clicked()
{
    // Mendapatkan kode barang yang akan dicari
    QString searchKey = ui->lineEditKodeCari->text();

    int index = binarySearch(dataArray, searchKey);

    if (index != -1) {
        // Barang ditemukan, tampilkan informasi barang di antarmuka pengguna
        const Item &foundItem = dataArray.at(index);
        QMessageBox::information(this, "Informasi Barang",
                                 "Kode: " + foundItem.kode +
                                     "\nNama: " + foundItem.nama +
                                     "\nJumlah: " + QString::number(foundItem.jumlah) +
                                     "\nKategori: " + foundItem.kategori +
                                     "\nMerek: " + foundItem.merek);
    } else {
        // Barang tidak ditemukan
        QMessageBox::warning(this, "Pencarian Barang", "Barang tidak ditemukan.");
    }
}

int inventariskantor::binarySearch(const QVector<Item> &array, const QString &key)
{
    int left = 0;
    int right = array.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (array[mid].kode == key)
            return mid; // Barang ditemukan di indeks mid
        else if (array[mid].kode < key)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1; // Barang tidak ditemukan
}

void inventariskantor::on_pushButton_3_clicked()
{
    // Mendapatkan kode barang yang akan dihapus
    QString deleteKey = ui->lineEditKodeHapus->text();

    // Mencari indeks dari barang yang akan dihapus
    int index = binarySearch(dataArray, deleteKey);

    if (index != -1) {
        // Barang ditemukan, hapus item dari array
        dataArray.remove(index);

        // Tampilkan pesan konfirmasi
        QMessageBox::information(this, "Penghapusan Barang", "Barang berhasil dihapus.");

        // Menampilkan kembali data setelah penghapusan
        displayData();
    } else {
        // Barang tidak ditemukan
        QMessageBox::warning(this, "Penghapusan Barang", "Barang tidak ditemukan.");
    }
}

void inventariskantor::on_pushButton_4_clicked()
{
    QMessageBox::StandardButton reply = QMessageBox::question(this, "Confirmation", "Are you sure?", QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::Yes)
    {
        this->hide();
        QMainWindow *m = new MainWindow();
        m->show();
    }
}

void inventariskantor::on_tableWidget_cellActivated(int row, int column)
{

}
