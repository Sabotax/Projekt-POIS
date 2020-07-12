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
#include <random>
//klasy
sf::Texture LoadOneTexture(std::string path);
std::map< std::string,sf::Texture> LoadTextures();
void SetRepeat(std::map<std::string, sf::Texture>& tekstury);
std::shared_ptr<sf::Sprite> InitiateBackground(const sf::Texture& wall_texture,const sf::Vector2u& wymiary);
void start_dumb_cpp_static_variables();
void debug(std::string id, std::string opis);
void debug(std::string id, int opis);
void debug(std::string id, double opis);
void debug(std::string id);
std::vector< std::shared_ptr < sf::Sprite> > InitiateWalls(const sf::Texture& texture);
std::shared_ptr< sf::Sprite > InitiateBanner(const sf::Texture& texture,const sf::Vector2u& wymiary);
sf::SoundBuffer LoadOneSoundBuffer(std::string path);
std::map< std::string,sf::SoundBuffer> LoadSounds();
int randomInt(int min, int max);
#include "Tile.h"
#include "Character.h"
#include "Hero.h"
#include "Music.h"
#include "Timer.h"
#include "baner_odliczanie.h"
#include "serca.h"
#include "pocisk.h"
#include "enemy.h"

#endif // HEADER_H
