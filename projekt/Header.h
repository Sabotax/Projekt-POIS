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
    static std::map< std::string , std::shared_ptr< sf::Texture > > tekstury;
    static std::string cos;
    void LoadTextures();
    sf::Texture LoadOneTexture(std::string path);
    void Boot(std::unique_ptr< sf::RenderWindow > window);
    void Boot();
    std::map< std::string , sf::Texture > getTekstury();
}

#endif // HEADER_H
