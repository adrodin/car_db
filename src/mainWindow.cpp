#include "include/mainWindow.h"



MainWindow::MainWindow():QMainWindow() {
    this->addWidget = new AddWidget(this,&db);
    this->findWidget = new FindWidget(this,&db);
    this->updateWidget = new UpdateWidget(this, &db);
    createMenu();
    setWindowTitle(tr("Cars database"));
    this->setMinimumHeight(480);
    this->setMinimumWidth(720);
};

void MainWindow::createMenu() {

    QMenu *menu = menuBar()->addMenu(tr("&Menu"));

    QAction *add = new QAction(tr("Add"));
    menu->addAction(add);
    connect(add, &QAction::triggered,addWidget, &AddWidget::showAddDialog);



    QAction *update = new QAction(tr("Update"));
    menu->addAction(update);
    connect(update,&QAction::triggered,updateWidget,&UpdateWidget::showUpdateDialog);


    QAction *find= new QAction(tr("Find"));
    menu->addAction(find);
    connect(find, &QAction::triggered,findWidget, &FindWidget::showFindDialog);

    QAction *exit = new QAction(tr("Exit"));
    menu->addAction(exit);
    connect(exit, &QAction::triggered, this, &QWidget::close);

};
