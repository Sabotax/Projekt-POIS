#ifndef ENEMY_H
#define ENEMY_H
#include "Header.h"

class enemy:public Character
{
public:
    enemy(const sf::Texture& texture, std::shared_ptr<Tile> tile);
    static std::vector<std::shared_ptr<enemy> > tab_enemies;
    static void make_enemies(const sf::Texture& texture);
    static bool zniszcz_enemy_na_tile_od_pocisk(std::shared_ptr<Tile> tile_pocisku);
};

#endif // ENEMY_H
