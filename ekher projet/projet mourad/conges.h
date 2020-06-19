#ifndef CONGES_H
#define CONGES_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>

class Conges
{
private:

    QString Type_conges;
    QDate Debut_conges;
    QDate Date_fin_conges;
public:
    Conges();
    Conges(QString,QDate,QDate);


    QString get_Type_conges();
    QDate get_Debut_conges();
    QDate get_Date_fin_conges();

    bool Ajouter_Conges();
    bool Modifier_Conges();
    QSqlQueryModel * Afficher_Conges () ;
    bool Supprimer_Conges();

};

#endif // CONGES_H
