#include <QtGui/QtGui>
#include "MainScene.h"
#include "QDebug"
#include <iostream>
#include <fstream>
#include "WelcomeWindow.h"
#include "QCoreApplication"

MainScene::MainScene() {

    background.load("../img/Background.png");
    setSceneRect(0, 0,5000,600);
    timer = new QTimer(this);
    timer->start(30);
    QString Img = "Glide_006redimensionned.png";
    QString PlateformH ="platH512.png";
    mainChar = new Character(Img);
    addItem(&(mainChar->getHitbox()));             //Eragon35
    addItem(mainChar);                            //Ajoute le character dans la scene)
    mainView = new QGraphicsView(this);
    imgEnd = new finishingLine(2500,250,297,250,"../img/temple.png");
    addItem(imgEnd);
    lev = new lever(1325, 480, 150,150,"control-lever_Right.png");
    addItem(lev);
    bestscore = 1000000;
    Tabplateform.push_back(new plateform(10,540,266,45,PlateformH)); //se conforme au max de la taille de l'image et pas à la taille donnée
    Tabplateform.push_back(new plateform(800,390,266,45,PlateformH));
    Tabplateform.push_back(new plateform(266,540,266,45,PlateformH));
    Tabplateform.push_back(new plateform(522,540,266,45,PlateformH));
    Tabplateform.push_back(new plateform(778,540,512,45,PlateformH));
    Tabplateform.push_back(new plateform(1024,540,512,45,PlateformH));
    Tabplateform.push_back(new plateform(1280,340,45,200,"platV512.png"));//l'unique plateforme verticale
    Tabplateform.push_back(new plateform(1280,299,512,45,PlateformH));
    Tabplateform.push_back(new plateform(1850, 500, 512,45,PlateformH));
    Tabplateform.push_back(new plateform(imgEnd->x()-50,imgEnd->y()+175,266,45,PlateformH)); //plateforme d'arrivée, contenant le temple
    Tabplateform.push_back(new plateform(1325, 540, 512,45, PlateformH));
    endW = new endWindow();
    quit = false;

    int nbPlateforms = Tabplateform.size();
    for (int i = 0; i < nbPlateforms; i++){
        QGraphicsRectItem *contenuTab = Tabplateform[i]->getHitbox();
        this->addItem(Tabplateform[i]);
        Tabplateform[8]->hide(); //On cache la plateforme ainsi que sa hitbox
        Tabplateform[8]->getHitbox()->hide();
        this->addItem(contenuTab);//On ajoute les plateforme dans la scene
    }
    countClock = new Clock();
    addItem(countClock);
    countClock->setPos(100,100);
    countClock->setScale(3);
    mainView->centerOn(mainChar); //on centre la vue sur le perso
    mainView->setFixedSize(600,600);
    mainView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff); //Empêche de scroll verticalement et horizontalement
    mainView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    mainChar->setFlag(QGraphicsItem::ItemIsFocusable); //Sert à indiquer que lorsqu'il y a une entrée clavier, ça envoie les infos à mainChar
    mainChar->setFocus();
    countClock->setFocus();
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
}

QGraphicsView *MainScene::getMainView() const {
    return mainView;
}

void MainScene::drawBackground(QPainter *painter, const QRectF &rect) {
    Q_UNUSED(rect);
    painter->drawPixmap(QRectF(0,0,sceneRect().width(), sceneRect().height()), background,sceneRect());
    painter->drawPixmap(QRectF(1920,0,sceneRect().width(), sceneRect().height()), background,sceneRect());

}

void MainScene::update() {
        startcrono(); //On démarre le chrono A PARTIR du moment ou le perso commence à bouger pour pas que le joueur soit pris de court
        this->collisationDetection();//on recherche les collisions
        if(mainChar->getindGravity())
            mainChar->setY(mainChar->y()+mainChar->getGravity()); //set la grav si bool est true
        mainView->centerOn(mainChar); //on continue de fixer la view sur le perso tt le temps
        countClock->setPos(mainChar->x()-250, 30); //Permet à l'horloge de rester dans un endroit visible, qu'elle suive le perso

        if(mainChar->x() < mainView->x()+100)
            mainChar->setX(mainChar->x()+15); //Empêche le perso de dépasser du bord gauche

        if(countClock->x() < mainView->x()) //pareil pour l'horloge
           countClock->setX(mainView->x());

        ArrivedCharacter(); //On regarde si le perso est arrivé

        if (quit)
        exit(0);
}

void MainScene::reset() {
    this->countClock->setDecim(0);
    this->countClock->setSec(0);
    this->countClock->setMin(0);
}


void MainScene::keyPressEvent(QKeyEvent *event) {
    switch (event->key()){
        case Qt::Key_Left:
            mainChar->setLeft(true);
            break;
        case Qt::Key_Right:
            mainChar->setRight(true);
            break;
        case Qt::Key_Space:
            mainChar->setUp(true);
            break;
        case Qt::Key_Down:
            mainChar->setDown(true);
            break;
    }
}

void MainScene::keyReleaseEvent(QKeyEvent *event){

    switch (event->key()){
        case Qt::Key_Left:
            mainChar->setLeft(false);
            break;
        case Qt::Key_Right:
            mainChar->setRight(false);
            break;
        case Qt::Key_Space:
            mainChar->setUp(false);
            break;
        case Qt::Key_Down:
            mainChar->setDown(false);
            break;
    }
}
void MainScene::collisationDetection() {
    int nbplat = Tabplateform.size();
    QGraphicsRectItem *testColl = new QGraphicsRectItem(); //On créée un backup, correspondant à l'ancienne pos du perso
    testColl->setPos(mainChar->x(), mainChar->y());        //je set la pos du backup à la pos de mon perso
    testColl->setRect(mainChar->getHitbox().rect());//Pareil mais avec la thitbox
    mainChar->move();
    mainChar->setindGravity(true);
    deadAndRecall(); //au cas où le perso sort de la limite imposée


//Merci Valou d'avoir aidé pour les plateformes qui ne prenaient pas toute en compte les collisions
        if(mainChar->collidesWithItem(lev)) { //Si il collide avec le levier, fait apparaitre la plateforme avec le changement d'image du levier
            Tabplateform[8]->show();
            lev->setPixmap(QPixmap(lev->getlevLeft()));
        }
    for (int i = 0; i < nbplat; i++) {
        QGraphicsRectItem *plateform = this->Tabplateform[i]->getHitbox();
        if (mainChar->collidesWithItem(plateform)) { //Si collison :
            if (mainChar->y()+ mainChar->boundingRect().height() > Tabplateform[i]->y()){  //Si le perso atterri sur le sol

                if(mainChar->x()>= Tabplateform[i]->x() && mainChar->x() <= Tabplateform[i]->boundingRect().width() + Tabplateform[i]->x()){ //si il se trouve bien au dessus de la plateforme
                    mainChar->setindGravity(false); //on annule la gravité
                    mainChar->setnbJump(1);
                    mainChar->setcountJump(0);
                }
                if (mainChar->x()+mainChar->boundingRect().width() >= Tabplateform[i]->x() && mainChar->x() <= Tabplateform[i]->boundingRect().width() + Tabplateform[i]->x()){ //si le début du perso est bien sur la plateforme
                    mainChar->setindGravity(false);
                    if(testColl->y() > Tabplateform[i]->y() || testColl->y() + testColl->boundingRect().height() > Tabplateform[i]->y()+mainChar->getGravity()+16){ //si l'ancienne pos du perso est en dessous d'une plateforme (en gros pour les collisions de côté)
                        mainChar->setX(testColl->x()); //correspond à stoper le perso en x, à le faire revenir à sa pos arriere
                        mainChar->setindGravity(true);
                    }
                }
            }
            if (mainChar->x() + mainChar->boundingRect().width() > Tabplateform[i]->x() &&
                             mainChar->boundingRect().height() < plateform->boundingRect().height()) {//Si le Perso entre dans la plateforme en x ET est inférieur à la hauteur de la plateforme, il est censé se stopper (pour la verticale)
                if(mainChar->y()+mainChar->boundingRect().height() >= Tabplateform[i]->y()+Tabplateform[i]->boundingRect().height()-Tabplateform[i]->boundingRect().width()*1.6){ //correspond à 0.1 près au scale des plateforme, correspond à la hauteur de la platforme
                    mainChar->setindGravity(false);
                    mainChar->setX(testColl->x());
                }
                else {
                    mainChar->setX(testColl->x());
                    mainChar->setindGravity(true);
                }
            }
        }
    }
}

void MainScene::deadAndRecall() {
    if (mainChar->y()+mainChar->boundingRect().height() > this->height()*2) //Si il tombe
        mainChar->setPos(300,300);
}
void MainScene::ArrivedCharacter() {

    if (mainChar->collidesWithItem(imgEnd)){
        mainChar->setindGravity(false); //Si le perso n'est plus en collision à cause de la chute sa reset mal
        showendWindow();
        Tabplateform[8]->hide(); //Pour relancer une partie, on recache la plateforme
        QFile scoreboard("../src/scoreboard.txt");
        scoreboard.open(QIODevice :: ReadWrite  | QIODevice::Text);
        QTextStream flux(&scoreboard);
        flux.setCodec("UTF-8");
            flux>>bestscore;

        int score = this->countClock->getMin()*60*10 + this->countClock->getSec()*10 + this->countClock->getDecim();

            if (score < bestscore){ //Si meilleur score, on reset le fichier et on met le score
                scoreboard.resize(0);
                bestscore = score;

                flux<<bestscore<<" dixiemes de seconde realise par :";
                flux<<pseudo;
            }
            if(endW->getisPlay()){ //Si la personne appuie sur rejouer: on cache la fenêtre de fin
                endW->hide();
                reset(); //on reset le timer
                lev->setPixmap(QPixmap(lev->getlevRight())); //On remet l'image du levier comme avant
                mainChar->setstart(false); //empêche de démarrer le crono avant mvt
                mainChar->setPos(300,300);
                endW->setisPlay(false);
            }
            if(endW->getisQuit()){
                endW->close();
                endW->setisQuit(false);
                quit = true;
            }
        }
    }
void MainScene::startcrono() {
    if (!mainChar->isStart())
        countClock->setTimer(0);
}
void MainScene::showendWindow() {
    endW->show();
}
void MainScene::setPseudo(QString pseu){
    this->pseudo = pseu;
}