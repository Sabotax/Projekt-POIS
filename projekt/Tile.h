#ifndef TILE_H
#define TILE_H
#include "Header.h"

class Tile {
public:
    std::shared_ptr< sf::Sprite > sprite;
    sf::Vector2i polozenie;
    sf::Vector2i polozenie_w_vector;
    static int tile_px_width;
    static int break_px_width;
    static std::vector< std::vector < std::shared_ptr< Tile >> > tiles_tab;
    //std::shared_ptr< Tile > koordy_w_pamieci;
    //static std::vector< std::vector < std::shared_ptr<sf::Sprite >> > GenerateTilesVector(const sf::Texture& temp_tex,sf::Vector2u wymiary);
    static void GenerateTilesVector(const sf::Texture& temp_tex,sf::Vector2u wymiary);
//    void setTexture(sf::Texture texture);
    Tile(int x, int y, const sf::Texture& texture,int x1, int y1);
    //std::shared_ptr< Tile > getTileAt(int x, int y);
    static void initialize_statics();
    static int ilosc_x;
    static int ilosc_y;
    static int zarezerwowane_z_gory;
    static int zarezerwowane_z_gory_na_sciane;
    static int zarezerwowane_z_lewej;
};

#endif // TILE_H
