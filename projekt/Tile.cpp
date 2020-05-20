#include "Header.h"

std::vector< std::vector < std::shared_ptr<Tile >> > Tile::GenerateTilesVector(const sf::Texture& texture,sf::Vector2u wymiary) {
    int poswiecone_na_przerwy = 3;
    int ilosc_x = wymiary.x / 50 - poswiecone_na_przerwy;
    int ilosc_y = wymiary.y / 50 - poswiecone_na_przerwy + 1;

    std::vector< std::vector < std::shared_ptr<Tile >> > re;
    for(int i = 0; i < ilosc_x ; i++) {
        std::vector < std::shared_ptr<Tile >> temp_vec;

        for(int j = 0; j < ilosc_y; j++) {
            //std::unique_ptr<sf::Sprite> temp = std::make_unique<sf::Sprite>();
            std::shared_ptr< Tile > temp_obiekt = std::make_shared<Tile>(i*60+5,j*61+10, texture);

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
    std::cout << re.size() << "\t" << re[0].size() << std::endl;
    return re;
}
//void Tile::setTexture(sf::Texture texture) {
//    sprite->setTexture(texture);
//}
Tile::Tile(int x, int y, const sf::Texture& texture)  {
    sprite = std::make_shared<sf::Sprite>();
    polozenie.x = x;
    polozenie.y = y;
    sprite->setPosition(polozenie.x,polozenie.y);
    sprite->setTexture(texture);
}
//std::shared_ptr< Tile > Tile::getTileAt(int x, int y) {
//    return return_from_this();
//}
// TODO przepisać tamto by działało na obiektach tile, tj vector<sprite>, vector<tile>, Tile ma pole z sprite
