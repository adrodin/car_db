#include <QApplication>
#include <QDebug>
#include <QMainWindow>
#include <QPushButton>
#include <QButtonGroup>
#include "include/mainWindow.h"
#include "include/addDialog.h"
#include "sqlite3/sqlite3.h"

using namespace std;

int main(int argc, char *argv[]) {

    QApplication app(argc, argv);
    MainWindow mainW;
    mainW.show();


    return app.exec();
}