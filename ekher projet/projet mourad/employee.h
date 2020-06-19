#ifndef EMPLOYEE_H
#define EMPLOYEE_H


#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
class employee
{public:
    employee();
    employee(int,QString,QString,int,QString);
    int get_id();
    QString get_nom();
    QString get_prenom();
    int get_cin();
    QString get_role();




    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier (int,QString,QString,int,QString);
   QSqlQueryModel * rechercher(QString);
    QSqlQueryModel * tri_employee();

private:
      int id,cin;
    QString nom,prenom,role;

};
#endif // EMPLOYEE_H
