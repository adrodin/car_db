

#ifndef V3_UPDATEWINDOW_H
#define V3_UPDATEWINDOW_H
#include <QDialog>
#include "dbMenager.h"
#include "car.h"
#include <QLineEdit>
class UpdateWindow : public QDialog {
private:
    DbMenager *db;
    Car *car;
    QLineEdit *enginePowerText;
    QLineEdit *mileageText;
    QLineEdit *colourText;

public:
    UpdateWindow(QWidget *parent = nullptr,DbMenager *db = nullptr,Car *car =nullptr);
    bool updateWin();

};
#endif //V3_UPDATEWINDOW_H
