#include "MainWindow.h"
#include <QVBoxLayout>
#include <QTableWidget>

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent) {
    mainScene = new MainScene();
    this->setCentralWidget(mainScene->getMainView());
    checkP = false;

}
MainScene* MainWindow::getmainScene() {
    return this->mainScene;
}

QString MainWindow::getpseudoMainW(){
return this ->pseudoMainW;
}
void MainWindow::setpseudoMainW(QString pseudo) {
    this->pseudoMainW = pseudo;
}
bool MainWindow::setcheckP(bool check){
    this->checkP = check;
}