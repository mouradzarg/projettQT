#include "conges.h"

Conges::Conges()
{





}
Conges::Conges(QString type_conges,QDate date_fin_conges,QDate debut_conges)
{
    this->Type_conges=type_conges;
    this->Date_fin_conges=date_fin_conges;
    this->Debut_conges=debut_conges;

}
QString Conges::get_Type_conges(){return Type_conges;}
QDate Conges::get_Date_fin_conges(){return Date_fin_conges;}
QDate Conges::get_Debut_conges(){return Debut_conges;}

bool Conges::Ajouter_Conges()
{
    QSqlQuery query;

    query.prepare("INSERT INTO CONGES (TYPE_CONGES, DEBUT_CONGES, DATE_FIN_CONGES) "
                        "VALUES (:Typeconges,:Debut_conges, :Date_fin_conges)");
    query.bindValue(":Typeconges", Type_conges);
    query.bindValue(":Debut_conges", Debut_conges);
    query.bindValue(":Date_fin_conges", Date_fin_conges);



    return    query.exec();
}

QSqlQueryModel * Conges::Afficher_Conges()
{
    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("SELECT * FROM CONGES");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("TYPECONGES"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("DEBUT_CONGES "));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("DATE_FIN_CONGES "));

    return model;
}

bool Conges::Supprimer_Conges()
{
QSqlQuery query;

query.prepare("DELETE FROM CONGES WHERE TYPE_CONGES = :Typeconges ");
query.bindValue(":Typeconges", Type_conges);
return    query.exec();
}

bool Conges::Modifier_Conges()
{

        QSqlQuery query ;

        query.prepare("UPDATE CONGES SET TYPE_CONGES=:Typeconges, DEBUT_CONGES=:Debut_conges, DATE_FIN_CONGES=:Date_fin_conges where TYPE_CONGES=:Typeconges");
                query.bindValue(":Typeconges",Type_conges);
                query.bindValue(":Debut_conges", Debut_conges );
                query.bindValue(":Date_fin_conges", Date_fin_conges );

                return query.exec();

}

