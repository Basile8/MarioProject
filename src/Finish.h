

#ifndef MARIOPROJECT_FINISH_H
#define MARIOPROJECT_FINISH_H

#include <QtWidgets/QGraphicsPixmapItem>
#include <QtGui/QPainter>

class finishingLine : public QGraphicsPixmapItem {

public:
    finishingLine(int posX, int posY, int width, int height, QString nameFinish) : QGraphicsPixmapItem(QPixmap(nameFinish)){
    this->hitbox = new QGraphicsRectItem(this);
    setPos(posX,posY);
    setScale(0.8);
    box = boundingRect();
    QPolygonF poly = mapToScene(box);
    this->hitbox->setRect(poly.boundingRect());
}

private:
    QGraphicsRectItem *hitbox;
    QRectF box;
};
#endif //MARIOPROJECT_FINISH_H
