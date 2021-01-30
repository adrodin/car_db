
#ifndef V3_FINDDIALOG_H
#define V3_FINDDIALOG_H


#include <QDialog>
#include <QtWidgets/QLineEdit>
#include "dbMenager.h"

class FindDialog : public QDialog {
private:
    DbMenager *db;
    QLineEdit *vinText;


public:
    FindDialog(QWidget *parent = nullptr,DbMenager *db = nullptr);
    bool findCar();

};
#endif //V3_FINDDIALOG_H
