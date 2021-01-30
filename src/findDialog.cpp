#include <QDialog>
#include "include/findDialog.h"
#include <QLabel>
#include <QPushButton>
#include <QGridLayout>
#include "car.h"
#include "messageWindow.h"
#include "showCar.h"

FindDialog::FindDialog(QWidget *parent,DbMenager *db): QDialog(parent){
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

bool FindDialog::findCar(){

    if(this->vinText->text().toStdString().empty()) {
        MessageWindow mw(this,"Vin can't be empty");
        mw.exec();
        return false;
    }

    string vin = this->vinText->text().toStdString();

    if(Car::checkVin(vin)){
        Car car = db->find(vin);
        if( !car.getVin().compare("NULL")) {
            MessageWindow mw(this,"No vin in db");
            mw.exec();
            return false;
        }
        else{

            ShowCar sh(this,&car);
            sh.exec();
            return true;
        }
    }

    else{
        MessageWindow mw(this,"Wrong vin length");
        mw.exec();

        return false;
    }

}