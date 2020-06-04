#ifndef MUSIC_H
#define MUSIC_H
#include <Header.h>

class Music
{
public:
    std::shared_ptr< sf::Music > soundtrack;
    std::vector< double > okienka_czasowe;
    std::vector< sf::Vector2f > pauzy;
    Music(std::shared_ptr<sf::Music> soundtrack, std::string nazwa, std::vector<double> okienka_czasowe, std::vector<sf::Vector2f> pauzy );
    int odliczanie_indexu;
    std::string nazwa;
    static void InitiateMusics();
    static std::vector< std::shared_ptr<Music> > muzyki_tab;
    static std::vector< std::string>  wektory_inicjalizacja_nazwa;
};

#endif // MUSIC_H
