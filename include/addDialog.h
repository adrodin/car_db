#ifndef V3_ADDDIALOG_H
#define V3_ADDDIALOG_H

#include <QDialog>
#include <QtWidgets/QLineEdit>
#include "car.h"
#include "dbMenager.h"

class AddDialog : public QDialog {
private:
    DbMenager *db;
    QLineEdit *vinText;
    QLineEdit *markText;
    QLineEdit *modelText;
    QLineEdit *yearText;
    QLineEdit *mileageText;
    QLineEdit *enginePowerText;
    QLineEdit *colourText;
public:
    AddDialog(QWidget *parent = nullptr,DbMenager *db=nullptr);
    bool getCar();


};

#endif //V3_ADDDIALOG_H
