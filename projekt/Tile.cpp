#include "Header.h"

std::vector< std::vector < std::shared_ptr< Tile >> > Tile::tiles_tab;
std::vector<   std::shared_ptr< Tile > > Tile::tiles_miganie_1_tab;
std::vector<  std::shared_ptr< Tile > > Tile::tiles_miganie_2_tab;
int Tile::tile_px_width;
int Tile::break_px_width;
int Tile::ilosc_x;
int Tile::ilosc_y;
int Tile::zarezerwowane_z_gory;
int Tile::zarezerwowane_z_gory_na_sciane;
int Tile::zarezerwowane_z_lewej;
sf::Texture Tile::tex1;
sf::Texture Tile::tex2;
int Tile::szerokosc_okna;
int Tile::wysokosc_okna;

void Tile::GenerateTilesVector(const sf::Texture& texture,sf::Vector2u wymiary) {

    std::vector< std::vector < std::shared_ptr<Tile >> > re;
    bool mig = true;
    for(int i = 0; i < ilosc_x ; i++) {
        std::vector < std::shared_ptr<Tile >> temp_vec;

        for(int j = 0; j < ilosc_y; j++) {
            //std::unique_ptr<sf::Sprite> temp = std::make_unique<sf::Sprite>();
            std::shared_ptr< Tile > temp_obiekt = std::make_shared<Tile>(zarezerwowane_z_lewej+i*(tile_px_width + break_px_width)+break_px_width,zarezerwowane_z_gory_na_sciane+zarezerwowane_z_gory+j*(tile_px_width+break_px_width)+break_px_width, texture,i,j);

            // funkcja od set textures co drugie ma byc osobno
            // temporary tu jest ustawianie skina

            //temp_obiekt->setTexture(temp_tex);
            //temp->setPosition(i*50+10*i,0);
            // aka
            //temp_obiekt->sprite->setPosition(j*61+10,i*60+5);
            temp_obiekt->sprite->setScale(0.2,0.2); //tekstura ma 250, tile ma mieć 50
            //temp->setPosition()

            // dodawanie do tablic migania
            temp_vec.emplace_back(temp_obiekt);


            if(mig) {
                Tile::tiles_miganie_1_tab.emplace_back(temp_obiekt);
            }
            else {
                Tile::tiles_miganie_2_tab.emplace_back(temp_obiekt);
            }
            mig = !mig;
            //std::cout << "tu mnie wyjebuje" << std::endl;
        }
        re.emplace_back(temp_vec);
    }
    //std::cout << re.size() << "\t" << re[0].size() << std::endl;
    Tile::tiles_tab = re;
    //return re;
}
void Tile::GenerateTilesVector(const sf::Texture& texture_one, const sf::Texture& texture_two ,sf::Vector2u wymiary) {

    std::vector< std::vector < std::shared_ptr<Tile >> > re;
    bool mig = true;
    for(int i = 0; i < ilosc_x ; i++) {
        std::vector < std::shared_ptr<Tile >> temp_vec;

        for(int j = 0; j < ilosc_y; j++) {
            //std::unique_ptr<sf::Sprite> temp = std::make_unique<sf::Sprite>();
            std::shared_ptr< Tile > temp_obiekt = std::make_shared<Tile>(zarezerwowane_z_lewej+i*(tile_px_width + break_px_width)+break_px_width,zarezerwowane_z_gory_na_sciane+zarezerwowane_z_gory+j*(tile_px_width+break_px_width)+break_px_width,
                                                                         mig ? texture_one : texture_two,i,j);

            // funkcja od set textures co drugie ma byc osobno
            // temporary tu jest ustawianie skina

            //temp_obiekt->setTexture(temp_tex);
            //temp->setPosition(i*50+10*i,0);
            // aka
            //temp_obiekt->sprite->setPosition(j*61+10,i*60+5);
            temp_obiekt->sprite->setScale(0.2,0.2); //tekstura ma 250, tile ma mieć 50
            //temp->setPosition()

            // dodawanie do tablic migania
            temp_vec.emplace_back(temp_obiekt);


            if(mig) {
                Tile::tiles_miganie_1_tab.emplace_back(temp_obiekt);
            }
            else {
                Tile::tiles_miganie_2_tab.emplace_back(temp_obiekt);
            }
            mig = !mig;
            //std::cout << "tu mnie wyjebuje" << std::endl;
        }
        re.emplace_back(temp_vec);
    }
    //std::cout << re.size() << "\t" << re[0].size() << std::endl;
    Tile::tiles_tab = re;
    //return re;
}
Tile::Tile(int x, int y, const sf::Texture& texture,int x1, int y1)  {
    sprite = std::make_shared<sf::Sprite>();
    polozenie.x = x;
    polozenie.y = y;
    sprite->setPosition(polozenie.x,polozenie.y);
    sprite->setTexture(texture);
    polozenie_w_vector.x = x1;
    polozenie_w_vector.y = y1;
}
void Tile::initialize_statics() {
    tile_px_width = 50;
    break_px_width = 10;
    ilosc_x = 22;
    ilosc_y = 11;
    zarezerwowane_z_gory = 60;
    zarezerwowane_z_gory_na_sciane = 16;
    zarezerwowane_z_lewej = 18;
    szerokosc_okna = 1366;
    wysokosc_okna = 768;
}
void Tile::migaj_szachownica(bool t) {
    //debug("migam szachownica");

    if(t) {
        for( std::shared_ptr<Tile> x : Tile::tiles_miganie_1_tab) {
            x->sprite->setTexture(Tile::tex1);
        }
        for( std::shared_ptr<Tile> x : Tile::tiles_miganie_2_tab) {
            x->sprite->setTexture(Tile::tex2);
        }
    }
    else {
        for( std::shared_ptr<Tile> x : Tile::tiles_miganie_1_tab) {
            x->sprite->setTexture(Tile::tex2);
        }
        for( std::shared_ptr<Tile> x : Tile::tiles_miganie_2_tab) {
            x->sprite->setTexture(Tile::tex1);
        }
    }


}
void Tile::ustaw_statyczne_tex( sf::Texture tex1, sf::Texture tex2) {
    Tile::tex1 = tex1;
    Tile::tex2 = tex2;
}
