#include "updateWindow.h"
#include <QLabel>
#include <QGridLayout>
#include <QPushButton>
#include "car.h"
#include "messageWindow.h"
using namespace std;
UpdateWindow::UpdateWindow(QWidget *parent,DbMenager *db,Car *car): QDialog(parent){
    this->db=db;
    this->car=car;
    auto mileageLabel = new QLabel(tr("Mileage"));
    auto enginePowerLabel = new QLabel(tr("Engine power"));
    auto colourLabel = new QLabel(tr("Colour"));
    auto okButton = new QPushButton(tr("OK"));
    auto cancelButton = new QPushButton(tr("Cancel"));



    this->mileageText = new QLineEdit;
    this->enginePowerText = new QLineEdit;
    this->colourText = new QLineEdit;
    this->mileageText->setText((to_string(car->getMileage()).c_str()));
    this->enginePowerText->setText((to_string(car->getEnginePower()).c_str()));
    this->colourText->setText(car->getColour().c_str());

    auto layout = new QGridLayout;

    layout->setColumnStretch(1, 2);

    layout->addWidget(mileageLabel,0,0);
    layout->addWidget(mileageText,0,1);

    layout->addWidget(enginePowerLabel,1,0);
    layout->addWidget(enginePowerText,1,1);

    layout->addWidget(colourLabel,2,0);
    layout->addWidget(colourText,2,1);


    auto buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget(okButton);
    buttonLayout->addWidget(cancelButton);

    layout->addLayout(buttonLayout, 3, 1, Qt::AlignRight);

    auto mainLayout = new QVBoxLayout;
    mainLayout->addLayout(layout);
    setLayout(mainLayout);

    connect(okButton, &QAbstractButton::clicked, this, &QDialog::accept);
    connect(cancelButton, &QAbstractButton::clicked, this, &QDialog::reject);

    setWindowTitle("Update car");

}

bool UpdateWindow::updateWin(){

    if(this->colourText->text().toStdString().empty()) {
        MessageWindow mw(this,"Colour was empty");
        mw.exec();
        return false;
    }
    if(this->mileageText->text().toStdString().empty()) {
        MessageWindow mw(this,"Mileage was empty");
        mw.exec();
        return false;
    }
    if(this->enginePowerText->text().toStdString().empty()) {
        MessageWindow mw(this,"Engine power was empty");
        mw.exec();
        return false;
    }

    int mileage;
    int enginePower;
    string colour;

    try {
        colour = this->colourText->text().toStdString();
        mileage = stol(this->mileageText->text().toStdString());
        enginePower = stol(this->enginePowerText->text().toStdString());
    }catch(invalid_argument e){
        MessageWindow mw(this,"Invalid argument");
        mw.exec();
        return false;
    }catch(out_of_range e){
        MessageWindow mw(this,"Out of range");
        mw.exec();
        return false;
    }

    if(this->car->getMileage()>mileage){
        MessageWindow mw(this,"New mileage can't be less than previous");
        mw.exec();
        return false;
    }

    Car car(this->car->getVin(),this->car->getMark(),this->car->getModel(),this->car->getYear(),mileage,enginePower,colour);
    this->db->updateCarInDB(car);

    MessageWindow mw(this,"Successful update");
    mw.exec();

    return true;
}
