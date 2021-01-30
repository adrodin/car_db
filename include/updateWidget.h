
#ifndef V3_UPDATEWIDGET_H
#define V3_UPDATEWIDGET_H
#include <QTabWidget>
#include <QtWidgets>
#include "include/findDialog.h"
#include "dbMenager.h"
class UpdateWidget : public QWidget{

private:
    DbMenager *db;
public:
    UpdateWidget(QWidget *parent = nullptr,DbMenager *db=nullptr);

public slots:
    void showUpdateDialog();

};


#endif //V3_UPDATEWIDGET_H
