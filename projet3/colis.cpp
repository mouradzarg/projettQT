#include "coli.h"
#include <QDebug>
coli::coli
()
{
ID=0;
nomExpediteur="";
prenomExpediteur="";
nomDestinatire="";
prenomDestinatire="";
    adresseDestinatire="";

   objet="";
 dimension="";
 poid="";
  statut="";
}
coli::coli (int ID,QString nomExpediteur,QString prenomExpediteur,QString nomDestinatire,QString prenomDestinatire,QString adresseDestinatire,QString objet,QString dimension,QString poid,QString statut )
{

  this->ID=ID;
  this->nomExpediteur=nomExpediteur;
  this->prenomExpediteur=prenomExpediteur;
  this->nomDestinatire=nomDestinatire;
  this->prenomDestinatire=prenomDestinatire;
  this->adresseDestinatire=adresseDestinatire;
  this->objet=objet;
  this->dimension=dimension;
  this-> poid= poid;
    this->statut=statut;
}
int coli::get_ID(){return  ID;}
QString coli::get_nomExpediteur(){return nomExpediteur;}
QString coli::get_prenomExpediteur(){return prenomExpediteur;}
QString coli::get_nomDestinatire(){return  nomDestinatire;}
QString coli::get_prenomDestinatire(){return  prenomDestinatire;}
QString coli::get_adresseDestinatire(){return  adresseDestinatire;}
QString coli::get_objet(){return    objet;}
QString coli::get_dimension(){return   dimension;}
QString coli::get_poid(){return  poid;}
QString coli::get_statut(){return  statut;}

bool coli::ajouter()
{
QSqlQuery query;
QString res= QString::number(ID);
query.prepare("INSERT INTO coli ( ID,nomExpediteur,prenomExpediteur,nomDestinatire,prenomDestinatire,adresseDestinatire,objet,dimension,poid,statut) "
                    "VALUES ( :ID, :nomExpediteur, :prenomExpediteur, :nomDestinatire, :prenomDestinatire, :adresseDestinatire, :objet, :dimension, :poid, :statut)");
query.bindValue(":ID", res);
query.bindValue(":nomExpediteur", nomExpediteur);
query.bindValue(":prenomExpediteur", prenomExpediteur);
query.bindValue(":nomDestinatire", nomDestinatire);
query.bindValue(":prenomDestinatire", prenomDestinatire);
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
model->setHeaderData(1, Qt::Horizontal, QObject::tr("nomExpediteur"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenomExpediteur"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("nomDestinatire"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("prenomDestinatire"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("adresseDestinatire"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("objet"));
model->setHeaderData(7, Qt::Horizontal, QObject::tr(" dimension"));
model->setHeaderData(8, Qt::Horizontal, QObject::tr(" poid"));
model->setHeaderData(9, Qt::Horizontal, QObject::tr("statut"));
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
bool coli::modifier(QString statut,int ID)
 {
    QSqlQuery query;
    QString res= QString::number(ID);
    query.prepare("update coli set statut = :s where ID= :ID");
    query.bindValue(":ID", res);
    query.bindValue(":s", statut);

    return query.exec();
 }

QSqlQueryModel *coli::rechercher(QString nomDestinatire)
 {
     QSqlQueryModel * model= new QSqlQueryModel();
     model->setQuery("select * from coli where nomDestinatire LIKE '"+nomDestinatire+"%'");


     model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("nomExpediteur"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenomExpediteur"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("nomDestinatire"));
     model->setHeaderData(4, Qt::Horizontal, QObject::tr("prenomDestinatire"));
     model->setHeaderData(5, Qt::Horizontal, QObject::tr("adresseDestinatire"));
     model->setHeaderData(6, Qt::Horizontal, QObject::tr("objet"));
     model->setHeaderData(7, Qt::Horizontal, QObject::tr(" dimension"));
     model->setHeaderData(8, Qt::Horizontal, QObject::tr(" poid"));
     model->setHeaderData(9, Qt::Horizontal, QObject::tr("statut"));
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

