#ifndef AGENTS_H
#define AGENTS_H


#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>


class Agents
{
private:
    int ID ;
    QString Nom ;
    QString Prenom;
    QString MotDePasse ;
    QString Adresse ;
    QString Role ;
public:
    Agents();
    Agents(int,QString,QString,QString,QString,QString);

    int get_ID ();
    QString get_Nom();
    QString get_Prenom();
    QString get_MotDePasse();
    QString get_Adresse();
    QString get_Role();

    bool Ajouter_Agents();
    bool Modifier_Agents();
    QSqlQueryModel * Afficher_Agents () ;
    bool Supprimer_Agents();
    bool Login(int,QString);
};


#endif // AGENTS_H
