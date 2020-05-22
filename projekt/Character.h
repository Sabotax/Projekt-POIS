#ifndef CHARACTER_H
#define CHARACTER_H
#include "Header.h"

class Character {
public:
    std::shared_ptr< Tile > polozenie_tile;
    std::string test;
    std::shared_ptr< sf::Sprite > sprite;
    //double moment_animacji;
    //static double czas_animacji;
    bool czy_w_trakcie_animacji;
    double frame_counter = 0;
    static sf::Vector2i frame_counter_max;
    static double animation_speed;
    std::string direction;
    //sf::Vector2i przewidywane_polozenie_na_koniec_animacji;
    void move();
    void start_move(const std::string& direction);
    Character();
    static void initialize_statics();
};
#endif // CHARACTER_H
