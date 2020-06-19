#ifndef FRED_H
#define FRED_H

#include <QDialog>
#include"agents.h"
#include"conges.h"

namespace Ui {
class fred;
}

class fred : public QDialog
{
    Q_OBJECT

public:
    explicit fred(QWidget *parent = nullptr);
    ~fred();

private slots:
    void on_Ajouter_Agents_clicked();

    void on_Modifier_Agents_clicked();

    void on_Supprimer_Agents_clicked();

    void on_Afficher_Agents_clicked();

    void on_Ajouter_Conges_clicked();

    void on_Modifier_Conges_clicked();

    void on_Supprimer_Conges_clicked();

    void on_Afficher_Conges_clicked();

    void on_Tab_Conges_activated(const QModelIndex &index);

    void on_TabAgents_activated(const QModelIndex &index);

    void on_Retour_Agents_clicked();

    void on_Retour_Conges_clicked();

private:
    Ui::fred *ui;
    Agents tmpAgents ;
    Conges tmpConges;
};

#endif // FRED_H
