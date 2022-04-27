
#include <sys/socket.h>
#include "Character.h"



void Character::setRight(bool right) {
    this->right = right;
}

void Character::setUp(bool up) {
    this->up = up;
}

void Character::setLeft(bool left) {
    this->left = left;
}

void Character::setDown(bool down) {
    this->down = down;
}
void Character::move() {

    if (left) {
        start=true;
        setPos(x()-15,y());
    }
    if (right) {
        start=true;
        setPos((x()+15), y());
    }
    if (up){
        start=true;
        if (nbJump<=0)//essayer de faire en sorte que quand on appuie sur la touche espace ça réduise le nombre de saut dispo
        return;
    if (countJump > 7){
        nbJump--;
        countJump =0;
    }
    else {
            countJump++;
            setPos(x(), y()-40);
        }
    }
    this->hitbox->setPos(this->pos());
}
 QGraphicsRectItem &Character::getHitbox() {
    return *hitbox;
}
float Character::getGravity() {
    return this ->gravity;
}



















