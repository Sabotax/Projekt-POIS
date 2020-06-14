#ifndef SERCA_H
#define SERCA_H
#include "Header.h"

class serca
{
public:
    serca();
    std::shared_ptr<sf::Sprite> sprite;
    static std::vector<std::shared_ptr < serca > > serca_tab;
    static int ilosc_serc;
    static int ilosc_pelnych_serc;
    static void utworz_serca(const sf::Texture& tex_pelne);
    static void strac_zycie(const sf::Texture& tex_puste);
//    static sf::Texture* tex_pelne;
//    static sf::Texture* tex_puste; //no niestety
    void ustaw_statyczne_tekstury(const sf::Texture& tex_pelne, const sf::Texture& tex_puste );
};

#endif // SERCA_H
