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
    static void utworz_serca();
    static void strac_zycie();
    static void ustaw_statyczne_tex( sf::Texture tex1, sf::Texture tex2);
    static sf::Texture tex_puste;
    static sf::Texture tex_pelne;

};

#endif // SERCA_H
