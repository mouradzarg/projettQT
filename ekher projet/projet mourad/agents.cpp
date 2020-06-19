#include "agents.h"

Agents::Agents()
{
    ID=0;
    Nom="";
    Prenom="";
    MotDePasse="";
    Adresse="";
    Role="";
}

Agents::Agents(int id,QString nom,QString prenom,QString motdepasse,QString adresse,QString role)
{
    this->ID=id;
    this->Nom=nom;
    this->Prenom=prenom;
    this->MotDePasse=motdepasse;
    this->Adresse=adresse;
    this->Role=role;
}

int Agents::get_ID(){return ID;}
QString Agents::get_Nom(){return Nom;}
QString Agents::get_Prenom(){return Prenom;}
QString Agents::get_MotDePasse(){return MotDePasse;}
QString Agents::get_Adresse(){return Adresse;}
QString Agents::get_Role(){return Role;}

bool Agents::Ajouter_Agents()
{
    QSqlQuery query;
    QString res= QString::number(ID);
    query.prepare("INSERT INTO AGENTS (ID, NOM, PRENOM, MOTDEPASSE, ADRESSE, ROLE) "
                        "VALUES (:Id, :Nom, :Prenom, :Motdepasse, :Adresse, :Role)");
    query.bindValue(":Id", res);
    query.bindValue(":Nom", Nom);
    query.bindValue(":Prenom", Prenom);
    query.bindValue(":Motdepasse", MotDePasse );
    query.bindValue(":Adresse", Adresse);
    query.bindValue(":Role", Role);

    return    query.exec();
}

QSqlQueryModel * Agents::Afficher_Agents()
{
    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("SELECT * FROM AGENTS");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM "));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("MOTDEPASSE"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("ADRESSE"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("ROLE"));
    return model;
}

bool Agents::Supprimer_Agents()
{
QSqlQuery query;
QString res= QString::number(ID);
query.prepare("DELETE FROM AGENTS WHERE ID = :Id ");
query.bindValue(":Id", res);
return    query.exec();
}

bool Agents::Modifier_Agents()
{

        QSqlQuery query ;
        QString res=QString::number(ID);
        query.prepare("UPDATE AGENTS SET NOM=:Nom, PRENOM=:Prenom, MOTDEPASSE=:Motdepasse, ADRESSE=:Adresse,ROLE=:Role where ID=:Id ");
                query.bindValue(":Id",res);
                query.bindValue(":Nom", Nom );
                query.bindValue(":Prenom", Prenom );
                query.bindValue(":Motdepasse", MotDePasse );
                query.bindValue(":Adresse", Adresse);
                query.bindValue(":Role", Role);
                return query.exec();

}

bool Agents::Login(int, QString)
{
    int i=0;
    QSqlQuery query;
 QString res=QString::number(ID);
    query.prepare(" SELECT ID FROM AGENTS WHERE ID =:Id AND MOTDEPASSE=:Motdepasse  ");
    query.bindValue(":Id",res);
    query.bindValue(":Motdepasse", MotDePasse );
    query.exec();
    while(query.next()==true)
    {
    i++;
    }

    if(i==0)
    {
        return  false;
    }

    return true ;
}
