#include "Header.h"

sf::Texture LoadOneTexture(std::string path) {
    sf::Texture texture;
    if (!texture.loadFromFile(path)) {
        std::cerr << "Could not load texture at " << path << std::endl;
    }
    return texture;
}
std::map< std::string,sf::Texture> LoadTextures() {
    std::map<std::string, sf::Texture> re;
    re.emplace("grass",LoadOneTexture("../textures/grass.png"));
    re.emplace("wall",LoadOneTexture("../textures/wall.png"));
    re.emplace("hero1",LoadOneTexture("../textures/proba3d-2-filled.png"));
    SetRepeat(re);
    return re;
}
void SetRepeat(std::map<std::string, sf::Texture>& tekstury) {
    tekstury["wall"].setRepeated(true);
}
sf::Sprite InitiateMapWall(const sf::Texture& wall_texture, sf::Vector2u wymiary) {
    sf::Sprite wall;
    wall.setTexture(wall_texture);
    double skala = 0.3;
    wall.setScale(0.3, 0.3);
    wall.setTextureRect(sf::IntRect(0, 0, wymiary.x/skala, wymiary.y/skala));
    wall.setPosition(0,0);
    return wall;
}
sf::Sprite InitiateHero(const sf::Texture& hero_texture, sf::Vector2u wymiary) {
    sf::Sprite hero;
    hero.setTexture(hero_texture);
    hero.setPosition(wymiary.x / 2,wymiary.y / 2);
    return hero;
}
//std::vector< std::vector < std::unique_ptr<sf::Sprite> > > GenerateTilesVector(sf::Texture& temp_tex,sf::Vector2u wymiary) {
std::vector< std::vector < std::shared_ptr<sf::Sprite >> > GenerateTilesVector(const sf::Texture& temp_tex,sf::Vector2u wymiary) {
    int poswiecone_na_przerwy = 3;
    int ilosc_x = wymiary.x / 50 - poswiecone_na_przerwy;
    int ilosc_y = wymiary.y / 50 - poswiecone_na_przerwy + 1;

    std::vector< std::vector < std::shared_ptr<sf::Sprite >> > re;
    for(int i = 0; i < ilosc_y ; i++) {
        std::vector < std::shared_ptr<sf::Sprite >> temp_vec;

        for(int j = 0; j < ilosc_x; j++) {
            //std::unique_ptr<sf::Sprite> temp = std::make_unique<sf::Sprite>();
            std::shared_ptr<sf::Sprite> temp = std::make_shared<sf::Sprite>();
            // funkcja od set textures co drugie ma byc osobno
            // temporary tu jest ustawianie skina
            temp->setTexture(temp_tex);
            //temp->setPosition(i*50+10*i,0);
            // aka
            temp->setPosition(j*61+10,i*60+5);
            temp->setScale(0.2,0.2); //tekstura ma 250, tile ma mieć 50
            //temp->setPosition()
            temp_vec.emplace_back(temp);
            std::cout << "tu mnie wyjebuje" << std::endl;
        }
        re.emplace_back(temp_vec);
    }
    std::cout << re.size() << "\t" << re[0].size() << std::endl;
    return re;
}
