
#ifndef V3_ADDWIDGET_H
#define V3_ADDWIDGET_H
#include <QTabWidget>
#include <QtWidgets>
#include "addDialog.h"
#include "include/addDialog.h"
#include "dbMenager.h"
class AddWidget : public QWidget{

private:
    DbMenager *db;
public:
    AddWidget(QWidget *parent = nullptr,DbMenager *db = nullptr);

public slots:
    void showAddDialog();
    void addEntry(bool what);
};

#endif //V3_ADDWIDGET_H
