#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "coli.h"
#include "courrier.h"
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pb_ajouter_5_clicked()
{
    int ID = ui->lineEdit_ID->text().toInt();
    QString nomExpediteur= ui->lineEdit_nomExpediteur->text();
    QString prenomExpediteur= ui->lineEdit_prenomExpediteur->text();
    QString nomDestinatire= ui->lineEdit_nomDestinatire->text();
    QString prenomDestinatire= ui->lineEdit_prenomDestinatire->text();
    QString adresseDestinatire= ui->lineEdit_adresseDestinatire->text();
    QString objet= ui->lineEdit_objet->text();

    QString dimension= ui->lineEdit_dimension->text();
    QString poid= ui->lineEdit_poid->text();
      QString statut= ui->lineEdit_statut->text();
  coli C(ID,nomExpediteur,prenomExpediteur,nomDestinatire,prenomDestinatire,adresseDestinatire,objet,dimension,poid,statut);
  bool test=C.ajouter();
  if(test)

 {ui->tabcoli_1->setModel(tmpcoli.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter un coli"),
                  QObject::tr("coli ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un coli"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
}


void MainWindow::on_pb_ajouter_6_clicked()
{
    QString statut= ui->lineEdit_statut_2->text();

    int ID = ui->lineEdit_ID_2->text().toInt();

        bool test=tmpcoli.modifier(statut,ID);
        if(test)
        {ui->tabcoli_1->setModel(tmpcoli.afficher());//refresh
            QMessageBox::information(nullptr, QObject::tr("modifier un coli"),
                        QObject::tr("coli modifier.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

        }
        else
            QMessageBox::critical(nullptr, QObject::tr("modifier un coli"),
                        QObject::tr("Erreur !.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
}
void MainWindow::on_pb_ajouter_7_clicked()
{

    long ID=ui->lineEdit_ID_3->text().toLong();
    bool test=tmpcoli.supprimer(ID);
    if(test)
    {ui->tabcoli_1->setModel(tmpcoli.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer un coli"),
                    QObject::tr("coli supprimé.\n"
                                                       "Click Cancel to exit."), QMessageBox::Cancel);


    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un coli"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
         }


void MainWindow::on_ajoute_cour_clicked()
{
    int id_courrier = ui->lineEdit_id_courrier->text().toInt();
    QString expediteur= ui->lineEdit_expediteur->text();
    QString destinataire= ui->lineEdit_destinataire->text();
    QString staut_courrier= ui->comboBox_statut1->currentText();

    courrier c(id_courrier,expediteur,destinataire,staut_courrier);
  bool test=c.ajouter();
  if(test)
{ui->tabcourrier_1->setModel(tmpcourrier.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter un courrier"),
                  QObject::tr("courrier ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un courrier "),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
}
void MainWindow::on_modifier_cour_2_clicked()
{
    QString staut_courrier= ui->comboBox_statut->currentText();

    int id_courrier = ui->lineEdit_ID_courrier_1->text().toInt();

        bool test=tmpcourrier.modifier(staut_courrier,id_courrier);
        if(test)
        {ui->tabcourrier_1->setModel(tmpcourrier.afficher());//refresh
            QMessageBox::information(nullptr, QObject::tr("modifier un courrier"),
                        QObject::tr("courrier modifier.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

        }
        else
            QMessageBox::critical(nullptr, QObject::tr("modifier un courrier"),
                        QObject::tr("Erreur !.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pb_ajouter_8_clicked()
{
    int id_courrier = ui->lineEdit_id_courrier_3->text().toInt();
    bool test=tmpcourrier.supprimer(id_courrier);
    if(test)
    {ui->tabcourrier_1->setModel(tmpcourrier.afficher());//refresh


        QMessageBox::information(nullptr, QObject::tr("Supprimer un courrier"),
                    QObject::tr("courrier supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un courrier"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
         }
void MainWindow::on_pb_ajouter_10_clicked()
{
    QString nomDestinatire = ui->lineEdit_name_4->text();
    QString prenomDestinatire = ui->lineEdit_name_5->text();

     ui->tabcoli_2->setModel(tmpcoli.rechercher(nomDestinatire));

         bool test=tmpcoli.rechercher(nomDestinatire);

         if(test)
         {ui->tabcoli_2->setModel(tmpcoli.rechercher(nomDestinatire));//refresh

             QMessageBox::information(nullptr, QObject::tr("chercher un coli"),
                         QObject::tr("coli trouve.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);

         }
         else
             QMessageBox::critical(nullptr, QObject::tr("chercher un coli"),
                         QObject::tr("Erreur !.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);
}
void MainWindow::on_pb_ajouter_11_clicked()
{
    QString destinataire = ui->lineEdit_cin_4->text();
     ui->tabcourrier_2->setModel(tmpcourrier.rechercher(destinataire));

         bool test=tmpcourrier.rechercher(destinataire);
         if(test)
         {ui->tabcourrier_2->setModel(tmpcourrier.rechercher(destinataire));//refresh
             QMessageBox::information(nullptr, QObject::tr("chercher un courrier"),
                         QObject::tr("courrier trouve.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);

         }
         else
             QMessageBox::critical(nullptr, QObject::tr("chercher un courrier"),
                         QObject::tr("Erreur !.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_radioButton_24_toggled(bool checked)
{
    coli C ;
    ui->tabcoli_5->setModel(C.trier(ui->radioButton_21->isChecked(),checked));
}





void MainWindow::on_radioButton_30_toggled(bool checked)
{
    courrier c;
    ui->tabcourrier_6->setModel(c.trier(ui->radioButton_27->isChecked(),checked));


}
