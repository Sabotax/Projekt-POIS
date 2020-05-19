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
sf::Texture LoadOneTexture(std::string path);

std::map< std::string,sf::Texture> LoadTexturesMap();
void SetRepeatMap(std::map<std::string, sf::Texture>& tekstury);

#endif // HEADER_H
