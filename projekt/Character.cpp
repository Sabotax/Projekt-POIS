#include "Header.h"

//double Character::czas_animacji;
sf::Vector2i Character::frame_counter_max;
double Character::animation_speed;
//c++ to największe gówno ze wszystkich, 30 min na szukanie fixów na takie coś

void Character::move() {
    double animation_speed = 3.27; //animation ? chyba speed
    //nice teraz wzorem to zrobić by move skakało o ileś pixeli w połączeniu z elapsed
    if(czy_w_trakcie_animacji) {
        if(direction == "up") {
            if(frame_counter <= Character::frame_counter_max.x/2) {
                sprite->move(0.25,-animation_speed);
                // cos w stylu TODO
                // zliczanie += iles pixeli dopoki 61 nie pyknie, tak samo zarzadzenie "skokiem do góry i w dół"
            }
            else if (frame_counter >= Character::frame_counter_max.x/2) {
                sprite->move(0.25,-animation_speed);
            }
        }
        else if(direction == "down") {
            if(frame_counter <= Character::frame_counter_max.x/2) {
                sprite->move(0.25,animation_speed);
                // cos w stylu TODO
                // zliczanie += iles pixeli dopoki 61 nie pyknie, tak samo zarzadzenie "skokiem do góry i w dół"
            }
            else if (frame_counter >= Character::frame_counter_max.x/2) {
                sprite->move(0.25,animation_speed);
            }
        }
        else if(direction == "left") {
            if(frame_counter <= Character::frame_counter_max.x/2.0) {
                sprite->move(-animation_speed,-0.5);
                // cos w stylu TODO
                // zliczanie += iles pixeli dopoki 61 nie pyknie, tak samo zarzadzenie "skokiem do góry i w dół"
            }
            else if (frame_counter >= Character::frame_counter_max.x/2.0) {
                sprite->move(-animation_speed,0.5);
            }

        }
        else if(direction == "right") {
            if(frame_counter <= Character::frame_counter_max.x/2) {
                sprite->move(animation_speed,-0.5);
                // cos w stylu TODO
                // zliczanie += iles pixeli dopoki 61 nie pyknie, tak samo zarzadzenie "skokiem do góry i w dół"
            }
            else if (frame_counter >= Character::frame_counter_max.x/2) {
                sprite->move(animation_speed,0.5);
            }
        }


        frame_counter += animation_speed;
        debug("check fps counter", frame_counter);
    }


    //moment_animacji += elapsed;

//    if(moment_animacji >= Character::czas_animacji) {
//        czy_w_trakcie_animacji = false;
//        moment_animacji = 0;
//    }
    // ustawic czy .x w poziom i .y w pion
    if(frame_counter >= Character::frame_counter_max.x) {
        //debug("wchodze tu");
        czy_w_trakcie_animacji = false;
        frame_counter = 0;

        //sprite->setPosition(przewidywane_polozenie_na_koniec_animacji.x,przewidywane_polozenie_na_koniec_animacji.y);


        if(direction == "up") {
            polozenie_tile = Tile::tiles_tab[polozenie_tile->polozenie_w_vector.x][polozenie_tile->polozenie_w_vector.y-1];
        }
        else if(direction == "down") {
            polozenie_tile = Tile::tiles_tab[polozenie_tile->polozenie_w_vector.x][polozenie_tile->polozenie_w_vector.y+1];
        }
        else if(direction == "left") {
            polozenie_tile = Tile::tiles_tab[polozenie_tile->polozenie_w_vector.x-1][polozenie_tile->polozenie_w_vector.y];
        }
        else if(direction == "right") {
            polozenie_tile = Tile::tiles_tab[polozenie_tile->polozenie_w_vector.x+1][polozenie_tile->polozenie_w_vector.y];
        }

        sprite->setPosition(polozenie_tile->polozenie.x,polozenie_tile->polozenie.y);
    }
}
void Character::start_move(const std::string& direction) {
    czy_w_trakcie_animacji = true;
    this->direction = direction;
    // tu w zaleznosci od left right up down
    //przewidywane_polozenie_na_koniec_animacji.x = polozenie_tile->polozenie.x - Tile::tile_px_width - Tile::break_px_width.x;
    //przewidywane_polozenie_na_koniec_animacji.y = polozenie_tile->polozenie.y;
}
Character::Character() {
    czy_w_trakcie_animacji = false;
}
void Character::initialize_statics() {
    frame_counter_max.x = Tile::tile_px_width + Tile::break_px_width.x;
    //debug("frame_counter_max.x",frame_counter_max.x);
    frame_counter_max.y = Tile::tile_px_width + Tile::break_px_width.y;
    //debug("frame_counter_max.y",frame_counter_max.y);
    animation_speed = 3.27; //dzieki fixowi kazde double moze byc
}
