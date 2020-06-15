#include "Header.h"
std::vector<std::shared_ptr<pocisk>> pocisk::pociski;

pocisk::pocisk(std::string zwrot, std::shared_ptr<Tile> startowy_tile)
{
    this->startowy_tile = startowy_tile;
    int wymiar_dluzszy = 10;
    int wymiar_krotszy = 2;
    this->zwrot = zwrot;
    //std::shared_ptr< Tile > startowy_tile = character->polozenie_tile;
    if(zwrot == "lewo") {
        sprite = std::make_shared<sf::RectangleShape>( sf::Vector2f(wymiar_dluzszy,wymiar_krotszy));
        sprite->setPosition(startowy_tile->polozenie.x + Tile::tile_px_width/2 - wymiar_dluzszy,startowy_tile->polozenie.y + Tile::tile_px_width/2+1);//+1 zeby na "srodku (1 pixel)"
        pozycja = sf::Vector2f(startowy_tile->polozenie.x + Tile::tile_px_width/2 - wymiar_dluzszy,startowy_tile->polozenie.y + Tile::tile_px_width/2+1);
        size = sf::Vector2i(wymiar_dluzszy,wymiar_krotszy);
    }
    if(zwrot == "prawo") {
        sprite = std::make_shared<sf::RectangleShape>(sf::Vector2f(wymiar_dluzszy,wymiar_krotszy));
        sprite->setPosition(startowy_tile->polozenie.x + Tile::tile_px_width/2,startowy_tile->polozenie.y + Tile::tile_px_width/2+1);
        pozycja = sf::Vector2f(startowy_tile->polozenie.x + Tile::tile_px_width/2,startowy_tile->polozenie.y + Tile::tile_px_width/2+1);
        size = sf::Vector2i(wymiar_dluzszy,wymiar_krotszy);
    }
    if(zwrot == "gora") {
        sprite = std::make_shared<sf::RectangleShape>(sf::Vector2f(wymiar_krotszy,wymiar_dluzszy));
        sprite->setPosition(startowy_tile->polozenie.x + Tile::tile_px_width/2 + 1,startowy_tile->polozenie.y + Tile::tile_px_width/2 - wymiar_dluzszy);
        pozycja = sf::Vector2f(startowy_tile->polozenie.x + Tile::tile_px_width/2 + 1,startowy_tile->polozenie.y + Tile::tile_px_width/2 - wymiar_dluzszy);
        size = sf::Vector2i(wymiar_krotszy,wymiar_dluzszy);
    }
    if(zwrot == "dol") {
        sprite = std::make_shared<sf::RectangleShape>(sf::Vector2f(wymiar_krotszy,wymiar_dluzszy));
        sprite->setPosition(startowy_tile->polozenie.x + Tile::tile_px_width/2 + 1,startowy_tile->polozenie.y + Tile::tile_px_width/2 );
        pozycja = sf::Vector2f(startowy_tile->polozenie.x + Tile::tile_px_width/2 + 1,startowy_tile->polozenie.y + Tile::tile_px_width/2 );
        size = sf::Vector2i(wymiar_krotszy,wymiar_dluzszy);
    }

    sprite->setFillColor(sf::Color(0,0,0));
    wyznacz_liste_potencjalnie_przebytych_tileow();

}
void pocisk::animuj(double elapsed) {
    if(zwrot == "lewo") {
        sprite->move(-speed * elapsed, 0);
    }
    if(zwrot == "prawo") {
        sprite->move(speed * elapsed, 0);
    }
    if(zwrot == "gora") {
        sprite->move(0, -speed * elapsed);
    }
    if(zwrot == "dol") {
        sprite->move(0, speed * elapsed);
    }

    update_pozycji();

    // TODO check for kill enemy (prawdopodobnie w enemy, ale moze i nie
    // TODO check for out of window -> destruktuje, (destruktuje nie tutaj tylko na zewnatrz prawdopodobnie
    // TODO byc moze beda potrzebne pola obecny tile pocisku itp, zeby poprawnie zabijac wrogow
    // TODO oczywiscie w hero razem obok blokady ruchu w turze, będą musiały być blokady strzałów
}
void pocisk::update_pozycji() {
    sf::FloatRect dane = sprite->getGlobalBounds();
    pozycja =  sf::Vector2f(dane.left,dane.top);
}
void pocisk::wyznacz_liste_potencjalnie_przebytych_tileow() {
    std::vector< std::shared_ptr <Tile> > re;

    sf::Vector2i polozenie_w_tablicy_tileow = {startowy_tile->polozenie_w_vector.x,startowy_tile->polozenie_w_vector.y};

    if(zwrot == "lewo") {
        for(size_t i = polozenie_w_tablicy_tileow.x; i > 0 ; i--) {
            re.emplace_back( Tile::tiles_tab[i-1][polozenie_w_tablicy_tileow.y]);
        }
    }
    if(zwrot == "prawo") {
        for(size_t i = polozenie_w_tablicy_tileow.x; i < Tile::ilosc_x-1 ; i++) {
            re.emplace_back( Tile::tiles_tab[i+1][polozenie_w_tablicy_tileow.y]);
        }
    }
    if(zwrot == "gora") {
        for(size_t i = polozenie_w_tablicy_tileow.y; i > 0 ; i--) {
            re.emplace_back( Tile::tiles_tab[polozenie_w_tablicy_tileow.x][i-1]);
        }
    }
    if(zwrot == "dol") {
        for(size_t i = polozenie_w_tablicy_tileow.y; i < Tile::ilosc_y-1 ; i++) {
            re.emplace_back( Tile::tiles_tab[polozenie_w_tablicy_tileow.x][i+1]);
        }
    }
    lista_potencjalnie_przebytych_tileow = re;
}
bool pocisk::czy_pocisk_przekroczyl_srodek_tile(std::shared_ptr<Tile> tile) {
    // przekroczyl zewnetrzna strona (czyli jakby zetknal sie ze srodkiem)
    if(zwrot == "lewo") {
        if(pozycja.x <= tile->polozenie.x + Tile::tile_px_width/2) return true;
    }
    if(zwrot == "prawo") {
        if(pozycja.x + size.x >= tile->polozenie.x + Tile::tile_px_width/2) return true;
    }
    if(zwrot == "gora") {
        if(pozycja.y <= tile->polozenie.y + Tile::tile_px_width/2) return true;
    }
    if(zwrot == "dol") {
        if(pozycja.y + size.y >= tile->polozenie.y + Tile::tile_px_width/2) return true;
    }
    return false;
}
void pocisk::wyznacz_obecny_tile() {
//    if(zwrot == "lewo") {
//        for(size_t i = 0 ; i < lista_potencjalnie_przebytych_tileow.size() ; i ++) {
//            if( czy_pocisk_przekroczyl_srodek_tile(lista_potencjalnie_przebytych_tileow[i]) ) {
//                obecny_tile = lista_potencjalnie_przebytych_tileow[i];
//                break;
//            }
//        }
//    }
//    if(zwrot == "prawo") {
//        for(size_t i = 0 ; i < lista_potencjalnie_przebytych_tileow.size() ; i ++) {
//            if( czy_pocisk_przekroczyl_srodek_tile(lista_potencjalnie_przebytych_tileow[i]) ) {
//                obecny_tile = lista_potencjalnie_przebytych_tileow[i];
//                break;
//            }
//        }
//    }
//    if(zwrot == "gora") {
//        for(size_t i = 0 ; i < lista_potencjalnie_przebytych_tileow.size() ; i ++) {
//            if( czy_pocisk_przekroczyl_srodek_tile(lista_potencjalnie_przebytych_tileow[i]) ) {
//                obecny_tile = lista_potencjalnie_przebytych_tileow[i];
//                break;
//            }
//        }
//    }
//    if(zwrot == "dol") {
//        for(size_t i = 0 ; i < lista_potencjalnie_przebytych_tileow.size() ; i ++) {
//            if( czy_pocisk_przekroczyl_srodek_tile(lista_potencjalnie_przebytych_tileow[i]) ) {
//                obecny_tile = lista_potencjalnie_przebytych_tileow[i];
//                break;
//            }
//        }
//    }

    for(size_t i = lista_potencjalnie_przebytych_tileow.size()-1 ; i > 0  ; i--) {
        //debug("i: " , (int) i);
        if( czy_pocisk_przekroczyl_srodek_tile(lista_potencjalnie_przebytych_tileow[i]) ) {
            obecny_tile = lista_potencjalnie_przebytych_tileow[i];
            //debug("Obecny tile: " , "x: " + std::to_string(obecny_tile->polozenie_w_vector.x) + "\ty: " + std::to_string(obecny_tile->polozenie_w_vector.y));
            break;
        }
    }

}
bool pocisk::czy_przekroczyl_ostatni_tile() {
    if( czy_pocisk_przekroczyl_srodek_tile(lista_potencjalnie_przebytych_tileow[lista_potencjalnie_przebytych_tileow.size()-1])) return true;
    else return false;
    //TODO upewnic sie że będzie kolejność:
    // 1 wyznacz obecny tile
    // 2 cale sprawdzanie enemy i pociskow i kasowanie odpowiednio
    // 3 kasowanie pociskow majacych wyleciec z mapy
}
void pocisk::zarzadzaj_pociskami() {
    std::vector<std::vector<std::shared_ptr<pocisk>>::iterator> do_skasowania;
    //for(std::shared_ptr<pocisk> x : pocisk::pociski) {
    for(std::vector<std::shared_ptr<pocisk>>::iterator it = pociski.begin(); it != pociski.end() ; it++) {
        //*it.wyznacz_obecny_tile();
        // punkt 1
        it->operator*().wyznacz_obecny_tile();
//        if(it->operator*().zwrot == "lewo") {
//            // tablica wszystkich enemy, sprawdza wszystkie enemy czy maja wspolne tile z pocisk->obecny tile, jak tak to oba kasuje
//            // miejsce na punkt 2
//            if(it->operator*().czy_przekroczyl_ostatni_tile() ) {
//                //pociski.erase(it);
//                do_skasowania.emplace_back(it);
//                continue;
//            }
//        }
//        if(it->operator*().zwrot == "prawo") {
//            if(it->operator*().czy_przekroczyl_ostatni_tile() ) {
//                //pociski.erase(it);
//                do_skasowania.emplace_back(it);
//                continue;
//            }
//        }
//        if(it->operator*().zwrot == "gora") {
//            if(it->operator*().czy_przekroczyl_ostatni_tile() ) {
//                //pociski.erase(it);
//                do_skasowania.emplace_back(it);
//                continue;
//            }
//        }
//        if(it->operator*().zwrot == "dol") {
//            if(it->operator*().czy_przekroczyl_ostatni_tile() ) {
//                //pociski.erase(it);
//                do_skasowania.emplace_back(it);
//                continue;
//            }
//        }

        // TODO punkt 2 czyli polecenie po wszystkich enemy i porownanie ktory jest na tile na ktorym aktualnie jest ten pocisk (albo na odwrot) i wtedy kasacja obu
        bool czy_trafiono = enemy::zniszcz_enemy_na_tile_od_pocisk(it->operator*().obecny_tile);
        if(czy_trafiono) {
            do_skasowania.emplace_back(it);
        }
        // punkt 3
        if(it->operator*().czy_przekroczyl_ostatni_tile() ) {
            do_skasowania.emplace_back(it);
            continue;
        }
    }
    for(auto& x : do_skasowania) {
        //debug("kasuje pocisk");
        pociski.erase(x);
    }
}
