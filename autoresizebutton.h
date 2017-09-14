#ifndef AUTORESIZEBUTTON_H
#define AUTORESIZEBUTTON_H
#include "QPushButton"

class AutoResizeButton : public QPushButton
{
public:
    AutoResizeButton(QWidget *parent);

private:
    void paintEvent(QPaintEvent *event);
};

#endif // AUTORESIZEBUTTON_H
