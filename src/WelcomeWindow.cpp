#include "WelcomeWindow.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QtWidgets/QLabel>

welcomeWindow::welcomeWindow(QWidget *parent) : QMainWindow(parent) {

    setWindowTitle("Ninja in danger !");
    setMinimumSize(600,500);
    mainW = new MainWindow();
    pseu ="";
    QHBoxLayout*hb1 = new QHBoxLayout();
    QVBoxLayout*vb1 = new QVBoxLayout();
    QWidget*widget = new QWidget();
    QLabel*label = new QLabel(this);
    label->setPixmap(img);
    vb1->addWidget(label);
    play = new QPushButton();
    play->setText("Play !");
    play->setFixedSize(200,70);

    connect(play, SIGNAL(clicked()), this, SLOT(clicPlay()));
    hb1->addWidget(play);

    quit = new QPushButton();
    quit->setText("Quit ?");
    quit->setFixedSize(200,70);
    connect(quit, SIGNAL(clicked()), this, SLOT(clicQuit()));
    hb1->addWidget(quit);

    pseudo = new QLineEdit();
    pseudo->setText("Entrez votre pseudo");
    pseudo->setFixedSize(200,35);
    hb1->addWidget(pseudo);

    registered = new QPushButton();
    registered->setText("OK !");
    registered->setFixedSize(200,70);
    connect(registered, SIGNAL(clicked()), this, SLOT(clicRegistered()));
    hb1->addWidget(registered);

    vb1->addLayout(hb1);
    widget->setLayout(vb1);
    setCentralWidget(widget);
}

void welcomeWindow::clicPlay() {
    this->hide();                   //on cache cette fenêtre au profit de la mainScene
    mainW->show();
}

void welcomeWindow::clicQuit() {
    exit(0);
}

void welcomeWindow::clicRegistered() {
    pseu = pseudo->text(); //On récup le pseudo de l'utilisateur et on l'envoie dans la mainScene pour pouvoir l'utiliser dans notre fichier
    mainW->getmainScene()->setPseudo(pseu);
    mainW->setcheckP(true);
}


