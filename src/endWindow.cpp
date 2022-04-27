#include "endWindow.h"

endWindow::endWindow(QWidget *parent) {
    setWindowTitle("Ninja in danger !");
    setMinimumSize(600, 500);

    QHBoxLayout *hb1 = new QHBoxLayout();
    QVBoxLayout *vh1 = new QVBoxLayout();
    QWidget *widget = new QWidget();
    QLabel *label = new QLabel();

    imgEnd = QPixmap("endImg.png");
    label->setPixmap(imgEnd);
    vh1->addWidget(label);

    play = new QPushButton();
    play->setText("Play !");
    play->setFixedSize(200, 70);
    connect(play, SIGNAL(clicked()), this, SLOT(clicPlay()));
    hb1->addWidget(play);

    quit = new QPushButton();
    quit->setText("Quit ?");
    quit->setFixedSize(200, 70);
    connect(quit, SIGNAL(clicked()), this, SLOT(clicQuit()));
    hb1->addWidget(quit);

    vh1->addLayout(hb1);
    widget->setLayout(vh1);
    setCentralWidget(widget);
}
void endWindow::clicPlay() {
    isplay = true;
    this->hide();
}

void endWindow::clicQuit() {
    isquit = true;
    this->hide();
}
bool endWindow::getisPlay() {
    return this->isplay;
}
void endWindow::setisPlay(bool Play) {
    this->isplay = Play;
}
bool endWindow::getisQuit() {
    return this->isquit;
}
void endWindow::setisQuit(bool quit) {
    this->isquit = quit;
}