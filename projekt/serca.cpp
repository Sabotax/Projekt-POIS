#include "Header.h"

std::vector<std::shared_ptr < serca > > serca::serca_tab;
int serca::ilosc_serc=10;
int serca::ilosc_pelnych_serc=serca::ilosc_serc;
//sf::Texture *serca::tex_pelne;
//sf::Texture *serca::tex_puste;

serca::serca()
{
    sprite = std::make_shared<sf::Sprite>();
}
void serca::utworz_serca(const sf::Texture& tex_pelne) {

    for(size_t i =0 ; i < ilosc_serc ; i++) {
        std::shared_ptr<serca> ob = std::make_shared<serca>();
        ob->sprite->setTexture(tex_pelne);
        ob->sprite->setPosition(20 + i * 40 + i * 10,0 + Tile::zarezerwowane_z_gory - 40 - 10);
        serca_tab.emplace_back(ob);
    }
}
void serca::strac_zycie(const sf::Texture& tex_puste) {
    ilosc_pelnych_serc--;
    // jesli ilosc pelnych = 0 lose game TODO
    if(ilosc_pelnych_serc == 0 ) {
        std::cout << "Przegrales" <<std::endl;
    }
    else {
        serca::serca_tab[serca_tab.size()-(ilosc_serc-ilosc_pelnych_serc)]->sprite->setTexture(tex_puste);
    }

}
//void ustaw_statyczne_tekstury(const sf::Texture& tex_puste ) {
//    serca::tex_pelne = &tex_pelne;
//}
