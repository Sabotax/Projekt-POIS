#include "Header.h"

std::vector<std::shared_ptr<enemy> > enemy::tab_enemies;

enemy::enemy(const sf::Texture& texture, std::shared_ptr<Tile> tile) {
    sprite = std::make_shared<sf::Sprite>();
    polozenie_tile = tile;
    sprite->setTexture(texture);
    sprite->setPosition(polozenie_tile->polozenie.x, polozenie_tile->polozenie.y);
    czy_w_trakcie_animacji = false;
}
void enemy::make_enemies(const sf::Texture& texture) {
    tab_enemies.emplace_back( std::make_shared<enemy>(texture, Tile::tiles_tab[4][5]));
}
bool enemy::zniszcz_enemy_na_tile_od_pocisk(std::shared_ptr<Tile> tile_pocisku) {
    std::vector<std::vector<std::shared_ptr<enemy>>::iterator> do_skasowania;
    bool re = false;
    for(std::vector<std::shared_ptr<enemy>>::iterator it = tab_enemies.begin(); it != tab_enemies.end() ; it++) {
        if( it->operator*().polozenie_tile == tile_pocisku) {
            do_skasowania.emplace_back(it);
            re = true;
        }
    }
    for(auto& x : do_skasowania) {
        //debug("kasuje wroga");
        tab_enemies.erase(x);
    }
    return re;
}
