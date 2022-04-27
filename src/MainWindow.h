//
// Created by Basile on 16/04/2020.
//

#ifndef MARIOPROJECT_MAINWINDOW_H
#define MARIOPROJECT_MAINWINDOW_H
#include <QMainWindow>
#include <QPushButton>
#include <QTextEdit>
#include "MainScene.h"
#include "Character.h"
#include <QGraphicsView>

class MainWindow : public QMainWindow {

Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);
    virtual ~MainWindow(){};
    MainScene* getmainScene();
    void setpseudoMainW(QString pseudo);
    QString getpseudoMainW();
    bool setcheckP(bool check);

private:
    MainScene *mainScene;
    QString pseudoMainW;
    bool checkP;   //Ce booléen permet de savoir quand la personne veut relancer une partie de faire ce qu'il faut pour réouvrir une fenêtre etc
};
#endif //MARIOPROJECT_MAINWINDOW_H
