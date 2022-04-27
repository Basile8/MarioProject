
#ifndef MARIOPROJECT_PLATEFORME_H
#define MARIOPROJECT_PLATEFORME_H


#include <QtGui/QPainter>
#include <QGraphicsRectItem>
#include <QDebug>

class plateform : public QGraphicsPixmapItem {


public:
    plateform(int posX, int posY, int width, int height, QString namePlat) : QGraphicsPixmapItem(QPixmap(namePlat)){
        this->hitboxPlat = new QGraphicsRectItem();
        setPos(posX, posY);
        setScale(0.5);
        box=boundingRect();
        QPolygonF poly = mapToScene(box);
        this->hitboxPlat->setRect(poly.boundingRect());
    };
    QGraphicsRectItem *getHitbox(){
      return this->hitboxPlat;
    };

private:
    QRectF box;
    QGraphicsRectItem *hitboxPlat;
};





#endif //MARIOPROJECT_PLATEFORME_H
