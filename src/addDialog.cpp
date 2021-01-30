#include <QDialog>
#include "include/addDialog.h"
#include <QLabel>
#include <QPushButton>
#include <QGridLayout>
#include "messageWindow.h"



AddDialog::AddDialog(QWidget *parent,DbMenager *db): QDialog(parent){
    this->db = db;
    auto vinLabel = new QLabel(tr("Vin"));
    auto markLabel = new QLabel(tr("Mark"));
    auto modelLabel = new QLabel(tr("Model"));
    auto yearLabel = new QLabel(tr("Year"));
    auto mileageLabel = new QLabel(tr("Mileage"));
    auto enginePowerLabel = new QLabel(tr("Engine power"));
    auto colourLabel = new QLabel(tr("Colour"));

    auto okButton = new QPushButton(tr("OK"));
    auto cancelButton = new QPushButton(tr("Cancel"));

    this->vinText = new QLineEdit();
    this->markText = new QLineEdit();
    this->modelText = new QLineEdit();
    this->yearText = new QLineEdit();
    this->mileageText = new QLineEdit();
    this->enginePowerText = new QLineEdit();
    this->colourText = new QLineEdit();


    auto layout = new QGridLayout;

    layout->setColumnStretch(1, 2);

    layout->addWidget(vinLabel,0,0);
    layout->addWidget(this->vinText,0,1);

    layout->addWidget(markLabel,1,0);
    layout->addWidget(this->markText,1,1);

    layout->addWidget(modelLabel,2,0);
    layout->addWidget(this->modelText,2,1);

    layout->addWidget(yearLabel,3,0);
    layout->addWidget(this->yearText,3,1);

    layout->addWidget(mileageLabel,4,0);
    layout->addWidget(this->mileageText,4,1);

    layout->addWidget(enginePowerLabel,5,0);
    layout->addWidget(this->enginePowerText,5,1);

    layout->addWidget(colourLabel,6,0);
    layout->addWidget(this->colourText,6,1);


    auto buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget(okButton);
    buttonLayout->addWidget(cancelButton);

    layout->addLayout(buttonLayout, 7, 1, Qt::AlignRight);

    auto mainLayout = new QVBoxLayout;
    mainLayout->addLayout(layout);
    setLayout(mainLayout);


    connect(okButton, &QAbstractButton::clicked, this, &QDialog::accept);
    connect(cancelButton, &QAbstractButton::clicked, this, &QDialog::reject);

    setWindowTitle("Add car to database");
}

bool AddDialog::getCar(){

    if(this->vinText->text().toStdString().empty()){
        MessageWindow mw(this,"Vin was empty");
        mw.exec();
        return false;
    }
    if(this->markText->text().toStdString().empty()){
        MessageWindow mw(this,"Mark was empty");
        mw.exec();
        return false;
    }
    if(this->modelText->text().toStdString().empty()){
        MessageWindow mw(this,"Model was empty");
        mw.exec();
        return false;
    }
    if(this->colourText->text().toStdString().empty()){
        MessageWindow mw(this,"Colour was empty");
        mw.exec();
        return false;
    }
    if(this->yearText->text().toStdString().empty()){
        MessageWindow mw(this,"Year was empty");
        mw.exec();
        return false;
    }
    if(this->mileageText->text().toStdString().empty()){
        MessageWindow mw(this,"Mileage was empty");
        mw.exec();
        return false;
    }
    if(this->enginePowerText->text().toStdString().empty()){
        MessageWindow mw(this,"Engine power was empty");
        mw.exec();
        return false;
    }

    int year;
    int mileage;
    int enginePower;
    string vin = this->vinText->text().toStdString();
    string mark = this->markText->text().toStdString();
    string model = this->modelText->text().toStdString();
    string colour = this->colourText->text().toStdString();
    try {
        year = stol(this->yearText->text().toStdString());
        mileage = stol(this->mileageText->text().toStdString());
        enginePower = stol(this->enginePowerText->text().toStdString());
    } catch(invalid_argument &e){
    MessageWindow mw(this,"Invalid argument");
    mw.exec();
    return false;}
    catch(out_of_range &e){
    MessageWindow mw(this,"Out of range");
    mw.exec();
    return false;
    }


    if(Car::checkVin(vin)){
        if(this->db->isInDB(vin)){
            MessageWindow mw(this,"This vin is in db");
            mw.exec();
            return false;
        }

        Car car = Car(vin, mark, model, year, mileage, enginePower, colour);
        if(this->db->addToDB(const_cast<Car &>(car))){
            MessageWindow mw(this,"Successfully added");
            mw.exec();
            return true;
        }
        MessageWindow mw(this,"Something went wrong");
        mw.exec();
        return false;

    }
    MessageWindow mw(this,"Vin must have 17 characters");
    mw.exec();
    return false;
}

