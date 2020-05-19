#ifndef HEADER_H
#define HEADER_H
//include
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
//klasy
class Tile;
namespace Boot {
    static std::vector<sf::Texture> tekstury;
    void LoadTextures();
    void Boot(std::unique_ptr< sf::RenderWindow > window);
}

#endif // HEADER_H
