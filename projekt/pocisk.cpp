#include "Header.h"
std::vector<std::shared_ptr<pocisk>> pocisk::pociski;

pocisk::pocisk(std::string zwrot, std::shared_ptr<Tile> startowy_tile)
{
    int wymiar_dluzszy = 10;
    int wymiar_krotszy = 2;
    this->zwrot = zwrot;
    //std::shared_ptr< Tile > startowy_tile = character->polozenie_tile;
    if(zwrot == "lewo") {
        sprite = std::make_shared<sf::RectangleShape>( sf::Vector2f(wymiar_dluzszy,wymiar_krotszy));
        sprite->setPosition(startowy_tile->polozenie.x + Tile::tile_px_width/2 - wymiar_dluzszy,startowy_tile->polozenie.y + Tile::tile_px_width/2+1);//+1 zeby na "srodku (1 pixel)"
    }
    if(zwrot == "prawo") {
        sprite = std::make_shared<sf::RectangleShape>(sf::Vector2f(wymiar_dluzszy,wymiar_krotszy));
        sprite->setPosition(startowy_tile->polozenie.x + Tile::tile_px_width/2,startowy_tile->polozenie.y + Tile::tile_px_width/2+1);
    }
    if(zwrot == "gora") {
        sprite = std::make_shared<sf::RectangleShape>(sf::Vector2f(wymiar_krotszy,wymiar_dluzszy));
        sprite->setPosition(startowy_tile->polozenie.x + Tile::tile_px_width/2 + 1,startowy_tile->polozenie.y + Tile::tile_px_width/2 - wymiar_dluzszy);
    }
    if(zwrot == "dol") {
        sprite = std::make_shared<sf::RectangleShape>(sf::Vector2f(wymiar_krotszy,wymiar_dluzszy));
        sprite->setPosition(startowy_tile->polozenie.x + Tile::tile_px_width/2 + 1,startowy_tile->polozenie.y + Tile::tile_px_width/2 );
    }

    sprite->setFillColor(sf::Color(0,0,0));


}
void pocisk::animuj(double elapsed) {
    if(zwrot == "lewo") {
        sprite->move(-speed * elapsed, 0);
    }
    if(zwrot == "prawo") {
        sprite->move(speed * elapsed, 0);
    }
    if(zwrot == "gora") {
        sprite->move(0, -speed * elapsed);
    }
    if(zwrot == "dol") {
        sprite->move(0, speed * elapsed);
    }

    // TODO check for kill enemy (prawdopodobnie w enemy, ale moze i nie
    // TODO check for out of window -> destruktuje, (destruktuje nie tutaj tylko na zewnatrz prawdopodobnie
    // TODO byc moze beda potrzebne pola obecny tile pocisku itp, zeby poprawnie zabijac wrogow
    // TODO oczywiscie w hero razem obok blokady ruchu w turze, będą musiały być blokady strzałów
}
std::shared_ptr<pocisk> pocisk::getptr() {
    return std::shared_ptr<pocisk>(this);
}
