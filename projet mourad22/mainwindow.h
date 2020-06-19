#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "coli.h"
#include "courrier.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();

    void on_ajouter_5_clicked();
    void on_ajouter_6_clicked();
    void on_ajouter_7_clicked();
    void on_ajoute_cour_clicked();
    void on_modifier_cour_2_clicked();
    void on_ajouter_8_clicked();
    void on_pb_ajouter_11_clicked();
    void on_radioButton_30_toggled(bool checked);
    void on_pb_ajouter_10_clicked();
    void on_radioButton_24_toggled(bool checked);






    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_tabcoli_1_activated(const QModelIndex &index);

private:
    Ui::MainWindow *ui;
    coli tmpcoli;
    courrier  tmpcourrier;


};

#endif // MAINWINDOW_H
