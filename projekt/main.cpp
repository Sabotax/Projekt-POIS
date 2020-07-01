#include "Header.h"
// OMEGATODO pathfinding i skakanie do bohatera co ture i atakowanie bohatera jesli jest obok
// DONE wymaganie żeby w okienku się ruszyć
// DONE lmit strzalu raz na ture (odrobine inna tura niz ta dotyczaca ruchu)
// MOZE TODO zielone pola oznaczajace mozliwe nawiasy, aczkolwiek niezbyt potrzebne
// TODO odrkyc unexptected blad ze na poczatku gry jak sie zrobi np dwa-trzy razy w prawo to nastepnie w lewo tez robi w prawo
// TODO zrobić zeby character mialo pole planowany tile, i zeby dzialaj/move robotów raczej sprawdzało je niż obecny tile, a może oba
// TODO sprawdzic czy sprawdzanie zalezy od tile::zajete, czy sprawdza każde character::polozenie_tile == planowany_tile
// TODO jak strzela do tile obok to nie zalicza i nie zabija robota na tile obok
int main()
{
    void start_dumb_cpp_static_variables();
    Tile::initialize_statics();
    Character::initialize_statics();
    Timer::Initiate_statics();
    // create the window
    //sf::RenderWindow window(sf::VideoMode(800, 600), "My window");
    //std::unique_ptr<sf::CircleShape> circle = std::make_unique<sf::CircleShape>(100.0);
    std::shared_ptr< sf::RenderWindow > window = std::make_shared<sf::RenderWindow>(sf::VideoMode(Tile::szerokosc_okna, Tile::wysokosc_okna), "My window");
    window->setFramerateLimit(60);
    Tile::window = window;

    std::map<std::string, sf::Texture> tekstury = LoadTextures();
    std::map<std::string, sf::SoundBuffer> sound_buffers = LoadSounds();

    //std::cout << window->getSize().x << " \t" << window->getSize().y << std::endl;
    Music::InitiateMusics();
    Tile::ustaw_statyczne_tex(tekstury["blue"],tekstury["red"]);
    serca::ustaw_statyczne_tex( tekstury["serce_puste"],tekstury["serce_pelne"]);
    enemy::ustaw_statyczne_tex( tekstury["robot"]);

    // na dole mur, który będzie rozdzielał drobnie tilesy
    std::map<std::string, std::shared_ptr<sf::Sprite>> sprites; // kolejnosc w vectorze bedzie oznaczala kolejnosc rysowania
    sprites.emplace("wall",InitiateBackground(tekstury["wall"],window->getSize()));
    //sprites.emplace("banner",InitiateBanner(tekstury["banner"],window->getSize()));
    //sprites.emplace("sciany", InitiateWalls(tekstury["brown"]));
    //sprites.emplace("hero1",Hero::InitiateHero(tekstury["hero1"],window->getSize()));
    //Tile::tiles_tab = Tile::GenerateTilesVector(tekstury["grass"],window->getSize());
    Tile::GenerateTilesVector(tekstury["red"], tekstury["blue"],window->getSize());
    std::shared_ptr< Hero > Hero1 = std::make_shared< Hero >(tekstury["hero1"], Tile::tiles_tab[Tile::ilosc_x/2][Tile::ilosc_y/2] );
    Hero::hero1 = Hero1;
    //std::cout << Hero1->polozenie_tile->polozenie.x << "\t" << Hero1->polozenie_tile->polozenie.y << std::endl;
    //std::vector< std::vector < std::unique_ptr<sf::Sprite> > > tiles = GenerateTilesVector(tekstury["grass"],window->getSize());
    //std::shared_ptr< enemy> enemy1 = std::make_shared<enemy>(tekstury["robot"], Tile::tiles_tab[10][1] );
    enemy::spawn_enemies();
    std::vector< std::shared_ptr < sf::Sprite> > sciany = InitiateWalls(tekstury["brown"]);
    std::shared_ptr<sf::Sprite> banner = InitiateBanner(tekstury["banner"],window->getSize());
    std::vector< std::shared_ptr < sf::RectangleShape> > baner_odliczanie_trasa = baner_odliczanie::create_position_rectangles();
    serca::utworz_serca();
    //sf::Sprite hero_test;
    //hero_test.setTexture(tekstury["hero1"]);

    //tiles[5][5]->setTexture(tekstury["red"]);

    //double bit = 5.0; // co 5 sekund tura
    //double zliczanie = 0;
    double elapsed_S = 0;
    //bool sw = true; // switch

    //sf::Music papers_test;
    //papers_test.openFromFile("../audio/papers_please/papers_please.ogg");
    //papers_test.play();

    sf::Clock clock;

    //temp tutaj
    //Character::czas_animacji = 1;
    Music::obecna_muzyka = Music::muzyki_tab[0];
    double chyba_sie_juz_zaladowalo_wszystko = 0.5;
    bool i_raz_jeno = true;
    //Music::muzyki_tab[0]->soundtrack->play();

    //std::cout << Hero1->test << std::endl;
    // run the program as long as the window is open
    baner_odliczanie::ob = std::make_shared<baner_odliczanie>(Music::obecna_muzyka->okienka_czasowe[Music::obecna_muzyka->obecny_index],Music::obecna_muzyka->okienka_czasowe[Music::obecna_muzyka->obecny_index+1]);
    while (window->isOpen()) {
        if(Timer::zliczanie > chyba_sie_juz_zaladowalo_wszystko && i_raz_jeno) {
            Music::obecna_muzyka->soundtrack->play();
            i_raz_jeno = false;
        }
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window->pollEvent(event)) {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed) {
                window->close();
            }

            if (event.type == sf::Event::MouseButtonPressed) {

                // lpm
                if(event.mouseButton.button == sf::Mouse::Left) {
                    sf::Vector2i mouse_pos = sf::Mouse::getPosition(*window);
                    //std::cout << "Mouse clicked: " << mouse_pos.x << ", " << mouse_pos.y << std::endl;

                    for(auto& x : Tile::tiles_tab) for(auto& y: x) {
                        if( y->czy_koordy_wchodza_w_tile(mouse_pos) ) {
                            std::cout << "X: " << mouse_pos.x << "\tY: " << mouse_pos.y << "\t" << (y->czy_zajete ? "zajete" : "wolne") << std::endl;
                        }
                    }

                }


            }

//            if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
//                Hero1->Character::start_move("up");
//            }
//            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
//                //Hero1->sprite->move(0,1);
//                Hero1->Character::start_move("down");
//            }
//            if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
//                //Hero1->sprite->move(-1,0);
//                Hero1->Character::start_move("left");
//            }
//            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
//                Hero1->Character::start_move("right");
//            }

            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::H) {
                    serca::strac_zycie();
                }
                if (event.key.code == sf::Keyboard::Left) {
                    Hero1->strzel("lewo");
                }
                if (event.key.code == sf::Keyboard::Right) {
                    Hero1->strzel("prawo");
                }
                if (event.key.code == sf::Keyboard::Up) {
                    Hero1->strzel("gora");
                }
                if (event.key.code == sf::Keyboard::Down) {
                    Hero1->strzel("dol");
                }

                if(event.key.code == sf::Keyboard::W) {
                    Hero1->Character::start_move("up");
                }
                else if(event.key.code == sf::Keyboard::S) {
                    Hero1->Character::start_move("down");
                }
                else if(event.key.code == sf::Keyboard::A) {
                    Hero1->Character::start_move("left");
                }
                else if(event.key.code == sf::Keyboard::D) {
                    Hero1->Character::start_move("right");
                }
            }

        }

        //control panel


        // clear the window with black color
        window->clear(sf::Color::Black);

        // draw everything here...

        // timer test

        sf::Time elapsed = clock.getElapsedTime();
        elapsed_S = elapsed.asSeconds();
        //zliczanie += elapsed_S;
        //debug("zliczanie: ", zliczanie);

        Timer::zarzadzaj_czasem(elapsed_S);
        //std::cout << bit-zliczanie << std::endl;


//        if( bit-zliczanie <= 0.5 && bit-zliczanie >= -0.5 ) { // nawiasy bitu
//            if(sw) gey.setTexture(texture_guy);
//            else gey.setTexture(texture_gey);
//            sw = !sw;
//            zliczanie = 0;
//        }

        //reverse dla kolejności odpowiedniej
//        for (std::reverse_iterator<std::map<std::string,sf::Sprite>::iterator> it=sprites.rbegin(); it!=sprites.rend(); it++) {
//            window->draw(it->second);
//        }
//        for(auto& x : tiles) for(auto& y : x) window->draw(*y);


        Hero1->move();
        for(auto& x: enemy::tab_enemies) x->move();
        baner_odliczanie::ob->animate(elapsed_S);
        for(auto& x: pocisk::pociski) x->animuj(elapsed_S);
        pocisk::zarzadzaj_pociskami();

        // dir dać do startmove i moze pole w charcter opisujace dir

        window->draw(*sprites["wall"]);
        window->draw(*banner);
        for(auto& x : sciany ) window->draw(*x);
        for(auto& x : Tile::tiles_tab) for(auto& y : x) window->draw(*y->sprite);
        window->draw(*Hero1->sprite);
        for(auto& x: enemy::tab_enemies) window->draw(*x->sprite);
        //window->draw(hero_test);
//        if(trig_once_testowo) {
//            Music::muzyki_tab[0]->soundtrack->play();
//            trig_once_testowo = false;
//        }

        for(auto& x : baner_odliczanie_trasa) window->draw(*x);
        window->draw(*(baner_odliczanie::ob->tyczka));

        for(auto& x : serca::serca_tab) window->draw(*x->sprite);

        for(auto& x : pocisk::pociski)  window->draw(*x->sprite);

//        for(auto& x: Tile::tiles_tab) {
//            for(auto& y : x) {
//                if(y->czy_zajete) std::cout<< "X: " << y->polozenie_w_vector.x << "\tY: " << y->polozenie_w_vector.y << " jest zajete" << std::endl;
//            }
//        }
        clock.restart();
        // end the current frame
        window->display();
    }

    return 0;

}
