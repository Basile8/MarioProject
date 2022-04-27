
#ifndef MARIOPROJECT_ENDWINDOW_H
#define MARIOPROJECT_ENDWINDOW_H

#include "QMainWindow"
#include "QPushButton"
#include "QLineEdit"
#include "QVBoxLayout"
#include "QHBoxLayout"
#include <QLabel>

class endWindow : public QMainWindow {

    Q_OBJECT
public:
    endWindow(QWidget* parent = nullptr);
    virtual ~endWindow(){};
    void setisPlay(bool Play);
    bool getisPlay();
    void setisQuit(bool quit);
    bool getisQuit();
private:
    QPushButton *play;
    QPushButton *quit;
    bool isplay = false;
    bool isquit = false;
    QPixmap imgEnd;
public slots:
    void clicQuit();
    void clicPlay();
};


#endif //MARIOPROJECT_ENDWINDOW_H
