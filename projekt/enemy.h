#ifndef ENEMY_H
#define ENEMY_H
#include "Header.h"

class enemy:public Character
{
public:
    enemy(const sf::Texture& texture, std::shared_ptr<Tile> tile);
    static std::vector<std::shared_ptr<enemy> > tab_enemies;
    static bool zniszcz_enemy_na_tile_od_pocisk(std::shared_ptr<Tile> tile_pocisku);
    sf::Vector2i pozycja_wzgledem_bohatera(std::shared_ptr<Hero> hero);
    void dzialaj();
    static void spawn_enemies();
    static sf::Texture tex;
    static void ustaw_statyczne_tex( sf::Texture tex);
};

#endif // ENEMY_H
