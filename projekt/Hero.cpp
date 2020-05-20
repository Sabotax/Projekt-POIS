// public from character
// TODO set poruszanie poprzez skakanie o 50 w bok, jeśli się da poprzez animację

#include "Header.h"
//std::shared_ptr<sf::Sprite> Hero::InitiateHero(const sf::Texture& hero_texture, sf::Vector2u wymiary) {
//    std::shared_ptr<sf::Sprite> hero = std::make_shared<sf::Sprite>();
//    hero->setTexture(hero_texture);
//    hero->setPosition(wymiary.x / 2,wymiary.y / 2);
//    return hero;
//}
Hero::Hero(const sf::Texture& texture, std::shared_ptr<Tile> tile) {
    sprite = std::make_shared<sf::Sprite>();
    polozenie_tile = tile;
    test = "test1231";
    sprite->setTexture(texture);
    sprite->setPosition(polozenie_tile->polozenie.x, polozenie_tile->polozenie.y);
}
//TODO przepisać na konstruktor i pola (position to pole Tile)
