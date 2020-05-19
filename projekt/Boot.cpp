#include "Header.h"

namespace Boot {
    void LoadTextures() {
        tekstury.emplace("grass", LoadOneTexture("../textures/grass.png"));
        tekstury.emplace("wall", LoadOneTexture("../textures/wall.png"));
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
};
