#ifndef TILE_H
#define TILE_H
#include "Header.h"

class Tile {
public:
    std::shared_ptr< sf::Sprite > sprite;
    sf::Vector2i polozenie;
    //std::shared_ptr< Tile > koordy_w_pamieci;
    //static std::vector< std::vector < std::shared_ptr<sf::Sprite >> > GenerateTilesVector(const sf::Texture& temp_tex,sf::Vector2u wymiary);
    static std::vector< std::vector < std::shared_ptr< Tile >> > GenerateTilesVector(const sf::Texture& temp_tex,sf::Vector2u wymiary);
//    void setTexture(sf::Texture texture);
    Tile(int x, int y, const sf::Texture& texture);
    //std::shared_ptr< Tile > getTileAt(int x, int y);
};

#endif // TILE_H
