#ifndef COURRIER_H
#define COURRIER_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
class courrier
{public:
    courrier();
    courrier(int,QString,QString,QString);
      int get_id_courrier();
    QString get_expediteur();
    QString get_destinataire();
    QString get_statut_courrier(); 


    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier (QString,int);
    QSqlQueryModel * rechercher(QString);
    QSqlQueryModel * trier(bool ph,bool croissant);


private:
         int id_courrier;
    QString expediteur,destinataire,statut_courrier;


};

#endif // COURRIER_H
