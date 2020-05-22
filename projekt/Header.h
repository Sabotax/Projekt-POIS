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
sf::Texture LoadOneTexture(std::string path);
std::map< std::string,sf::Texture> LoadTextures();
void SetRepeat(std::map<std::string, sf::Texture>& tekstury);
std::shared_ptr<sf::Sprite> InitiateMapWall(const sf::Texture& wall_texture, sf::Vector2u wymiary);
void start_dumb_cpp_static_variables();
void debug(std::string id, std::string opis);
void debug(std::string id, int opis);
void debug(std::string id, double opis);
void debug(std::string id);

#include "Tile.h"
#include "Character.h"
#include "Hero.h"

#endif // HEADER_H
