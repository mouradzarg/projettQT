#include "fred.h"
#include "ui_fred.h"
#include <QObject>
#include <QMessageBox>

fred::fred(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::fred)
{
    ui->setupUi(this);
}

fred::~fred()
{
    delete ui;
}

void fred::on_Ajouter_Agents_clicked()
{
    int Id =ui->ID_Agents->text().toInt();
    QString Nom= ui->Nom_Agents->text();
    QString Prenom= ui->Prenom_Agents->text();
    QString MotDePasse= ui->Motdepasse_Agents->text();
    QString Adresse= ui->Adresse_Agents->text();
    QString Role=ui->Role_Agents->currentText();
  Agents a(Id,Nom,Prenom,MotDePasse,Adresse,Role);
  bool test=a.Ajouter_Agents();
  if(test)
{ ui->TabAgents->setModel(tmpAgents.Afficher_Agents());
QMessageBox::information(nullptr, QObject::tr("Ajouter un utilisateur"),
                  QObject::tr("utilisateur ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un utilisateur"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}

void fred::on_Modifier_Agents_clicked()
{
    if(ui->TabAgents->currentIndex().row()==-1)
        QMessageBox::information(nullptr, QObject::tr("Modification"),
                          QObject::tr("Veuillez Choisir un agent.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
    else
    {
         Agents tmp(ui->TabAgents->model()->data(ui->TabAgents->model()->index(ui->TabAgents->currentIndex().row(),0)).toInt(),ui->Nom_Agents->text(),ui->Prenom_Agents->text(),ui->Motdepasse_Agents->text(),ui->Adresse_Agents->text(),ui->Role_Agents->currentText());
        if(tmp.Modifier_Agents())
        {
            ui->TabAgents->setModel(tmp.Afficher_Agents());

            QMessageBox::information(nullptr, QObject::tr("Modification"),
                              QObject::tr("Success.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
        }
        else
        {
            QMessageBox::information(nullptr, QObject::tr("Modification"),
                              QObject::tr("Erreur.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
        }
    }
}

void fred::on_Supprimer_Agents_clicked()
{
    if(ui->TabAgents->currentIndex().row()==-1)
        QMessageBox::information(nullptr, QObject::tr("Suppression"),
                          QObject::tr("Veuillez Choisir un agent.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
    else
    {
         Agents tmp(ui->TabAgents->model()->data(ui->TabAgents->model()->index(ui->TabAgents->currentIndex().row(),0)).toInt(),ui->Nom_Agents->text(),ui->Prenom_Agents->text(),ui->Motdepasse_Agents->text(),ui->Adresse_Agents->text(),ui->Role_Agents->currentText());
        if(tmp.Supprimer_Agents())
        {
            ui->TabAgents->setModel(tmp.Afficher_Agents());

            QMessageBox::information(nullptr, QObject::tr("Suppression"),
                              QObject::tr("Success.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
        }
        else
        {
            QMessageBox::information(nullptr, QObject::tr("Suppression"),
                              QObject::tr("Erreur.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
        }
    }
}

void fred::on_Afficher_Agents_clicked()
{
    ui->TabAgents->setModel(tmpAgents.Afficher_Agents());
   }


void fred::on_Ajouter_Conges_clicked()
{
    QString Typeconges= ui->Type_Conge->currentText();
    QDate Debut_conges= ui->Date_Conge->date();
    QDate Date_fin_conges= ui->Date_Fin_Conge->date();

  Conges c(Typeconges,Debut_conges,Date_fin_conges);
  bool test=c.Ajouter_Conges();
  if(test)
{ ui->Tab_Conges->setModel(tmpConges.Afficher_Conges());
QMessageBox::information(nullptr, QObject::tr("Ajouter un conge"),
                  QObject::tr("conge ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un conge"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
}

void fred::on_Modifier_Conges_clicked()
{
    if(ui->Tab_Conges->currentIndex().row()==-1)
        QMessageBox::information(nullptr, QObject::tr("Modification"),
                          QObject::tr("Veuillez Choisir un conge.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
    else
    {
         Conges tmp(ui->Tab_Conges->model()->data(ui->Tab_Conges->model()->index(ui->Tab_Conges->currentIndex().row(),0)).toString(),ui->Date_Conge->date(),ui->Date_Fin_Conge->date());
        if(tmp.Modifier_Conges())
        {
            ui->Tab_Conges->setModel(tmp.Afficher_Conges());

            QMessageBox::information(nullptr, QObject::tr("Modification"),
                              QObject::tr("Success.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
        }
        else
        {
            QMessageBox::information(nullptr, QObject::tr("Modification"),
                              QObject::tr("Erreur.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
        }
    }
}

void fred::on_Supprimer_Conges_clicked()
{
    if(ui->Tab_Conges->currentIndex().row()==-1)
        QMessageBox::information(nullptr, QObject::tr("Supression"),
                          QObject::tr("Veuillez Choisir un conge.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
    else
    {
         Conges tmp(ui->Tab_Conges->model()->data(ui->Tab_Conges->model()->index(ui->Tab_Conges->currentIndex().row(),0)).toString(),ui->Date_Conge->date(),ui->Date_Fin_Conge->date());
        if(tmp.Supprimer_Conges())
        {
            ui->Tab_Conges->setModel(tmp.Afficher_Conges());

            QMessageBox::information(nullptr, QObject::tr("Supression"),
                              QObject::tr("Success.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
        }
        else
        {
            QMessageBox::information(nullptr, QObject::tr("Supression"),
                              QObject::tr("Erreur.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
        }
    }
}

void fred::on_Afficher_Conges_clicked()
{
    ui->Tab_Conges->setModel(tmpConges.Afficher_Conges());


}

void fred::on_Tab_Conges_activated(const QModelIndex &index)
{
    ui->Type_Conge->setCurrentText(ui->Tab_Conges->model()->data(ui->Tab_Conges->model()->index(ui->Tab_Conges->currentIndex().row(),0)).toString());
    ui->Date_Conge->setDate(ui->Tab_Conges->model()->data(ui->Tab_Conges->model()->index(ui->Tab_Conges->currentIndex().row(),1)).toDate());
    ui->Date_Fin_Conge->setDate(ui->Tab_Conges->model()->data(ui->Tab_Conges->model()->index(ui->Tab_Conges->currentIndex().row(),2)).toDate());
}

void fred::on_TabAgents_activated(const QModelIndex &index)
{
    ui->ID_Agents->setText(ui->TabAgents->model()->data(ui->TabAgents->model()->index(ui->TabAgents->currentIndex().row(),0)).toString());
    ui->Nom_Agents->setText(ui->TabAgents->model()->data(ui->TabAgents->model()->index(ui->TabAgents->currentIndex().row(),1)).toString());
    ui->Prenom_Agents->setText(ui->TabAgents->model()->data(ui->TabAgents->model()->index(ui->TabAgents->currentIndex().row(),2)).toString());
    ui->Motdepasse_Agents->setText(ui->TabAgents->model()->data(ui->TabAgents->model()->index(ui->TabAgents->currentIndex().row(),3)).toString());
    ui->Adresse_Agents->setText(ui->TabAgents->model()->data(ui->TabAgents->model()->index(ui->TabAgents->currentIndex().row(),4)).toString());
    ui->Role_Agents->setCurrentText(ui->TabAgents->model()->data(ui->TabAgents->model()->index(ui->TabAgents->currentIndex().row(),5)).toString());
}

void fred::on_Retour_Agents_clicked()
{
     ui->stackedWidget->setCurrentIndex(3);
}

void fred::on_Retour_Conges_clicked()
{
  ui->stackedWidget->setCurrentIndex(2);
}
