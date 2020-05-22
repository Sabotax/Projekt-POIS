#include "Header.h"

std::vector< std::vector < std::shared_ptr< Tile >> > Tile::tiles_tab;
int Tile::tile_px_width;
sf::Vector2i Tile::break_px_width;

void Tile::GenerateTilesVector(const sf::Texture& texture,sf::Vector2u wymiary) {
    int poswiecone_na_przerwy = 3;
    int ilosc_x = wymiary.x / 50 - poswiecone_na_przerwy;
    int ilosc_y = wymiary.y / 50 - poswiecone_na_przerwy + 1;

    std::vector< std::vector < std::shared_ptr<Tile >> > re;
    for(int i = 0; i < ilosc_x ; i++) {
        std::vector < std::shared_ptr<Tile >> temp_vec;

        for(int j = 0; j < ilosc_y; j++) {
            //std::unique_ptr<sf::Sprite> temp = std::make_unique<sf::Sprite>();
            std::shared_ptr< Tile > temp_obiekt = std::make_shared<Tile>(i*(tile_px_width + break_px_width.x)+break_px_width.x,j*(tile_px_width+break_px_width.y)+break_px_width.y, texture,i,j);

            // funkcja od set textures co drugie ma byc osobno
            // temporary tu jest ustawianie skina

            //temp_obiekt->setTexture(temp_tex);
            //temp->setPosition(i*50+10*i,0);
            // aka
            //temp_obiekt->sprite->setPosition(j*61+10,i*60+5);
            temp_obiekt->sprite->setScale(0.2,0.2); //tekstura ma 250, tile ma mieć 50
            //temp->setPosition()

            temp_vec.emplace_back(temp_obiekt);
            //std::cout << "tu mnie wyjebuje" << std::endl;
        }
        re.emplace_back(temp_vec);
    }
    //std::cout << re.size() << "\t" << re[0].size() << std::endl;
    Tile::tiles_tab = re;
    //return re;
}
Tile::Tile(int x, int y, const sf::Texture& texture,int x1, int y1)  {
    sprite = std::make_shared<sf::Sprite>();
    polozenie.x = x;
    polozenie.y = y;
    sprite->setPosition(polozenie.x,polozenie.y);
    sprite->setTexture(texture);
    polozenie_w_vector.x = x1;
    polozenie_w_vector.y = y1;
}
void Tile::initialize_statics() {
    tile_px_width = 50;
    break_px_width.x = 10;
    break_px_width.y = 10;
}
