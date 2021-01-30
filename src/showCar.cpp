
#include "showCar.h"
#include <QLabel>
#include <QPushButton>
#include <QGridLayout>


ShowCar::ShowCar(QWidget *parent,Car *car): QDialog(parent) {

    auto vinLabel = new QLabel(tr("Vin"));
    auto markLabel = new QLabel(tr("Mark"));
    auto modelLabel = new QLabel(tr("Model"));
    auto yearLabel = new QLabel(tr("Year"));
    auto mileageLabel = new QLabel(tr("Mileage"));
    auto enginePowerLabel = new QLabel(tr("Engine power"));
    auto colourLabel = new QLabel(tr("Colour"));

    auto okButton = new QPushButton(tr("OK"));


    this->vinText = new QLineEdit();
    this->markText = new QLineEdit();
    this->modelText = new QLineEdit();
    this->yearText = new QLineEdit();
    this->mileageText = new QLineEdit();
    this->enginePowerText = new QLineEdit();
    this->colourText = new QLineEdit();

    this->vinText->setText(car->getVin().c_str());
    this->markText->setText(car->getMark().c_str());
    this->modelText->setText(car->getModel().c_str());
    this->yearText->setText(to_string(car->getYear()).c_str());
    this->mileageText->setText(to_string(car->getMileage()).c_str());
    this->enginePowerText->setText(to_string(car->getEnginePower()).c_str());
    this->colourText->setText(car->getColour().c_str());

    this->vinText->setReadOnly(true);
    this->markText->setReadOnly(true);
    this->modelText->setReadOnly(true);
    this->yearText->setReadOnly(true);
    this->mileageText->setReadOnly(true);
    this->enginePowerText->setReadOnly(true);
    this->colourText->setReadOnly(true);

    auto layout = new QGridLayout;

    layout->setColumnStretch(1, 2);

    layout->addWidget(vinLabel, 0, 0);
    layout->addWidget(this->vinText, 0, 1);

    layout->addWidget(markLabel, 1, 0);
    layout->addWidget(this->markText, 1, 1);

    layout->addWidget(modelLabel, 2, 0);
    layout->addWidget(this->modelText, 2, 1);

    layout->addWidget(yearLabel, 3, 0);
    layout->addWidget(this->yearText, 3, 1);

    layout->addWidget(mileageLabel, 4, 0);
    layout->addWidget(this->mileageText, 4, 1);

    layout->addWidget(enginePowerLabel, 5, 0);
    layout->addWidget(this->enginePowerText, 5, 1);

    layout->addWidget(colourLabel, 6, 0);
    layout->addWidget(this->colourText, 6, 1);


    auto buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget(okButton);


    layout->addLayout(buttonLayout, 7, 1, Qt::AlignRight);

    auto mainLayout = new QVBoxLayout;
    mainLayout->addLayout(layout);
    setLayout(mainLayout);


    connect(okButton, &QAbstractButton::clicked, this, &QDialog::accept);
}