
#include "messageWindow.h"
#include <QLabel>
#include <QPushButton>
#include <QGridLayout>

MessageWindow::MessageWindow(QWidget *parent,string text){
    auto label = new QLabel(tr(text.c_str()));
    auto okButton = new QPushButton(tr("OK"));
    auto layout = new QGridLayout;

    layout->addWidget(label,0,0);

    auto buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget(okButton);

    layout->addLayout(buttonLayout, 1, 0, Qt::AlignRight);

    auto mainLayout = new QVBoxLayout;
    mainLayout->addLayout(layout);
    setLayout(mainLayout);


    connect(okButton, &QAbstractButton::clicked, this, &QDialog::accept);

}