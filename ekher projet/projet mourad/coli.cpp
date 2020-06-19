#include "coli.h"

#include <QDebug>
coli::coli
()
{
ID=0;
nom_prenom_Expediteur="";

nom_prenom_Destinatire="";
    adresseDestinatire="";

   objet="";
 dimension="";
 poid="";
  statut="";
}
coli::coli (int ID,QString nom_prenom_Expediteur,QString nom_prenom_Destinatire,QString adresseDestinatire,QString objet,QString dimension,QString poid,QString statut )
{

  this->ID=ID;
  this->nom_prenom_Expediteur=nom_prenom_Expediteur;

  this->nom_prenom_Destinatire=nom_prenom_Destinatire;

  this->adresseDestinatire=adresseDestinatire;
  this->objet=objet;
  this->dimension=dimension;
  this-> poid= poid;
    this->statut=statut;
}
int coli::get_ID(){return  ID;}
QString coli::get_nom_prenom_Expediteur(){return nom_prenom_Expediteur;}
QString coli::get_nom_prenom_Destinatire(){return  nom_prenom_Destinatire;}
QString coli::get_adresseDestinatire(){return  adresseDestinatire;}
QString coli::get_objet(){return    objet;}
QString coli::get_dimension(){return   dimension;}
QString coli::get_poid(){return  poid;}
QString coli::get_statut(){return  statut;}

bool coli::ajouter()
{
QSqlQuery query;
QString res= QString::number(ID);
query.prepare("INSERT INTO coli ( ID,nom_prenom_Expediteur,nom_prenom_Destinataire,adresseDestinatire,objet,dimension,poid,statut) "
                    "VALUES ( :ID, :nom_prenom_Expediteur, :nom_prenom_Destinataire, :adresseDestinatire, :objet, :dimension, :poid, :statut)");
query.bindValue(":ID", res);
query.bindValue(":nom_prenom_Expediteur", nom_prenom_Expediteur);
query.bindValue(":nom_prenom_Destinataire", nom_prenom_Destinatire);
query.bindValue(":adresseDestinatire",  adresseDestinatire);
query.bindValue(":objet", objet);
query.bindValue(":dimension",  dimension);
query.bindValue(":poid", poid);
query.bindValue(":statut", statut);


return    query.exec();
}

QSqlQueryModel * coli::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from coli");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom_prenom_Expediteur"));

model->setHeaderData(2, Qt::Horizontal, QObject::tr("nom_prenom_Destinataire"));

model->setHeaderData(3, Qt::Horizontal, QObject::tr("adresseDestinatire"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("objet"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr(" dimension"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr(" poid"));
model->setHeaderData(7, Qt::Horizontal, QObject::tr("statut"));
return model;
}

bool coli::supprimer(int ID)
{
QSqlQuery query;
QString res= QString::number(ID);
query.prepare("Delete from coli where ID = :ID ");
query.bindValue(":ID", res);
return    query.exec();
}
bool coli::modifier(QString statut,QString nom_prenom_Expediteur,QString nom_prenom_Destinataire,QString adresseDestinatire,QString objet,QString dimension,QString poid,int ID)
 {
    QSqlQuery query;
    QString res= QString::number(ID);
    query.prepare("UPDATE coli SET NOM_PRENOM_EXPEDITEUR = :c, NOM_PRENOM_DESTINATAIRE = :a, ADRESSEDESTINATIRE = :b, OBJET = :d, DIMENSION = :e, POID = :f, statut = :s where ID= :ID");
    query.bindValue(":ID", res);
    query.bindValue(":s", statut);
    query.bindValue(":c", nom_prenom_Expediteur);
    query.bindValue(":a", nom_prenom_Destinataire);
    query.bindValue(":b", adresseDestinatire);
    query.bindValue(":d", objet);
    query.bindValue(":e", dimension);
    query.bindValue(":f", poid);





    return query.exec();
 }

QSqlQueryModel *coli::rechercher(QString nom_prenom_Destinatire)
 {
     QSqlQueryModel * model= new QSqlQueryModel();
     model->setQuery("select * from coli where nom_prenom_Destinataire LIKE '"+nom_prenom_Destinatire+"%'");


     model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom_prenom_Expediteur"));

     model->setHeaderData(2, Qt::Horizontal, QObject::tr("nom_prenom_Destinataire"));

     model->setHeaderData(3, Qt::Horizontal, QObject::tr("adresseDestinatire"));
     model->setHeaderData(4, Qt::Horizontal, QObject::tr("objet"));
     model->setHeaderData(5, Qt::Horizontal, QObject::tr(" dimension"));
     model->setHeaderData(6, Qt::Horizontal, QObject::tr(" poid"));
     model->setHeaderData(7, Qt::Horizontal, QObject::tr("statut"));
     return model;
     }
QSqlQueryModel *coli::trier(bool ph,bool croissant)
{
    QSqlQueryModel *model=new QSqlQueryModel;
    QString tr;
    tr="SELECT * FROM coli ORDER BY ";
    if (ph)
        tr+="ID";

    if (!croissant)
        tr+=" DESC";
    model->setQuery(tr);
    return model;
}
