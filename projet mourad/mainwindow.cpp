#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "coli.h"
#include "courrier.h"
#include <QMessageBox>
#include "mailing/SmtpMime"
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

void MainWindow::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}
void MainWindow::on_pushButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}
void MainWindow::on_pushButton_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_ajouter_5_clicked()
{
    int ID = ui->lineEdit_ID->text().toInt();
    QString nom_prenom_Expediteur= ui->lineEdit_nomExpediteur->text();

    QString nom_prenom_Destinatire= ui->lineEdit_nom_prenom_Destinatire->text();

    QString adresseDestinatire= ui->lineEdit_adresseDestinatire->text();
    QString objet= ui->lineEdit_objet->text();

    QString dimension= ui->lineEdit_dimension->text();
    QString poid= ui->lineEdit_poid->text();
      QString statut= ui->comboBox_statut1_2->currentText();
  coli C(ID,nom_prenom_Expediteur,nom_prenom_Destinatire,adresseDestinatire,objet,dimension,poid,statut);
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


void MainWindow::on_ajouter_6_clicked()
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

void MainWindow::on_ajouter_7_clicked()
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
    int id = ui->lineEdit_id_courrier->text().toInt();
    QString nom_prenom_expediteur= ui->lineEdit_expediteur->text();
    QString nom_prenom_destinataire= ui->lineEdit_destinataire->text();
    QString staut_courrier= ui->comboBox_statut1->currentText();

    courrier c(id,nom_prenom_expediteur,nom_prenom_destinataire,staut_courrier);
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

    int id = ui->lineEdit_ID_courrier_1->text().toInt();

        bool test=tmpcourrier.modifier(staut_courrier,id);
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

void MainWindow::on_ajouter_8_clicked()
{
    int id = ui->lineEdit_id_courrier_3->text().toInt();
    bool test=tmpcourrier.supprimer(id);
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
    QString nom_prenom_destinataire = ui->lineEdit_cin_4->text();
     ui->tabcourrier_2->setModel(tmpcourrier.rechercher(nom_prenom_destinataire));

         bool test=tmpcourrier.rechercher(nom_prenom_destinataire);
         if(test)
         {ui->tabcourrier_2->setModel(tmpcourrier.rechercher(nom_prenom_destinataire));//refresh
             QMessageBox::information(nullptr, QObject::tr("chercher un courrier"),
                         QObject::tr("courrier trouve.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);

         }
         else
             QMessageBox::critical(nullptr, QObject::tr("chercher un courrier"),
                         QObject::tr("Erreur !.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);

}
void MainWindow::on_radioButton_30_toggled(bool checked)
{
    courrier c;
    ui->tabcourrier_6->setModel(c.trier(ui->radioButton_27->isChecked(),checked));


}
void MainWindow::on_pb_ajouter_11_clicked()
{
    QString nom_prenom_Destinatire = ui->lineEdit_name_4->text();


     ui->tabcoli_2->setModel(tmpcoli.rechercher(nom_prenom_Destinatire));

         bool test=tmpcoli.rechercher(nom_prenom_Destinatire);

         if(test)
         {ui->tabcoli_2->setModel(tmpcoli.rechercher(nom_prenom_Destinatire));//refresh

             QMessageBox::information(nullptr, QObject::tr("chercher un coli"),
                         QObject::tr("coli trouve.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);

         }
         else
             QMessageBox::critical(nullptr, QObject::tr("chercher un coli"),
                         QObject::tr("Erreur !.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);
}
void MainWindow::on_radioButton_24_toggled(bool checked)
{
    coli C ;
    ui->tabcoli_5->setModel(C.trier(ui->radioButton_21->isChecked(),checked));
}






void MainWindow::on_pushButton_5_clicked()
{
    SmtpClient smtp("smtp.gmail.com", 465, SmtpClient::SslConnection);

    smtp.setUser("mouradzarga111@gmail.com");
    smtp.setPassword("181JMT2802");


    MimeMessage message;

    message.setSender(new EmailAddress("mouradzarga111@gmail.com", "Admin"));
    message.addRecipient(new EmailAddress("mourad.zargelayoun@esprit.tn", "zarga"));
    message.setSubject("une promotion ");

    MimeText text;

    text.setText(" Bonjour"

             " \n\nC’est avec un grand plaisir que j'ai accepté de vous écrire ces quelques mots de bienvenue au nom de notre societe"

             " \n\nVous allez découvrir que nous menons des nouveaux promotions our nos voitures ,"

             "  si vous etes interessé n'oubliez pas de venir pour consulter nos offres"

             " \n\nNous aurons certainement aussi l’occasion de nous y croiser"

             " \n\nA bientôt donc et encore bienvenue parmi nous."

             " \n\n\nCordialement.");

    message.addPart(&text);

    smtp.connectToHost();
    smtp.login();
    smtp.sendMail(message);
    smtp.quit();
}

void MainWindow::on_pushButton_6_clicked()
{
    SmtpClient smtp("smtp.gmail.com", 465, SmtpClient::SslConnection);

    smtp.setUser("mouradzarga111@gmail.com");
    smtp.setPassword("181JMT2802");


    MimeMessage message;

    message.setSender(new EmailAddress("mouradzarga111@gmail.com", "Admin"));
    message.addRecipient(new EmailAddress("mourad.zargelayoun@esprit.tn", "zarga"));
    message.setSubject("une promotion ");

    MimeText text;

    text.setText(" Bonjour"

             " \n\nC’est avec un grand plaisir que j'ai accepté de vous écrire ces quelques mots de bienvenue au nom de notre societe"

             " \n\nVous allez découvrir que nous menons des nouveaux promotions our nos voitures ,"

             "  si vous etes interessé n'oubliez pas de venir pour consulter nos offres"

             " \n\nNous aurons certainement aussi l’occasion de nous y croiser"

             " \n\nA bientôt donc et encore bienvenue parmi nous."

             " \n\n\nCordialement.");

    message.addPart(&text);

    smtp.connectToHost();
    smtp.login();
    smtp.sendMail(message);
    smtp.quit();
}
