#ifndef HEADER_H
#define HEADER_H
//include
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <map>
#include <memory>
//klasy
class Tile;
sf::Texture LoadOneTexture(std::string path);

std::map< std::string,sf::Texture> LoadTextures();
void SetRepeat(std::map<std::string, sf::Texture>& tekstury);
std::shared_ptr<sf::Sprite> InitiateMapWall(const sf::Texture& wall_texture, sf::Vector2u wymiary);

#include "Tile.h"
#include "Character.h"
#include "Hero.h"


#endif // HEADER_H
