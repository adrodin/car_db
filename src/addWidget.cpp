
#include "include/addWidget.h"
#include "messageWindow.h"


AddWidget::AddWidget(QWidget *parent,DbMenager *db) :QWidget(parent){
    this->db = db;
}


void AddWidget::showAddDialog(){
    AddDialog dialog(this,db);
    if(dialog.exec()){
        addEntry(dialog.getCar());
    }
}

void AddWidget::addEntry(bool what){


}
