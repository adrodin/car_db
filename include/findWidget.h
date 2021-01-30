//
// Created by Adik on 11.01.2021.
//

#ifndef V3_FINDWIDGET_H
#define V3_FINDWIDGET_H

#include <QTabWidget>
#include <QtWidgets>
#include "include/findDialog.h"
#include "dbMenager.h"
class FindWidget : public QWidget{
    // Q_OBJECT
private:
    DbMenager *db;
public:
    FindWidget(QWidget *parent = nullptr,DbMenager *db=nullptr);

public slots:
    void showFindDialog();

};
#endif //V3_FINDWIDGET_H
