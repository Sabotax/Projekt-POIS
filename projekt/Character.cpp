#include "Header.h"

double Character::czas_animacji;
//c++ to największe gówno ze wszystkich, 30 min na szukanie fixów na takie coś

void Character::move(const std::string& direction, const double& elapsed) {

    //nice teraz wzorem to zrobić by move skakało o ileś pixeli w połączeniu z elapsed
    if(czy_w_trakcie_animacji) {
        if(direction == "up") {

        }
        else if(direction == "down") {

        }
        else if(direction == "left") {
            if(moment_animacji <= czas_animacji/2) {
                sprite->move(-1,1/10);
                // cos w stylu TODO
                // zliczanie += iles pixeli dopoki 61 nie pyknie, tak samo zarzadzenie "skokiem do góry i w dół"
            }
            else if (moment_animacji >= czas_animacji/2) {
                sprite->move(-1,-1/10);
            }

        }
        else if(direction == "right") {

        }
    }


    moment_animacji += elapsed;

    if(moment_animacji >= Character::czas_animacji) {
        czy_w_trakcie_animacji = false;
        moment_animacji = 0;
    }
}
void Character::start_move() {
    czy_w_trakcie_animacji = true;
}
Character::Character() {
    czy_w_trakcie_animacji = false;
}
