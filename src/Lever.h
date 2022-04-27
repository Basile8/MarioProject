
#ifndef MARIOPROJECT_LEVER_H
#define MARIOPROJECT_LEVER_H

#include <QtWidgets/QGraphicsPixmapItem>

class lever : public QGraphicsPixmapItem {

public:
lever(int posX, int posY, int width, int height, QString nameFinish) : QGraphicsPixmapItem(QPixmap(nameFinish)){
    this->hitbox = new QGraphicsRectItem(this);
    setPos(posX,posY);
    setScale(0.5);
    box = boundingRect();
    QPolygonF poly = mapToScene(box);
    this->hitbox->setRect(poly.boundingRect());
    levLeft = QPixmap("control-lever_Left.png");
    levRight = QPixmap("control-lever_Right.png");
}
QPixmap getlevLeft(){
    return this->levLeft;
}
QPixmap getlevRight(){
    return this->levRight;
}
private:
    QGraphicsRectItem *hitbox;
    QPixmap levLeft;
    QPixmap levRight;
    QRectF box;
};


#endif //MARIOPROJECT_LEVER_H
