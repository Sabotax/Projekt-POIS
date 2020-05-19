#include "Header.h"

sf::Texture LoadOneTexture(std::string path) {
    sf::Texture texture;
    if (!texture.loadFromFile(path)) {
        std::cerr << "Could not load texture at " << path << std::endl;
    }
    return texture;
}
std::map< std::string,sf::Texture> LoadTexturesMap() {
    std::map<std::string, sf::Texture> re;
    re.emplace("grass",LoadOneTexture("../textures/grass.png"));
    re.emplace("wall",LoadOneTexture("../textures/wall.png"));
    SetRepeatMap(re);
    return re;
}
void SetRepeatMap(std::map<std::string, sf::Texture>& tekstury) {
    tekstury["grass"].setRepeated(true);
}
