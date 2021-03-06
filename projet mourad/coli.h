#ifndef COLI_H
#define COLI_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
class coli
{public:
    coli();
    coli(int,QString,QString,QString,QString,QString,QString,QString);
    int get_ID();
    QString get_nom_prenom_Expediteur();
    QString get_nom_prenom_Destinatire();
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
    QString nom_prenom_Expediteur,nom_prenom_Destinatire,adresseDestinatire,objet,dimension,poid,statut;

};

#endif // COLI_H
