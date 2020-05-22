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
    re.emplace("hero1",LoadOneTexture("../textures/proba3d-2-filled.png"));
    re.emplace("wall",LoadOneTexture("../textures/wall.png"));
    re.emplace("red",LoadOneTexture("../textures/red.png"));
    SetRepeat(re);
    return re;
}
std::map< std::string,sf::Texture> LoadSounds() {
    std::map<std::string, sf::Texture> re;
    re.emplace("grass",LoadOneTexture("../textures/grass.png"));
    re.emplace("hero1",LoadOneTexture("../textures/proba3d-2-filled.png"));
    re.emplace("wall",LoadOneTexture("../textures/wall.png"));
    re.emplace("red",LoadOneTexture("../textures/red.png"));
    SetRepeat(re);
    return re;
}
void SetRepeat(std::map<std::string, sf::Texture>& tekstury) {
    tekstury["wall"].setRepeated(true);
}
std::shared_ptr<sf::Sprite> InitiateMapWall(const sf::Texture& wall_texture, sf::Vector2u wymiary) {
    std::shared_ptr<sf::Sprite> wall = std::make_shared<sf::Sprite>();
    wall->setTexture(wall_texture);
    double skala = 0.3;
    wall->setScale(0.3, 0.3);
    wall->setTextureRect(sf::IntRect(0, 0, wymiary.x/skala, wymiary.y/skala));
    wall->setPosition(0,0);
    return wall;
}

