#include "Header.h"

namespace Boot {
    //static std::vector<sf::Texture> tekstury;
    void LoadTextures() {
        sf::Texture texture_grass;
        if (!texture_grass.loadFromFile("../textures/grass.png")) {
            std::cerr << "Could not load texture" << std::endl;
        }

        tekstury.emplace_back(texture_grass);
    }
    void Boot(std::unique_ptr< sf::RenderWindow > window) {
        LoadTextures();
        sf::Sprite grass;
        grass.setTexture(tekstury[0]);
        double skala = 0.3;
        grass.setScale(skala, skala);
        grass.setTextureRect(sf::IntRect(0, 0, window->getSize().x*1/skala, window->getSize().y*1/skala));
        grass.setPosition(0,0);
    }
};
