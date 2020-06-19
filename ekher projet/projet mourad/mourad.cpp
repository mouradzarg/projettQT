#include "mourad.h"
#include "ui_mourad.h"
#include"coli.h"
#include"courrier.h"
#include<QMessageBox>
#include "mailing/SmtpMime"

mourad::mourad(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::mourad)
{
    ui->setupUi(this);
    ui->tabcoli_1->setModel(tmpcoli.afficher());//refresh
}

mourad::~mourad()
{
    delete ui;
}

void mourad::on_pushButton_7_clicked()
{
     ui->stackedWidget->setCurrentIndex(1);
}

void mourad::on_pushButton_8_clicked()
{
     ui->stackedWidget->setCurrentIndex(2);
}

void mourad::on_ajouter_5_clicked()
{
    coli C1;
       if(ui->lineEdit_nomExpediteur->text()=="" || ui->lineEdit_nomExpediteur->text()=="   *champ obligatoire")
               ui->lineEdit_nomExpediteur->setText("   *champ obligatoire");
       if(ui->lineEdit_nom_prenom_Destinatire->text()=="" || ui->lineEdit_nom_prenom_Destinatire->text()=="   *champ obligatoire")
               ui->lineEdit_nom_prenom_Destinatire->setText("   *champ obligatoire");
       if(ui->lineEdit_adresseDestinatire->text()=="" || ui->lineEdit_adresseDestinatire->text()=="   *champ obligatoire")
               ui->lineEdit_adresseDestinatire->setText("   *champ obligatoire");
       if(ui->lineEdit_objet->text()=="" || ui->lineEdit_objet->text()=="   *champ obligatoire")
               ui->lineEdit_objet->setText("   *champ obligatoire");

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
}

void mourad::on_ajouter_6_clicked()
{
    int ID = ui->lineEdit_ID->text().toInt();
    QString nom_prenom_Expediteur= ui->lineEdit_nomExpediteur->text();

    QString nom_prenom_Destinatire= ui->lineEdit_nom_prenom_Destinatire->text();

    QString adresseDestinatire= ui->lineEdit_adresseDestinatire->text();
    QString objet= ui->lineEdit_objet->text();

    QString dimension= ui->lineEdit_dimension->text();
    QString poid= ui->lineEdit_poid->text();
      QString statut= ui->comboBox_statut1_2->currentText();

        bool test=tmpcoli.modifier(statut,nom_prenom_Expediteur,nom_prenom_Expediteur,adresseDestinatire,objet,dimension,poid,ID);
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

void mourad::on_ajouter_7_clicked()
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

void mourad::on_pb_ajouter_11_clicked()
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

void mourad::on_pushButton_5_clicked()
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



             " \n\n\nCordialement.");

    message.addPart(&text);

    smtp.connectToHost();
    smtp.login();
    smtp.sendMail(message);
    smtp.quit();
}

void mourad::on_tabcoli_1_activated(const QModelIndex &index)
{
    ui->lineEdit_ID->setText(ui->tabcoli_1->model()->data(ui->tabcoli_1->model()->index(ui->tabcoli_1->currentIndex().row(),0)).toString());
    ui->lineEdit_nomExpediteur->setText(ui->tabcoli_1->model()->data(ui->tabcoli_1->model()->index(ui->tabcoli_1->currentIndex().row(),1)).toString());
     ui->lineEdit_nom_prenom_Destinatire->setText(ui->tabcoli_1->model()->data(ui->tabcoli_1->model()->index(ui->tabcoli_1->currentIndex().row(),2)).toString());
    ui->lineEdit_adresseDestinatire->setText(ui->tabcoli_1->model()->data(ui->tabcoli_1->model()->index(ui->tabcoli_1->currentIndex().row(),3)).toString());
    ui->lineEdit_objet->setText(ui->tabcoli_1->model()->data(ui->tabcoli_1->model()->index(ui->tabcoli_1->currentIndex().row(),4)).toString());
    ui->lineEdit_dimension->setText(ui->tabcoli_1->model()->data(ui->tabcoli_1->model()->index(ui->tabcoli_1->currentIndex().row(),5)).toString());
    ui->lineEdit_poid->setText(ui->tabcoli_1->model()->data(ui->tabcoli_1->model()->index(ui->tabcoli_1->currentIndex().row(),5)).toString());

}

void mourad::on_radioButton_24_toggled(bool checked)
{
    coli C ;
    ui->tabcoli_5->setModel(C.trier(ui->radioButton_21->isChecked(),checked));
}

void mourad::on_ajoute_cour_clicked()
{
    int id = ui->lineEdit_id_courrier->text().toInt();
    QString nom_prenom_expediteur= ui->lineEdit_expediteur->text();
    QString nom_prenom_destinataire= ui->lineEdit_destinataire->text();
    QString adresseDestinatire= ui->lineEdit_destinataire_2->text();

    QString staut_courrier= ui->comboBox_statut1->currentText();


    courrier c(id,nom_prenom_expediteur,nom_prenom_destinataire,staut_courrier,adresseDestinatire);
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

void mourad::on_modifier_cour_2_clicked()
{
     int id_courrier = ui->lineEdit_ID_courrier_1->text().toInt();
    QString nom_prenom_expediteur= ui->lineEdit_expediteur->text();
    QString nom_prenom_destinataire= ui->lineEdit_destinataire->text();

    QString adresseDestinatire= ui->lineEdit_destinataire_2->text();

    QString staut_courrier= ui->comboBox_statut->currentText();

        bool test=tmpcourrier.modifier(staut_courrier,nom_prenom_expediteur,nom_prenom_destinataire,adresseDestinatire,id_courrier);
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

void mourad::on_pushButton_6_clicked()
{
    SmtpClient smtp("smtp.gmail.com", 465, SmtpClient::SslConnection);

    smtp.setUser("mouradzarga111@gmail.cocm");
    smtp.setPassword("181JMT2802");


    MimeMessage message;

    message.setSender(new EmailAddress("mouradzarga111@gmail.com", "Admin"));
    message.addRecipient(new EmailAddress("mourad.zargelayoun@esprit.tn", "zarga"));
    message.setSubject("une promotion ");

    MimeText text;

    text.setText(" Bonjour"

             " \n\nC’est avec un grand plaisir que j'ai accepté de vous écrire ces quelques mots de bienvenue au nom de notre societe"


             " \n\n\nCordialement.");

    message.addPart(&text);

    smtp.connectToHost();
    smtp.login();
    smtp.sendMail(message);
    smtp.quit();
}

void mourad::on_ajouter_8_clicked()
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

void mourad::on_pb_ajouter_10_clicked()
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

void mourad::on_radioButton_30_toggled(bool checked)
{
    courrier c;
    ui->tabcourrier_6->setModel(c.trier(ui->radioButton_27->isChecked(),checked));
}

void mourad::on_tabcourrier_1_activated(const QModelIndex &index)
{

        ui->lineEdit_id_courrier->setText(ui->tabcourrier_1->model()->data(ui->tabcourrier_1->model()->index(ui->tabcourrier_1->currentIndex().row(),0)).toString());
        ui->lineEdit_expediteur->setText(ui->tabcourrier_1->model()->data(ui->tabcourrier_1->model()->index(ui->tabcourrier_1->currentIndex().row(),1)).toString());
        ui->lineEdit_destinataire->setText(ui->tabcourrier_1->model()->data(ui->tabcourrier_1->model()->index(ui->tabcourrier_1->currentIndex().row(),2)).toString());
        ui->lineEdit_destinataire_2->setText(ui->tabcourrier_1->model()->data(ui->tabcourrier_1->model()->index(ui->tabcourrier_1->currentIndex().row(),3)).toString());



}
