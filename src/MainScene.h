

#ifndef MARIOPROJECT_MAINSCENE_H
#define MARIOPROJECT_MAINSCENE_H

#include <QGraphicsScene>
#include <QTimer>
#include <QPainter>
#include "Character.h"
#include <QGraphicsView>
#include "Plateforme.h"
#include <QVector>
#include <QtWidgets/QLCDNumber>
#include <QLCDNumber>
#include "Clock.h"
#include "Finish.h"
#include "endWindow.h"
#include "Lever.h"


class MainScene : public QGraphicsScene {

    Q_OBJECT

private:
    QPixmap background;
    Character *mainChar;
    QTimer* timer;
    QGraphicsView*mainView;
    QVector<plateform*>Tabplateform;
    Clock*countClock;
    finishingLine *imgEnd;
    endWindow* endW;
    lever *lev;
    int bestscore;
    bool quit;
    QString pseudo;

public:
    MainScene();
    void drawBackground(QPainter* painter, const QRectF& rect);
    virtual ~MainScene() {};
    QGraphicsView *getMainView() const;
    void collisationDetection(); //Détecte éventuelles collisions, et réagis en fonction
    void deadAndRecall();  //Si le perso meurt, de le faire revenir au départ
    void ArrivedCharacter(); //Si le perso franchi la ligne d'arrivée
    void reset();  //Reset le timer
    void startcrono(); //démarre le timer
    void showendWindow(); //Fenêtre de fin de niveau
    void setPseudo(QString pseu);
public slots:
    void update();


protected:

    void keyPressEvent(QKeyEvent *);

    void keyReleaseEvent(QKeyEvent *);

};



#endif //MARIOPROJECT_MAINSCENE_H


