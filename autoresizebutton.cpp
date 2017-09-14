#include "autoresizebutton.h"
#include "QStylePainter"
#include "QStyleOptionButton"


AutoResizeButton::AutoResizeButton(QWidget *parent):
    QPushButton(parent)
{
    this->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
}

void AutoResizeButton::paintEvent(QPaintEvent *event)
{
    QStylePainter painter(this);
    QStyleOptionButton opt;
    this->initStyleOption(&opt);
    QRect r = opt.rect;
    int h = r.height();
    int w = r.width();

    opt.iconSize = QSize(h,w);
    painter.drawControl(QStyle::CE_PushButton,opt);

}
