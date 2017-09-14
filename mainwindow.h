#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QHBoxLayout>

class mainwindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit mainwindow(QWidget *parent = 0);

signals:

public slots:
    void slotExample();
private:
    QPushButton *btn1;
    QPushButton *font;
    QPushButton *style;
    QPushButton *gradient;
    QPushButton *eventbtn;
    QPushButton *signalSlot;
    QHBoxLayout *hbox;
    bool eventFilter(QObject *watched, QEvent *event);
    int time = 0;
};

#endif // MAINWINDOW_H
