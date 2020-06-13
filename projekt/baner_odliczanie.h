#ifndef BANER_ODLICZANIE_H
#define BANER_ODLICZANIE_H
#include "Header.h"

class baner_odliczanie
{
public:
    baner_odliczanie(double val1, double val2);
    double speed;
    //sf::Vector2i starting_pos;
    //sf::Vector2i ending_pos;
    void wyznaczSpeed(double odkad, double dokad);
    static std::vector< std::shared_ptr<sf::RectangleShape>> create_position_rectangles();
    void animate(double elapsed);
    std::shared_ptr< sf::RectangleShape> tyczka;
    bool check_for_destroy();
    static std::shared_ptr<baner_odliczanie> ob;
};

#endif // BANER_ODLICZANIE_H
