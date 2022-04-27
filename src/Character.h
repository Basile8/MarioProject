//
// Created by Basile on 24/04/2020.
//

#ifndef MARIOPROJECT_CHARACTER_H
#define MARIOPROJECT_CHARACTER_H

#include <QtWidgets/QGraphicsPixmapItem>
#include <QPixmap>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QDebug>
#include <QTimer>

class Character : public QGraphicsPixmapItem {

public:
    Character(QString Img) : QGraphicsPixmapItem(QPixmap(Img)){

            right = false;
            left = false;
            up = false;
            down = false;
            start = false;
            nbJump = 1;
            countJump = 0;
            gravity = 8;
            indGravity = true;
            setScale(0.3);   //diminue l'affichage de mon personnage
            setPos(300,300);  //Place le perso dans le décor
            this->hitbox = new QGraphicsRectItem(this); //Eragon35 m'a aidé pour récupérer l'hitbox et afficher mon rectangle avec la bonne hitbox dessus
            QRectF bobox = boundingRect();
            bobox.setWidth(bobox.width()*0.3);
            bobox.setHeight(bobox.height()*0.3);
            this->hitbox->setRect(bobox);
            hitbox->setPen(QPen(Qt::white));
    };

    QGraphicsRectItem &getHitbox();

    bool isStart(){
        return this->start;
    }
    void setGravity(int grav){
        this->gravity = grav;
    }

    void setRight(bool right);

    void setUp(bool up);

    void setLeft(bool left);

    void setDown(bool down);

    float getGravity();

    bool getindGravity(){
        return this ->indGravity;
    }
    void setindGravity(bool setgrav){
        this->indGravity = setgrav;
    }
    void move();

    int getnbJump(){
       return this ->nbJump;
    }
    void setnbJump(int nbjump){
        this ->nbJump = nbjump;
    }

    void setcountJump(int countjump){
        this->countJump = countjump;
    }
    int getcountJump(){
        return this ->countJump;
    }
    QVector<QPixmap*> getmarcheAvant(){
        return this ->marcheAvant;
    }
    void setstart(bool Start){
        this->start = Start;
    }
    bool getstart(){
        return this->start;
    }
    int getincrGravity();
    void setincrGravity(int incr);
private:
    bool right;
    bool left;
    bool up;
    bool down;
    bool start;
    QGraphicsRectItem *hitbox;
    float gravity;
    bool indGravity;
    int nbJump;
    int countJump;
    QVector<QVector<QPixmap*>> vectSprite;
    QVector<QPixmap*>marcheAvant;
    QVector<QPixmap*>marcheArriere;
};

#endif //MARIOPROJECT_CHARACTER_H
