
#ifndef V3_SHOWCAR_H
#define V3_SHOWCAR_H

#include "QDialog"
#include "car.h"
#include <QLineEdit>
class ShowCar : public QDialog {
private:
    QLineEdit *vinText;
    QLineEdit *markText;
    QLineEdit *modelText;
    QLineEdit *yearText;
    QLineEdit *mileageText;
    QLineEdit *enginePowerText;
    QLineEdit *colourText;
public:
    ShowCar(QWidget *parent = nullptr,Car *car=nullptr);



};
#endif //V3_SHOWCAR_H
