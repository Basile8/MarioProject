
#ifndef MARIOPROJECT_CLOCK_H
#define MARIOPROJECT_CLOCK_H

#include <QObject>
#include <QGraphicsTextItem>

class Clock: public QGraphicsTextItem{

    Q_OBJECT

private:
    int timer=0;
    int decim;
    int sec;
    int min;
    int hour;
    QTimer* time;

public:

    explicit Clock(QGraphicsItem* parent=nullptr);
    int getCount(){  return this->timer;}
   // void posClock();
    void setDecim(int decimal);
    int getDecim();
    void setSec(int seconds);
    int getSec();
    void setMin(int minuts);
    int getMin();
    int getTimer();
    void setTimer(int time);
public slots:
    void showTime();

};

#endif //MARIOPROJECT_CLOCK_H
