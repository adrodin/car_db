
#ifndef V3_MESSAGEWINDOW_H
#define V3_MESSAGEWINDOW_H
#include <QDialog>
#include <QWidget>
using namespace std;

class MessageWindow : public QDialog {
private:
    string text;
public:
    MessageWindow(QWidget *parent = nullptr,string text = nullptr);


};
#endif //V3_MESSAGEWINDOW_H
