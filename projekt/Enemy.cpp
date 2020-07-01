#include "Header.h"

std::vector<std::shared_ptr<enemy> > enemy::tab_enemies;
sf::Texture enemy::tex;

enemy::enemy(const sf::Texture& texture, std::shared_ptr<Tile> tile) {
    sprite = std::make_shared<sf::Sprite>();
    polozenie_tile = tile;
    sprite->setTexture(texture);
    sprite->setPosition(polozenie_tile->polozenie.x, polozenie_tile->polozenie.y);
    czy_w_trakcie_animacji = false;
    polozenie_tile->czy_zajete=true;
}
bool enemy::zniszcz_enemy_na_tile_od_pocisk(std::shared_ptr<Tile> tile_pocisku) {
    std::vector<std::vector<std::shared_ptr<enemy>>::iterator> do_skasowania;
    bool re = false;
    for(std::vector<std::shared_ptr<enemy>>::iterator it = tab_enemies.begin(); it != tab_enemies.end() ; it++) {
        if( it->operator*().polozenie_tile == tile_pocisku) {
            do_skasowania.emplace_back(it);
            re = true;
        }
        // czasami robot moze zmienic tile akurat jak pocisk bedzie miedzy tile'ami, przez co robot jakby robi unik
        // nazwijmy to "feature" a nie bugiem
    }
    for(auto& x : do_skasowania) {
        //debug("kasuje wroga");
        x->operator*().polozenie_tile->czy_zajete=false;
        if(x->operator*().planowany_tile != nullptr) {
            if(x->operator*().planowany_tile != Hero::hero1->polozenie_tile ) {
                x->operator*().planowany_tile->czy_zajete=false;
                x->operator*().polozenie_tile->czy_zajete=false;
            }
        }

        tab_enemies.erase(x);
    }
    return re;
}
sf::Vector2i enemy::pozycja_wzgledem_bohatera(std::shared_ptr<Hero> hero) {
    sf::Vector2i re;
    // { x , y}: -1 dla lewo/gora, 0 dla nic, 1 dla prawo/dol -> w sensie gdzie ma iść
    if(polozenie_tile->polozenie_w_vector.x < hero->polozenie_tile->polozenie_w_vector.x) {
        re.x = 1;
    }
    else if(polozenie_tile->polozenie_w_vector.x > hero->polozenie_tile->polozenie_w_vector.x) {
        re.x = -1;
    }
    else {
        re.x = 0;
    }

    if(polozenie_tile->polozenie_w_vector.y < hero->polozenie_tile->polozenie_w_vector.y) {
        re.y = 1;
    }
    else if(polozenie_tile->polozenie_w_vector.y > hero->polozenie_tile->polozenie_w_vector.y) {
        re.y = -1;
    }
    else {
        re.y = 0;
    }
    return re;
}
void enemy::dzialaj() {
    // czy jest zajete, jesli tak to czy zajete przez bohatera, jesli tak to dmg, jesli nie to move
    // raczej nie da rady "chciec isc poza ramy, bo bohater poza ramy nie wyjdzie
    //debug("przebieg");
    sf::Vector2i gdzie_chce_isc_liczby = pozycja_wzgledem_bohatera(Hero::hero1);

    // zle bo nie mozna na skos
    //std::shared_ptr<Tile> gdzie_chce_isc_tile = Tile::tiles_tab[polozenie_tile->polozenie_w_vector.x+gdzie_chce_isc_liczby.x][polozenie_tile->polozenie_w_vector.y+gdzie_chce_isc_liczby.y];
    std::shared_ptr<Tile> gdzie_chce_isc_tile;
    bool opcjaX = false;
    bool opcjaY = false;

    // X
//    if(randomInt(0,1) == 0) {
//        if(gdzie_chce_isc_liczby.x != 0) {
//            gdzie_chce_isc_tile = Tile::tiles_tab[polozenie_tile->polozenie_w_vector.x][polozenie_tile->polozenie_w_vector.y+gdzie_chce_isc_liczby.y];
//            opcjaX = true;
//        }
//    }
//    else {
//        if(gdzie_chce_isc_liczby.y != 0) {
//            gdzie_chce_isc_tile = Tile::tiles_tab[polozenie_tile->polozenie_w_vector.x+gdzie_chce_isc_liczby.x][polozenie_tile->polozenie_w_vector.y];
//            opcjaY = true;
//        }
//    }

    //std::cout << gdzie_chce_isc_liczby.x << "\t" << gdzie_chce_isc_liczby.y << std::endl;

    if(gdzie_chce_isc_liczby.y != 0 && gdzie_chce_isc_liczby.x != 0) {
        if(randomInt(0,1) == 0) {
            //debug("chce isc w ", gdzie_chce_isc_liczby.x == -1 ? "lewo1" : "prawo1");
            gdzie_chce_isc_tile = Tile::tiles_tab[polozenie_tile->polozenie_w_vector.x][polozenie_tile->polozenie_w_vector.y+gdzie_chce_isc_liczby.y];
            opcjaX = true;
        }
        else {
            //debug("chce isc w ", gdzie_chce_isc_liczby.y == -1 ? "gora1" : "dol1");
            gdzie_chce_isc_tile = Tile::tiles_tab[polozenie_tile->polozenie_w_vector.x+gdzie_chce_isc_liczby.x][polozenie_tile->polozenie_w_vector.y];
            opcjaY = true;
        }
    }
    else if(gdzie_chce_isc_liczby.y != 0) {
        //debug("chce isc w ", gdzie_chce_isc_liczby.y == -1 ? "gora2" : "dol2");
        gdzie_chce_isc_tile = Tile::tiles_tab[polozenie_tile->polozenie_w_vector.x][polozenie_tile->polozenie_w_vector.y+gdzie_chce_isc_liczby.y];
        opcjaY = true;
    }
    else if(gdzie_chce_isc_liczby.x != 0) {
        //debug("chce isc w ", gdzie_chce_isc_liczby.x == -1 ? "lewo2" : "prawo2");
        gdzie_chce_isc_tile = Tile::tiles_tab[polozenie_tile->polozenie_w_vector.x+gdzie_chce_isc_liczby.x][polozenie_tile->polozenie_w_vector.y];
        opcjaX = true;
    }
    else {
        //stoi na bohaterze
        //std::cout << "nie powinienem tu dotrzec nigdy " << gdzie_chce_isc_liczby.x << "\t" << gdzie_chce_isc_liczby.y << std::endl;
        //debug("bohater we mnie wskoczyl");
        std::cout<<"Miałeś zbyt bliskie spotkanie z robotem = instant death\nPrzegrales" << std::endl;
        Tile::window->close();
        // powinno się skasowac robota bo pewnie i tak będzie crash
    }

    //debug("czy zajente 1",gdzie_chce_isc_tile->czy_zajete);
    if(gdzie_chce_isc_tile->czy_zajete && opcjaY) {
        if(gdzie_chce_isc_liczby.x != 0) {
            gdzie_chce_isc_tile = Tile::tiles_tab[polozenie_tile->polozenie_w_vector.x+gdzie_chce_isc_liczby.x][polozenie_tile->polozenie_w_vector.y];
            opcjaX = true;
            opcjaY = false;
            //debug("won zajente Y");
        }
    }
    else if(gdzie_chce_isc_tile->czy_zajete && opcjaX) {
        if(gdzie_chce_isc_liczby.y != 0) {
            gdzie_chce_isc_tile = Tile::tiles_tab[polozenie_tile->polozenie_w_vector.x][polozenie_tile->polozenie_w_vector.y+gdzie_chce_isc_liczby.y];
            opcjaY = true;
            opcjaX = false;
            //debug("won zajente X");
        }
    }
    // oba .x i .y nigdy nie mogą być 0, więc zawsze gdzie chce isc zajdzie

    if(!gdzie_chce_isc_tile->czy_zajete && opcjaY && opcjaX) {
        // nie idz nigdzie
        //debug("nigdzie nie ide");
        // nie powinno musiec ustawiac na true bo juz jest
        //polozenie_tile->czy_zajete = true;
    }
    else if(gdzie_chce_isc_tile == Hero::hero1->polozenie_tile) {
        //debug("robot bije bohatera");
    }
    else if(!gdzie_chce_isc_tile->czy_zajete){
//        if( Tile::tiles_tab[polozenie_tile->polozenie_w_vector.x+gdzie_chce_isc_liczby.x][polozenie_tile->polozenie_w_vector.y+gdzie_chce_isc_liczby.y]->czy_zajete ) {
//            //debug("wracam se, czyli tu cos sie rozpierdala bo powinno byc zawarte w warunku u gory");
//            return;
//        }

        //debug("Opcja X:" , opcjaX );
        //debug("Opcja Y:" , opcjaY );
        //debug("czy zajente 1",gdzie_chce_isc_tile->czy_zajete);
        //std::cout << gdzie_chce_isc_tile->polozenie_w_vector.x << "\t" << gdzie_chce_isc_tile->polozenie_w_vector.y << std::endl;
        gdzie_chce_isc_tile->czy_zajete=true;
        polozenie_tile->czy_zajete=false;
        planowany_tile = gdzie_chce_isc_tile;
        if(opcjaX) {
            if(gdzie_chce_isc_liczby.x == -1) {
                //debug("idem w left");
                start_move("left");
            }
            if(gdzie_chce_isc_liczby.x == 1) {
                //debug("idem w right");
                start_move("right");
            }
        }
        if(opcjaY) {
            if(gdzie_chce_isc_liczby.y == -1) {
                //debug("idem w up");
                start_move("up");
            }
            if(gdzie_chce_isc_liczby.y == 1) {
                //debug("idem w down");
                start_move("down");
            }
        }
    }
    else {
        //polozenie_tile->czy_zajete = true;
        //debug("co do ch");
        //std::cout<< "X: " << gdzie_chce_isc_tile->polozenie_w_vector.x << "\tY: " << gdzie_chce_isc_tile->polozenie_w_vector.y << " chce isc" << std::endl;
    }
}
void enemy::spawn_enemies() {
    //lewo
    tab_enemies.emplace_back( std::make_shared<enemy>(tex,Tile::tiles_tab[0][4]));
    tab_enemies.emplace_back( std::make_shared<enemy>(tex,Tile::tiles_tab[0][5]));
    tab_enemies.emplace_back( std::make_shared<enemy>(tex,Tile::tiles_tab[0][6]));
    //gora
    tab_enemies.emplace_back( std::make_shared<enemy>(tex,Tile::tiles_tab[10][0]));
    tab_enemies.emplace_back( std::make_shared<enemy>(tex,Tile::tiles_tab[11][0]));
    tab_enemies.emplace_back( std::make_shared<enemy>(tex,Tile::tiles_tab[12][0]));
    //prawo
    tab_enemies.emplace_back( std::make_shared<enemy>(tex,Tile::tiles_tab[Tile::ilosc_x-1][4]));
    tab_enemies.emplace_back( std::make_shared<enemy>(tex,Tile::tiles_tab[Tile::ilosc_x-1][5]));
    tab_enemies.emplace_back( std::make_shared<enemy>(tex,Tile::tiles_tab[Tile::ilosc_x-1][6]));
    //dol
    tab_enemies.emplace_back( std::make_shared<enemy>(tex,Tile::tiles_tab[10][Tile::ilosc_y-1]));
    tab_enemies.emplace_back( std::make_shared<enemy>(tex,Tile::tiles_tab[11][Tile::ilosc_y-1]));
    tab_enemies.emplace_back( std::make_shared<enemy>(tex,Tile::tiles_tab[12][Tile::ilosc_y-1]));
}
void enemy::ustaw_statyczne_tex( sf::Texture tex) {
    enemy::tex = tex;
}
