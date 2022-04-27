
#ifndef MARIOPROJECT_WELCOMEWINDOW_H
#define MARIOPROJECT_WELCOMEWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLineEdit>
#include "MainWindow.h"

class welcomeWindow : public QMainWindow {

    Q_OBJECT

public:
    welcomeWindow(QWidget* parent = nullptr);
    virtual ~welcomeWindow() {};

private:
        QPushButton *play;
        QPushButton *quit;
        QLineEdit *pseudo;
        MainWindow *mainW;
        QPushButton *registered;
        QString pseu;
        QPixmap img = QPixmap("welcomeImg.png");
public slots:
    void clicQuit();   //quitte le jeux lors du clic
    void clicPlay();   //lance le jeux lors du clic
    void clicRegistered(); //mémorise le pseudo lors du clic
};

#endif //MARIOPROJECT_WELCOMEWINDOW_H
