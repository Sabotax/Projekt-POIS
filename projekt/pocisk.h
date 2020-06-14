#ifndef POCISK_H
#define POCISK_H
#include "Header.h"

class pocisk
{
public:
    std::string zwrot;
    int speed = 2000;
    std::shared_ptr<sf::RectangleShape> sprite;
    pocisk(std::string zwrot, std::shared_ptr<Tile> startowy_tile);
    void animuj(double elapsed);
    static std::vector<std::shared_ptr<pocisk>> pociski;
    std::vector< std::shared_ptr <Tile> > lista_potencjalnie_przebytych_tileow;
    void wyznacz_liste_potencjalnie_przebytych_tileow();
    std::shared_ptr<Tile> startowy_tile;
    bool czy_pocisk_przekroczyl_srodek_tile(std::shared_ptr<Tile> tile);
    sf::Vector2f pozycja;
    sf::Vector2i size;
    void update_pozycji();
    static void zarzadzaj_pociskami();
    void wyznacz_obecny_tile();
    std::shared_ptr<Tile> obecny_tile;
    bool czy_przekroczyl_ostatni_tile();
};

#endif // POCISK_H
