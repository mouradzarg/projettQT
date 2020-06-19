#ifndef MOURAD_H
#define MOURAD_H
#include"coli.h"
#include"courrier.h"
#include <QDialog>

namespace Ui {
class mourad;
}

class mourad : public QDialog
{
    Q_OBJECT

public:
    explicit mourad(QWidget *parent = nullptr);
    ~mourad();

private slots:
    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_ajouter_5_clicked();

    void on_ajouter_6_clicked();

    void on_ajouter_7_clicked();

    void on_pb_ajouter_11_clicked();

    void on_pushButton_5_clicked();

    void on_tabcoli_1_activated(const QModelIndex &index);

    void on_radioButton_24_toggled(bool checked);

    void on_ajoute_cour_clicked();

    void on_modifier_cour_2_clicked();

    void on_pushButton_6_clicked();

    void on_ajouter_8_clicked();

    void on_pb_ajouter_10_clicked();

    void on_radioButton_30_toggled(bool checked);

    void on_tabcourrier_1_activated(const QModelIndex &index);

private:
    Ui::mourad *ui;
    coli tmpcoli;
    courrier  tmpcourrier;

};

#endif // MOURAD_H
