#include "courrier.h"

#include <QDebug>
courrier::courrier
()
{
id_courrier=0;
nom_prenom_expediteur="";
nom_prenom_destinataire="";
statut_courrier="";
adresseDestinatire="";



}
courrier::courrier(int id_courrier,QString nom_prenom_expediteur,QString nom_prenom_destinataire,QString statut_courrier,QString adresseDestinatire)
{


  this->id_courrier=id_courrier;
  this->nom_prenom_expediteur=nom_prenom_expediteur;
   this->nom_prenom_destinataire=nom_prenom_destinataire;
    this->statut_courrier=statut_courrier;
    this->adresseDestinatire=adresseDestinatire;


}
int courrier::get_id_courrier(){return  id_courrier;}
QString courrier::get_nom_prenom_expediteur(){return nom_prenom_expediteur;}
QString courrier::get_nom_prenom_destinataire(){return nom_prenom_destinataire;}
QString courrier::get_statut_courrier(){return statut_courrier;}
QString courrier::get_adresseDestinatire(){return adresseDestinatire;}


bool courrier::ajouter()
{
QSqlQuery query;
QString res= QString::number(id_courrier);
query.prepare("INSERT INTO courrier( id_courrier,nom_prenom_expediteur,nom_prenom_destinataire,statut_courrier) "
                    "VALUES (  :id_courrier, :nom_prenom_expediteur, :nom_prenom_destinataire, :statut_courrier)");

query.bindValue(":id_courrier", res);
query.bindValue(":nom_prenom_expediteur", nom_prenom_expediteur);
query.bindValue(":nom_prenom_destinataire", nom_prenom_destinataire);
query.bindValue(":statut_courrier", statut_courrier);
query.bindValue(":adresseDestinatire", adresseDestinatire);


return    query.exec();
}

QSqlQueryModel * courrier::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from courrier");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_courrier"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom_prenom_expediteur"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("nom_prenom_destinataire"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("statut_courrier"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("adresseDestinatire"));

    return model;
}

bool courrier::supprimer(int id_courrier)
{
    QSqlQuery query;
    QString res= QString::number(id_courrier);
    query.prepare("Delete from courrier where id_courrier = :id_courrier ");
    query.bindValue(":id_courrier", res);
    return    query.exec();
}
bool courrier::modifier(QString statut_courrier,int id_courrier)
 {
     QSqlQuery query;
     QString res= QString::number(id_courrier);
     query.prepare("update courrier set statut_courrier = :s where id_courrier = :id_courrier");
     query.bindValue(":s", statut_courrier);
     query.bindValue(":id_courrier", res);


     return query.exec();
 }
QSqlQueryModel *courrier::rechercher(QString nom_prenom_destinataire)
 {
     QSqlQueryModel * model= new QSqlQueryModel();
     model->setQuery("select * from courrier where nom_prenom_destinataire LIKE '"+nom_prenom_destinataire+"%'");


     model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_courrier"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom_prenom_expediteur"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("nom_prenom_destinataire"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("statut_courrier"));
     model->setHeaderData(4, Qt::Horizontal, QObject::tr("adresseDestinatire"));


         return model;
     }
QSqlQueryModel *courrier::trier(bool ph,bool croissant)
{
    QSqlQueryModel *model=new QSqlQueryModel;
    QString tr;
    tr="SELECT * FROM courrier ORDER BY ";
    if (ph)
        tr+="id_courrier";

    if (!croissant)
        tr+=" DESC";
    model->setQuery(tr);
    return model;
}
