
#include "include/updateWidget.h"
#include "updateDialog.h"

UpdateWidget::UpdateWidget(QWidget *parent,DbMenager *db ) :QWidget(parent){
    this->db=db;
}


void UpdateWidget::showUpdateDialog(){
    UpdateDialog dialog(this,db);
    if(dialog.exec()){
        dialog.updateCar();
    }
}