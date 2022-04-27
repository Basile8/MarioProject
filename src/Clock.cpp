#include <sys/socket.h>
#include <QtCore>
#include <QFont>
#include "Clock.h"
#include "Character.h"

Clock::Clock(QGraphicsItem* parent):QGraphicsTextItem(parent) { //Merci Antonin
    setPlainText(QString("time: ")+QString::number(this->timer)); //Merci Antonin
    setDefaultTextColor(Qt::black);

    this->time = new QTimer(this); //Tjrs initialiser dans constructeur
    time->start(10);
    decim =0;
    sec=0;
    min=0;
    hour=0;
    connect(time,SIGNAL(timeout()),this,SLOT(showTime()));
}

void Clock::showTime() {
    this->timer++;
    if (this->timer%10 ==0){
        decim++;
        if (decim%10 ==0){
            sec++;
            decim =0;
            if (sec % 60 == 0){
                min++;
                sec =0;
            }
        }
    }
    setPlainText(QString("time: ")+QString::number(min)+": "+QString::number(sec)+": "+QString::number(decim));
}

void Clock::setDecim(int decimal) {
    this->decim = decimal;
}
void Clock::setSec(int seconds) {
    this->sec = seconds;
}
void Clock::setMin(int minuts) {
    this->min = minuts;
}
int Clock::getDecim() {
    return this->decim;
}
int Clock::getSec() {
    return this->sec;
}
int Clock::getMin() {
    return this->min;
}
int Clock::getTimer(){
    return this->timer;
}
void Clock::setTimer(int time) {
    this ->timer = time;
}
//You can solve the problem if delete the folder where Qt save object files, and then recompile your project.
//In my case the folder has name "projectName-build-desktop".