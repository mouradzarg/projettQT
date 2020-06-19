#include "melek.h"
#include "ui_melek.h"
#include <QMessageBox>
#include"employee.h"
#include"reclamation.h"
#include "mailing/SmtpMime"
#include<QMessageBox>
#include<QPaintEvent>
#include<QPainter>
#include<QPdfWriter>
#include<QPrinter>
#include<QFileDialog>
#include<QTextDocument>

melek::melek(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::melek)
{
    ui->setupUi(this);
    ui->tabcoli_1->setModel(tmpcoli.afficher());//refresh
    QPixmap pix("D:/integration_melek/image/back.png");
    ui->label_13->setPixmap(pix.scaled(1920,1050,Qt::KeepAspectRatio));
    QPixmap pix1("D:/integration_melek/image/back.png");
    ui->label_29->setPixmap(pix1.scaled(1920,1050,Qt::KeepAspectRatio));
}

melek::~melek()
{
    delete ui;
}

void melek::on_ajoute_congee_2_clicked()
{
    int id = ui->lineEdit_id_congee_2->text().toInt();

int cin= ui->lineEdit_cin_2->text().toInt();

    QString type= ui->lineEdit_type_2->text();






  reclamation co(id,cin,type);
  bool test=co.ajouter();
  if(test)

 {ui->tabcongee_2->setModel(tmpcongee.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter un reclamation"),
                  QObject::tr("reclamation ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un reclamation"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
}

void melek::on_AjoutEmployer_clicked()
{
    int id = ui->lineEdit_ID->text().toInt();


    QString nom= ui->lineEdit_nomExpediteur->text();
    QString prenom= ui->lineEdit_nom_prenom_Destinatire->text();
    int cin= ui->lineEdit_adresseDestinatire->text().toInt();


    QString role= ui->lineEdit_objet->text();

  employee C(id,nom,prenom,cin,role);
  bool test=C.ajouter();
  if(test)

 {ui->tabcoli_1->setModel(tmpcoli.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter un emplo"),
                  QObject::tr("emplyeé ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un employ"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);


}

void melek::on_ajouter_6_clicked()
{
    int  id = ui->lineEdit_ID->text().toInt();

    int  cin = ui->lineEdit_adresseDestinatire->text().toInt();
    QString nom = ui->lineEdit_nomExpediteur->text();
    QString prenom = ui->lineEdit_nom_prenom_Destinatire->text();
    QString role = ui->lineEdit_objet->text();

    employee c;
    bool test=c.modifier(id,nom,prenom,cin,role);
    if(test)
    {  ui->tabcoli_1->setModel(tmpcoli.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("mod emplyee"),
                           QObject::tr("modif successful.\n"
                                       "Click Cancel to exit."), QMessageBox::Cancel);

    }
           else
               QMessageBox::information(nullptr, QObject::tr("mod emplyee "),
                           QObject::tr("modif failed.\n"
                                       "Click Cancel to exit."), QMessageBox::Cancel);

}

void melek::on_ajouter_7_clicked()
{
    long id=ui->lineEdit_ID_3->text().toLong();
    bool test=tmpcoli.supprimer(id);
    if(test)
    {ui->tabcoli_1->setModel(tmpcoli.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer un employe"),
                    QObject::tr("eemplyeé supprimé.\n"
                                                       "Click Cancel to exit."), QMessageBox::Cancel);


    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un emplyee"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void melek::on_pushButton_13_clicked()
{
    QString nom =ui->lineEdit_rech->text();
    ui->tabcoli_1->setModel(tmpcoli.rechercher(nom));
}

void melek::on_pushButton_14_clicked()
{

        employee C ;
             ui->tabcoli_1->setModel(tmpcoli.tri_employee());
}



void melek::on_pushButton_5_clicked()
{
    QString str;
           str.append("<html><head></head><body><center>"+QString("&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;;<font size=""10"" color =""red""> GESTION DES employess </font><br /> <br /> "));
           str.append("<table border=1><tr>");
           str.append("<td>"+QString("  ")+"&nbsp;&nbsp;<font color =""blue""  size=""10""id</font>&nbsp;&nbsp;"+"</td>");
           str.append("<td>"+QString("&nbsp;&nbsp;<font color =""blue""  size=""10"">cin </font>&nbsp;&nbsp;")+"</td>");

           str.append("<td>"+QString("&nbsp;&nbsp;<font color =""blue""  size=""10"">type </font>&nbsp;&nbsp;")+"</td>");
          // str.append("<td>"+QString("&nbsp;&nbsp;<font color =""blue""  size=""10"">dispo</font>&nbsp;&nbsp;")+"</td>");

           QSqlQuery * query=new QSqlQuery();
           query->exec("SELECT * FROM EMPLOYE");
           while(query->next())
           {
               str.append("<tr><td>");
               str.append("&nbsp;&nbsp;<font color =""green"" size= ""10"">"+query->value(0).toString()+"&nbsp;&nbsp;");
               str.append("</td><td>");
               str.append("&nbsp;&nbsp;<font color =""green""  size=""10"">"+query->value(1).toString()+"&nbsp;&nbsp;");
               str.append("</td><td>");
               str.append("&nbsp;&nbsp;<font color =""green"" size=""10"">"+query->value(2).toString()+"&nbsp;&nbsp;");
               str.append("</td><td>");

       }
           str.append("</table></center><body></html>");
           QPrinter printer;
           printer.setOrientation(QPrinter::Portrait);
           printer.setOutputFormat(QPrinter::PdfFormat);
           printer.setPaperSize(QPrinter::A4);
           QString path= QFileDialog::getSaveFileName(NULL,"imprimer","gestion des emplopyess","PDF(*.pdf");
            if(path.isEmpty()) return;
            printer.setOutputFileName(path);
            QTextDocument doc;
            doc.setHtml(str);
            doc.print(&printer);
}

void melek::on_modifier_congee_2_clicked()
{
    int  id = ui->lineEdit_id_congee_2->text().toInt();

    int  cin = ui->lineEdit_cin_2->text().toInt();
    QString type = ui->lineEdit_type_2->text();

    reclamation c;
    bool test=c.modifier(id,cin,type);
    if(test)
    {  ui->tabcongee_2->setModel(tmpcongee.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("mod recla"),
                           QObject::tr("modif successful.\n"
                                       "Click Cancel to exit."), QMessageBox::Cancel);

    }
           else
               QMessageBox::information(nullptr, QObject::tr("mod recla "),
                           QObject::tr("modif failed.\n"
                                       "Click Cancel to exit."), QMessageBox::Cancel);

}

void melek::on_supp_congee_2_clicked()
{
    long id=ui->lineEdit_id_supp_2->text().toLong();
    bool test=tmpcongee.supprimer(id);
    if(test)
    {ui->tabcongee_2->setModel(tmpcongee.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer un recla"),
                    QObject::tr("recla supprimé.\n"
                                                       "Click Cancel to exit."), QMessageBox::Cancel);


    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un recla"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void melek::on_trier_congee_2_clicked()
{
    reclamation C ;
         ui->tabcongee_2->setModel(tmpcongee.tri_congee());
}

void melek::on_pushButton_10_clicked()
{
    QString str;
           str.append("<html><head></head><body><center>"+QString("&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;;<font size=""10"" color =""red""> GESTION DES reclamation </font><br /> <br /> "));
           str.append("<table border=1><tr>");
           str.append("<td>"+QString("  ")+"&nbsp;&nbsp;<font color =""blue""  size=""10""id</font>&nbsp;&nbsp;"+"</td>");
           str.append("<td>"+QString("&nbsp;&nbsp;<font color =""blue""  size=""10"">cin </font>&nbsp;&nbsp;")+"</td>");

           str.append("<td>"+QString("&nbsp;&nbsp;<font color =""blue""  size=""10"">type </font>&nbsp;&nbsp;")+"</td>");
          // str.append("<td>"+QString("&nbsp;&nbsp;<font color =""blue""  size=""10"">dispo</font>&nbsp;&nbsp;")+"</td>");

           QSqlQuery * query=new QSqlQuery();
           query->exec("SELECT * FROM CONGEE");
           while(query->next())
           {
               str.append("<tr><td>");
               str.append("&nbsp;&nbsp;<font color =""green"" size= ""10"">"+query->value(0).toString()+"&nbsp;&nbsp;");
               str.append("</td><td>");
               str.append("&nbsp;&nbsp;<font color =""green""  size=""10"">"+query->value(1).toString()+"&nbsp;&nbsp;");
               str.append("</td><td>");
               str.append("&nbsp;&nbsp;<font color =""green"" size=""10"">"+query->value(2).toString()+"&nbsp;&nbsp;");
               str.append("</td><td>");

       }
           str.append("</table></center><body></html>");
           QPrinter printer;
           printer.setOrientation(QPrinter::Portrait);
           printer.setOutputFormat(QPrinter::PdfFormat);
           printer.setPaperSize(QPrinter::A4);
           QString path= QFileDialog::getSaveFileName(NULL,"imprimer","gestion des reclamations","PDF(*.pdf");
            if(path.isEmpty()) return;
            printer.setOutputFileName(path);
            QTextDocument doc;
            doc.setHtml(str);
            doc.print(&printer);
}

void melek::on_recherche_congee_2_clicked()
{
    QString type =ui->lineEdit_id_rech_2->text();
    ui->tabcongee_2->setModel(tmpcongee.rechercher(type));
}
