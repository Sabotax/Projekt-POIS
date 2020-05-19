#ifndef HEADER_H
#define HEADER_H
//include
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include <map>
//klasy
class Tile;
namespace Boot {
    static std::vector<sf::Texture > tekstury;
    static std::string cos;
    void LoadTextures();
    sf::Texture LoadOneTexture(std::string path);
    void Boot(std::unique_ptr< sf::RenderWindow > window);
    void Boot();
    std::map< std::string , sf::Texture > getTekstury();
}
sf::Texture LoadOneTexture(std::string path);
std::vector< sf::Texture> LoadTextures();
void SetRepeat(std::vector< sf::Texture>& tekstury);

#endif // HEADER_H
