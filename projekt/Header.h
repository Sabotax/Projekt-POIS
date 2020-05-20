#ifndef HEADER_H
#define HEADER_H
//include
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include <map>
#include <memory>
//klasy
class Tile;
sf::Texture LoadOneTexture(std::string path);

std::map< std::string,sf::Texture> LoadTextures();
void SetRepeat(std::map<std::string, sf::Texture>& tekstury);
sf::Sprite InitiateMapWall(const sf::Texture& wall_texture, sf::Vector2u wymiary);
sf::Sprite InitiateHero(const sf::Texture& hero_texture, sf::Vector2u wymiary);
std::vector< std::vector < std::shared_ptr<sf::Sprite >> > GenerateTilesVector(const sf::Texture& temp_tex,sf::Vector2u wymiary);

#endif // HEADER_H
