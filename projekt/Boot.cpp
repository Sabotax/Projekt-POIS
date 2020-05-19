#include "Header.h"

namespace Boot {
    void LoadTextures() {
//        tekstury.emplace("grass", LoadOneTexture("../textures/grass.png"));
//        tekstury.emplace("wall", LoadOneTexture("../textures/wall.png"));

//        tekstury["grass"] = std::make_shared<sf::Texture>(LoadOneTexture("../textures/grass.png"));
//        tekstury["wall"] = std::make_shared<sf::Texture>(LoadOneTexture("../textures/wall.png"));

        //tekstury.emplace("grass", std::make_shared<sf::Texture>(LoadOneTexture("../textures/grass.png"));

        tekstury.emplace_back(LoadOneTexture("../textures/grass.png"));
    }
    sf::Texture LoadOneTexture(std::string path) {
        sf::Texture texture;
        if (!texture.loadFromFile(path)) {
            std::cerr << "Could not load texture at " << path << std::endl;
        }
        return texture;
    }
    void Boot(std::unique_ptr< sf::RenderWindow > window) {
        LoadTextures();

//        sf::Sprite grass;
//        grass.setTexture(tekstury["grass"]);
//        double skala = 0.3;
//        grass.setScale(skala, skala);
//        grass.setTextureRect(sf::IntRect(0, 0, window->getSize().x*1/skala, window->getSize().y*1/skala));
//        grass.setPosition(0,0);

    }
    void Boot() {
        LoadTextures();
    }
//    std::map< std::string , sf::Texture > getTekstury() {
//        return tekstury;
//    }
};

std::vector< sf::Texture> LoadTextures() {
    std::vector< sf::Texture> re;
    re.emplace_back(LoadOneTexture("../textures/grass.png"));
    re.emplace_back(LoadOneTexture("../textures/wall.png"));
    SetRepeat(re);
    return re;
}
sf::Texture LoadOneTexture(std::string path) {
    sf::Texture texture;
    if (!texture.loadFromFile(path)) {
        std::cerr << "Could not load texture at " << path << std::endl;
    }
    return texture;
}
void SetRepeat(std::vector< sf::Texture>& tekstury) {
    tekstury[0].setRepeated(true);
}
