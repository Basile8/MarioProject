#include "MainWindow.h"
#include "WelcomeWindow.h"
#include <QApplication>
#include <QTime>
int main(int argc, char* argv[]) {
    QApplication app(argc, argv);
    QTime time = QTime::currentTime();
    qsrand((uint)time.msec());
    welcomeWindow FenetreAccueil;
    FenetreAccueil.show();
    return app.exec();
}