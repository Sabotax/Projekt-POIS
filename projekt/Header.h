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
    static std::map< std::string , sf::Texture > tekstury;
    void LoadTextures();
    sf::Texture LoadOneTexture(std::string path);
    void Boot(std::unique_ptr< sf::RenderWindow > window);
    void Boot();
}

#endif // HEADER_H
