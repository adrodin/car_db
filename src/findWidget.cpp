
#include "include/findWidget.h"


FindWidget::FindWidget(QWidget *parent,DbMenager *db ) :QWidget(parent){
this->db=db;
}


void FindWidget::showFindDialog(){
    FindDialog dialog(this,db);
    if(dialog.exec()){
        dialog.findCar();
    }
}