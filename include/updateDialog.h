
#ifndef V3_UPDATEDIALOG_H
#define V3_UPDATEDIALOG_H




#include <QDialog>
#include <QtWidgets/QLineEdit>
#include "dbMenager.h"

class UpdateDialog : public QDialog {
private:
    DbMenager *db;
    QLineEdit *vinText;


public:
    UpdateDialog(QWidget *parent = nullptr,DbMenager *db = nullptr);
    bool updateCar();

};



#endif //V3_UPDATEDIALOG_H
