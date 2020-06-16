#include "Header.h"


Hero::Hero(const sf::Texture& texture, std::shared_ptr<Tile> tile) {
    sprite = std::make_shared<sf::Sprite>();
    polozenie_tile = tile;
    //test = "test1231";
    sprite->setTexture(texture);
    sprite->setPosition(polozenie_tile->polozenie.x, polozenie_tile->polozenie.y);
    czy_w_trakcie_animacji = false;
    polozenie_tile->czy_zajete = true;
}
void Hero::strzel(std::string zwrot) {
    pocisk::pociski.emplace_back( std::make_shared<pocisk>(zwrot, polozenie_tile) );
}
//TODO przepisać na konstruktor i pola (position to pole Tile)
