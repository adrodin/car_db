#include "updateDialog.h"
#include <QLabel>
#include <QGridLayout>
#include <QPushButton>
#include "car.h"
#include "messageWindow.h"
#include "updateWindow.h"
using namespace std;
UpdateDialog::UpdateDialog(QWidget *parent,DbMenager *db): QDialog(parent){
    this->db=db;
    auto vinLabel = new QLabel(tr("Vin"));
    auto okButton = new QPushButton(tr("OK"));
    auto cancelButton = new QPushButton(tr("Cancel"));

    this->vinText = new QLineEdit;

    auto layout = new QGridLayout;

    layout->setColumnStretch(1, 2);

    layout->addWidget(vinLabel,0,0);
    layout->addWidget(vinText,0,1);


    auto buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget(okButton);
    buttonLayout->addWidget(cancelButton);

    layout->addLayout(buttonLayout, 1, 1, Qt::AlignRight);

    auto mainLayout = new QVBoxLayout;
    mainLayout->addLayout(layout);
    setLayout(mainLayout);

    connect(okButton, &QAbstractButton::clicked, this, &QDialog::accept);
    connect(cancelButton, &QAbstractButton::clicked, this, &QDialog::reject);

    setWindowTitle("Find car in database");

}

bool UpdateDialog::updateCar(){
    string vin = this->vinText->text().toStdString();

    if(!Car::checkVin(vin)){
        MessageWindow mw(this,"Wrong vin length");
        mw.exec();
        return false;
    }
    if(!db->isInDB(vin)){
        MessageWindow mw(this,"No car in db");
        mw.exec();
        return false;
    }
    Car car = this->db->find(vin);
    UpdateWindow uw(this,this->db,&(car));
    if(uw.exec()){
        if(!uw.updateWin()){
            return false;
        }
    }
    return true;


}