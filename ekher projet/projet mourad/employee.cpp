#include "employee.h"

#include <QDebug>
employee::employee
()
{
id=0;
nom="";

prenom="";
    cin=0;

  role="";

}

employee::employee (int id, QString nom,QString prenom,int cin,QString role )
{

  this->id=id;
  this->nom=nom;

  this->prenom=prenom;

  this->cin=cin;
  this->role=role;

}
int employee::get_id(){return  id;}
QString employee::get_nom(){return nom;}
QString employee::get_prenom(){return  prenom;}
int employee::get_cin(){return cin;}
QString employee::get_role(){return role;}


bool employee::ajouter()
{
    QSqlQuery query;
    QString res= QString::number(id);
    QString res1= QString::number(cin);

    query.prepare("INSERT INTO EMPLOYE (ID_EMP, NOM ,PRENOM ,CIN,ROLE ) "
                        "VALUES (:id, :nom, :prenom, :cin, :role)");
    query.bindValue(":id", res);
    query.bindValue(":nom", nom);

    query.bindValue(":prenom", prenom);
    query.bindValue(":cin", res1);
    query.bindValue(":role", role);

    return    query.exec();
    }


QSqlQueryModel * employee::afficher()
{

        QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from EMPLOYE");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_EMP"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("CIN"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("ROLE"));
    return model;
    }
bool employee::supprimer(int id)
{
    QSqlQuery query;
    QString res= QString::number(id);
    query.prepare("Delete from EMPLOYE where ID_EMP = :id ");
    query.bindValue(":id", res);
    return    query.exec();
    }
bool employee::modifier(int id,QString nom, QString prenom , int cin,QString role)
 {
    {
        QSqlQuery query;
        QString res= QString::number(id);
        QString res1= QString::number(cin);
        query.prepare("UPDATE EMPLOYE set  NOM = :nom, PRENOM = :prenom, CIN = :cin, ROLE= :role WHERE ID_EMP = :id");
        query.bindValue(":id",res);
        query.bindValue(":cin",res1);

        query.bindValue(":nom",nom);
        query.bindValue(":prenom",prenom);
         query.bindValue(":role",role);

        return query.exec();
    }
 }

QSqlQueryModel *employee::rechercher(QString nom)
 {
     QSqlQueryModel * model= new QSqlQueryModel();
     model->setQuery("select * from EMPLOYE where nom LIKE '"+nom+"%'");


     model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));

     model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));

     model->setHeaderData(3, Qt::Horizontal, QObject::tr("cin"));
     model->setHeaderData(4, Qt::Horizontal, QObject::tr("role"));
 return model;
     }
QSqlQueryModel *employee::tri_employee()

    {
        QSqlQueryModel * model= new QSqlQueryModel();

        model->setQuery("select * from EMPLOYE order by ID_EMP");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("NOM"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("PRENOM"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("CIN"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("ROLE"));





        return model;

}
