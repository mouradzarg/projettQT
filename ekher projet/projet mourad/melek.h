#ifndef MELEK_H
#define MELEK_H

#include <QDialog>
#include"employee.h"
#include"reclamation.h"

namespace Ui {
class melek;
}

class melek : public QDialog
{
    Q_OBJECT

public:
    explicit melek(QWidget *parent = nullptr);
    ~melek();

private slots:
    void on_ajoute_congee_2_clicked();

    void on_AjoutEmployer_clicked();

    void on_ajouter_6_clicked();

    void on_ajouter_7_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_14_clicked();

    void on_modifier_congee_2_clicked();

    void on_supp_congee_2_clicked();

    void on_trier_congee_2_clicked();

    void on_pushButton_10_clicked();

    void on_recherche_congee_2_clicked();

    void on_ajoute_congee_clicked();

private:
    Ui::melek *ui;
    employee tmpcoli;
    reclamation tmpcongee;
};

#endif // MELEK_H
