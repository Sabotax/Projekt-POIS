#include "Header.h"

std::shared_ptr<baner_odliczanie> baner_odliczanie::ob;

baner_odliczanie::baner_odliczanie(double val1, double val2)
{
    //val 1 i 2 to czasy w wektorze okienek czasowych
    //debug("Tyczka: ", "nowy obiekt tworze");
    tyczka = std::make_shared<sf::RectangleShape>(sf::Vector2f(5,Tile::zarezerwowane_z_gory-20));
    wyznaczSpeed(val1,val2);
    tyczka->setPosition(Tile::szerokosc_okna - 150,0 + 10);
    tyczka->setFillColor(sf::Color(56, 56, 122));

}
void baner_odliczanie::wyznaczSpeed(double odkad, double dokad) {
    double distance = 100; // pixeli, (dystans między rec start, a rect end)
    double time = dokad - odkad;
    //debug("time: ", time);
    speed = distance / time;
    //speed = 1;
}
std::vector< std::shared_ptr<sf::RectangleShape>> baner_odliczanie::create_position_rectangles() {
    std::vector< std::shared_ptr<sf::RectangleShape>> re;

    std::shared_ptr< sf::RectangleShape> start = std::make_shared<sf::RectangleShape>( sf::Vector2f(5,Tile::zarezerwowane_z_gory-20));
    start->setPosition(Tile::szerokosc_okna - 155,0 + 10);
    start->setFillColor(sf::Color(0, 0, 0));

    re.emplace_back(start);

    std::shared_ptr< sf::RectangleShape> end = std::make_shared<sf::RectangleShape>( sf::Vector2f(5,Tile::zarezerwowane_z_gory-20));
    end->setPosition(Tile::szerokosc_okna - 50,0 + 10);
    end->setFillColor(sf::Color(0, 0, 0));

    re.emplace_back(end);
    return re;
}
bool baner_odliczanie::check_for_destroy() {
    sf::FloatRect dane = tyczka->getGlobalBounds();
    if(dane.left >= Tile::szerokosc_okna - 50) return true;
    else return false;
}
void baner_odliczanie::animate(double elapsed) {
    tyczka->move(speed*elapsed,0);
    sf::FloatRect dane = tyczka->getGlobalBounds();
    //debug("Tyczka speed" , speed*elapsed);
    //debug("Tyczka pos x" , dane.left);
    //debug("Tyczka pos y" , dane.top);
}
