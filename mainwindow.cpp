#include "mainwindow.h"
#include "QWidget"
#include "QFont"
#include "QLinearGradient"
#include "QBrush"
#include "QPalette"
#include "QGraphicsColorizeEffect"
#include "autoresizebutton.h"
#include "QEvent"
mainwindow::mainwindow(QWidget *parent) : QMainWindow(parent)
{
    QWidget *central = new QWidget();
    hbox = new QHBoxLayout(central);
    btn1 = new QPushButton(this);
    font = new QPushButton(this);
    style = new QPushButton(this);
    gradient = new QPushButton(this);
    QPushButton *icon = new AutoResizeButton(this);
    eventbtn = new QPushButton(this);
    signalSlot = new QPushButton(this);


    btn1->setText("try it"); //設定文字
    font->setText("font");
    style->setText("style");
    gradient->setText("gradient");
    eventbtn->setText("event");
    signalSlot->setText("signal");
    btn1->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    font->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    style->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    gradient->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    eventbtn->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    signalSlot->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);


    QFont *fonts = new QFont();//字體，字型
    fonts->setPixelSize(18);
    fonts->setFamily("新細明體");
    fonts->setWeight(QFont::Black);
    font->setFont(*fonts);

    style->setStyleSheet("background-color:blue;border-radius: 5");

    //gradient->setStyleSheet("background-color: qradialgradient(cx: 0.5, cy: 0.5, radius: 2, fx: 0.5, fy: 1, stop: 0 rgba(255,30,30,255), stop: 0.2 rgba(255,30,30,144), stop: 0.4 rgba(255,30,30,32));");
    QGraphicsColorizeEffect *effect = new QGraphicsColorizeEffect(gradient); //系統方式預設漸層
    effect->setColor(Qt::red);
    gradient->setGraphicsEffect(effect);
    
    icon->setIcon(QIcon(".\\svgtest.svg"));

    eventbtn->installEventFilter(this);

    QLinearGradient btnGradient(0,0,0,50); //上往下線性漸層
    btnGradient.setColorAt(0, QColor(0, 0, 0));
    btnGradient.setColorAt(1,QColor(160, 180, 200));
    QPalette palette = this->palette(); //背景漸層
    palette.setBrush(QPalette::Background, btnGradient);
    //palette.setColor(QPalette::Button, Qt::red);
    this->setPalette(palette);


    hbox->addWidget(btn1);
    hbox->addWidget(font);
    hbox->addWidget(style);
    hbox->addWidget(gradient);
    hbox->addWidget(icon);
    hbox->addWidget(eventbtn);
    hbox->addWidget(signalSlot);

    setCentralWidget(central);

    //connect(signalSlot,SIGNAL(pressed()),this,SLOT(slotExample()));
    connect(signalSlot,&QPushButton::clicked,[this](){
        signalSlot->setText("preesed by lamda");
    });
}

void mainwindow::slotExample(){

    signalSlot->setText("pressed");
}

bool mainwindow::eventFilter(QObject *watched, QEvent *event)
{
    if(watched == eventbtn && event->type() == QEvent::MouseButtonRelease){
        eventbtn->setText("preesed");
    }
    return QMainWindow::eventFilter(watched,event);
}
