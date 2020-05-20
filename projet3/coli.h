#ifndef COLI_H
#define COLI_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
class coli
{public:
    coli();
    coli(int,QString,QString,QString,QString,QString,QString,QString,QString,QString);
    int get_ID();
    QString get_nomExpediteur();
    QString get_prenomExpediteur();

    QString get_nomDestinatire();
    QString get_prenomDestinatire();
     QString get_adresseDestinatire();

    QString get_objet();
    QString get_dimension();
     QString get_poid();
      QString get_statut();



    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier (QString,int);
   QSqlQueryModel * rechercher(QString);
   QSqlQueryModel * trier(bool ph,bool croissant);

private:
      int ID;
    QString nomExpediteur,prenomExpediteur,nomDestinatire,prenomDestinatire,adresseDestinatire,objet,dimension,poid,statut;

};

#endif // COLI_H
