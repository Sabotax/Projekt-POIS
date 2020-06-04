#include "Header.h"

std::vector< std::shared_ptr<Music> > Music::muzyki_tab;
std::vector< std::string>  Music::wektory_inicjalizacja_nazwa;

Music::Music(std::shared_ptr<sf::Music> soundtrack, std::string nazwa, std::vector<double> okienka_czasowe, std::vector<sf::Vector2f> pauzy)
{
    this->soundtrack = soundtrack;
    this->nazwa = nazwa;
    this->okienka_czasowe = okienka_czasowe;
    this->pauzy = pauzy;
}
void Music::InitiateMusics() {

    std::vector< std::string>  wektory_inicjalizacja_nazwa;
    std::vector< std::string>  wektory_inicjalizacja_sciezka;
    //lvl 1 - papers please
    // 104 sekundy
    // bit - 1 s?
    wektory_inicjalizacja_nazwa.emplace_back("papers_please");
    wektory_inicjalizacja_sciezka.emplace_back("../audio/papers_please/papers_please.ogg");
    std::vector<double> temp_okienka_czasowe;
    double suma = 0;
    double czas_trwania = 104;
    double bit = 1;
    for(int i = 0; suma < czas_trwania; i++) {
        suma += bit;
        temp_okienka_czasowe.emplace_back(suma);
    }
    std::vector<sf::Vector2f> temp_pauzy;

    // TODO włączyć tą inicjalizacje w pętle, albo wyjebać pętle i po prostu tak jak u góry tworzyć muzyki w kodzie

    for(size_t i = 0 ; i < wektory_inicjalizacja_nazwa.size() ; i++) {

        //std::shared_ptr<sf::Sound> sound = std::make_shared<sf::Sound>();
        //sound->setBuffer(sounds_map[wektory_inicjalizacja_nazwa[i]]);
        //sound->play();
        std::shared_ptr<sf::Music> temp_music = std::make_shared<sf::Music>();
        if(!temp_music->openFromFile(wektory_inicjalizacja_sciezka[i])) {
            std::cerr << "Could not load music at " << wektory_inicjalizacja_sciezka[i] << std::endl;
        }
        std::shared_ptr<Music> obiekt = std::make_shared<Music>(temp_music,wektory_inicjalizacja_nazwa[i], temp_okienka_czasowe, temp_pauzy);
        Music::muzyki_tab.emplace_back(obiekt);
    }
    // TODO zrobić użytek z okienek czasowych i połączyć z timerem
}
