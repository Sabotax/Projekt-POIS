#include "Header.h"

sf::Texture LoadOneTexture(std::string path) {
    sf::Texture texture;
    if (!texture.loadFromFile(path)) {
        std::cerr << "Could not load texture at " << path << std::endl;
    }
    return texture;
}
std::map< std::string,sf::Texture> LoadTextures() {
    std::map<std::string, sf::Texture> re;
    re.emplace("grass",LoadOneTexture("../textures/grass.png"));
    re.emplace("hero1",LoadOneTexture("../textures/proba3d-2-filled.png"));
    re.emplace("wall",LoadOneTexture("../textures/wall.png"));
    re.emplace("red",LoadOneTexture("../textures/red.png"));
    re.emplace("debug1",LoadOneTexture("../textures/debug_tex.png"));
    re.emplace("brown",LoadOneTexture("../textures/brown.png"));
    re.emplace("banner",LoadOneTexture("../textures/bannersmall.png"));
    SetRepeat(re);
    return re;
}
sf::SoundBuffer LoadOneSoundBuffer(std::string path) {
    sf::SoundBuffer buffer;
    if (!buffer.loadFromFile(path)) {
        std::cerr << "Could not load soundbuffer at " << path << std::endl;
    }
    return buffer;
}
std::map< std::string,sf::SoundBuffer> LoadSounds() {
    std::map<std::string, sf::SoundBuffer> re;
    //re.emplace("papers_please",LoadOneSoundBuffer("../audio/papers_please/papers_please.ogg")); Music::wektory_inicjalizacja_nazwa.push_back("papers_please");
    return re;
}

void SetRepeat(std::map<std::string, sf::Texture>& tekstury) {
    tekstury["wall"].setRepeated(true);
    tekstury["brown"].setRepeated(true);
    tekstury["banner"].setRepeated(true);
}
std::shared_ptr<sf::Sprite> InitiateBackground(const sf::Texture& wall_texture,const sf::Vector2u& wymiary) {
    std::shared_ptr<sf::Sprite> wall = std::make_shared<sf::Sprite>();
    wall->setTexture(wall_texture);
    double skala = 0.3;
    wall->setScale(0.3, 0.3);
    wall->setTextureRect(sf::IntRect(0, 0, wymiary.x/skala, wymiary.y/skala));
    wall->setPosition(0,0);
    return wall;
}
std::vector< std::shared_ptr < sf::Sprite> > InitiateWalls(const sf::Texture& texture) {
    std::vector< std::shared_ptr <sf::Sprite > > re;
    for(int i =0; i < 8; i++) re.emplace_back( std::make_shared<sf::Sprite>() );
    //4 * 2 sciany
    std::vector< sf::Vector2i > pozycje;
    std::vector< sf::Vector2i > wymiary;

    int szerokosc_poziomej = Tile::zarezerwowane_z_lewej+9 * (Tile::tile_px_width+Tile::break_px_width);
    int wysokosc_poziomej = Tile::zarezerwowane_z_gory_na_sciane;

    int szerokosc_pionowej =  Tile::zarezerwowane_z_lewej;
    int wysokosc_pionowej = Tile::zarezerwowane_z_gory_na_sciane+ 4 *(Tile::tile_px_width+Tile::break_px_width)  ;
    //Poziome
    //lewo gora
    pozycje.emplace_back( sf::Vector2i(0,Tile::zarezerwowane_z_gory));
    wymiary.emplace_back( sf::Vector2i(szerokosc_poziomej,wysokosc_poziomej));

    //prawo gora
    pozycje.emplace_back( sf::Vector2i(Tile::zarezerwowane_z_lewej+10 * (Tile::tile_px_width+Tile::break_px_width)+Tile::break_px_width + 3 * Tile::tile_px_width + 3 * Tile::break_px_width,Tile::zarezerwowane_z_gory));
    wymiary.emplace_back( sf::Vector2i(szerokosc_poziomej,wysokosc_poziomej));

    //lewo dół
    pozycje.emplace_back( sf::Vector2i(0,Tile::zarezerwowane_z_gory+2*Tile::zarezerwowane_z_gory_na_sciane+11*(Tile::tile_px_width+Tile::break_px_width)));
    wymiary.emplace_back( sf::Vector2i(szerokosc_poziomej,wysokosc_poziomej));

    //prawo dół
    pozycje.emplace_back( sf::Vector2i(Tile::zarezerwowane_z_lewej+10 * (Tile::tile_px_width+Tile::break_px_width)+Tile::break_px_width + 3 * Tile::tile_px_width + 3 * Tile::break_px_width,Tile::zarezerwowane_z_gory+2*Tile::zarezerwowane_z_gory_na_sciane+11*(Tile::tile_px_width+Tile::break_px_width)));
    wymiary.emplace_back( sf::Vector2i(szerokosc_poziomej,wysokosc_poziomej));

    //Pionowe
    //lewo gora
    pozycje.emplace_back( sf::Vector2i(0,Tile::zarezerwowane_z_gory));
    wymiary.emplace_back( sf::Vector2i(szerokosc_pionowej,wysokosc_pionowej));

    //lewo dol
    pozycje.emplace_back( sf::Vector2i(0,Tile::break_px_width+Tile::zarezerwowane_z_gory_na_sciane+ 8 *(Tile::tile_px_width+Tile::break_px_width )));
    wymiary.emplace_back( sf::Vector2i(szerokosc_pionowej,wysokosc_pionowej));

    //prawo gora
    pozycje.emplace_back( sf::Vector2i(Tile::zarezerwowane_z_lewej+Tile::ilosc_x*(Tile::tile_px_width+Tile::break_px_width)+Tile::break_px_width,Tile::zarezerwowane_z_gory));
    wymiary.emplace_back( sf::Vector2i(szerokosc_pionowej,wysokosc_pionowej));

    //prawo dol
    pozycje.emplace_back( sf::Vector2i(Tile::zarezerwowane_z_lewej+Tile::ilosc_x*(Tile::tile_px_width+Tile::break_px_width)+Tile::break_px_width,Tile::break_px_width+Tile::zarezerwowane_z_gory_na_sciane+ 8 *(Tile::tile_px_width+Tile::break_px_width )));
    wymiary.emplace_back( sf::Vector2i(szerokosc_pionowej,wysokosc_pionowej));

    for(size_t i = 0; i < re.size();i++) {
        re[i]->setPosition(pozycje[i].x,pozycje[i].y);
        re[i]->setTextureRect(sf::IntRect(0,0,wymiary[i].x,wymiary[i].y));
        re[i]->setTexture(texture);
    }

    return re;
}
std::shared_ptr< sf::Sprite > InitiateBanner(const sf::Texture& texture,const sf::Vector2u& wymiary) {
    std::shared_ptr<sf::Sprite> re = std::make_shared<sf::Sprite>();
    re->setTexture(texture);
    re->setTextureRect(sf::IntRect(0, 0, wymiary.x, Tile::zarezerwowane_z_gory));
    re->setPosition(0,0);
    return re;
}

