

#ifndef V3_MAINWINDOW_H
#define V3_MAINWINDOW_H

#include <QMainWindow>
#include <QItemSelection>
#include "include/addDialog.h"
#include "include/addWidget.h"
#include "include/findWidget.h"
#include "dbMenager.h"
#include "updateWidget.h"
class MainWindow : public QMainWindow {

private:
    DbMenager db = DbMenager();
    void createMenu();

    AddWidget *addWidget;
    FindWidget *findWidget;
    UpdateWidget *updateWidget;


public:
    MainWindow();



};


#endif //V3_MAINWINDOW_H
