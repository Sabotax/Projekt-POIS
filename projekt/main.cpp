#include "Header.h"
#include "Tile.h"
#include "Character.h"
#include "Hero.h"

int main()
{
    void start_dumb_cpp_static_variables();
    // create the window
    //sf::RenderWindow window(sf::VideoMode(800, 600), "My window");
    //std::unique_ptr<sf::CircleShape> circle = std::make_unique<sf::CircleShape>(100.0);
    std::unique_ptr< sf::RenderWindow > window = std::make_unique<sf::RenderWindow>(sf::VideoMode(800, 600), "My window");
    window->setFramerateLimit(60);

    std::map<std::string, sf::Texture> tekstury = LoadTextures();

    std::cout << window->getSize().x << " \t" << window->getSize().y << std::endl;


    // na dole mur, który będzie rozdzielał drobnie tilesy
    std::map<std::string, std::shared_ptr<sf::Sprite>> sprites; // kolejnosc w vectorze bedzie oznaczala kolejnosc rysowania
    sprites.emplace("wall",InitiateMapWall(tekstury["wall"],window->getSize()));
    //sprites.emplace("hero1",Hero::InitiateHero(tekstury["hero1"],window->getSize()));
    //Tile::tiles_tab = Tile::GenerateTilesVector(tekstury["grass"],window->getSize());
    Tile::GenerateTilesVector(tekstury["grass"],window->getSize());
    std::shared_ptr< Hero > Hero1 = std::make_shared< Hero >(tekstury["hero1"], Tile::tiles_tab[6][5] );
    std::cout << Hero1->polozenie_tile->polozenie.x << "\t" << Hero1->polozenie_tile->polozenie.y << std::endl;
    //std::vector< std::vector < std::unique_ptr<sf::Sprite> > > tiles = GenerateTilesVector(tekstury["grass"],window->getSize());

    //sf::Sprite hero_test;
    //hero_test.setTexture(tekstury["hero1"]);

    //tiles[5][5]->setTexture(tekstury["red"]);

    double bit = 5.0; // co 5 sekund tura
    double zliczanie = 0;
    double elapsed_S = 0;
    bool sw = true; // switch

    sf::Clock clock;

    //temp tutaj
    Character::czas_animacji = 1;

    //std::cout << Hero1->test << std::endl;

    // run the program as long as the window is open
    while (window->isOpen()) {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window->pollEvent(event)) {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window->close();
        }

        //control panel
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            Hero1->sprite->move(0,-1);
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            //Hero1->sprite->move(0,1);
            Hero1->sprite->move(0,1);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            //Hero1->sprite->move(-1,0);
            Hero1->start_move();
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            Hero1->sprite->move(1,0);
        }

        // clear the window with black color
        window->clear(sf::Color::Black);

        // draw everything here...

        // timer test

        sf::Time elapsed = clock.getElapsedTime();
        elapsed_S = elapsed.asSeconds();
        zliczanie += elapsed_S;
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

        Hero1->move("left",elapsed_S);
        // dir dać do startmove i moze pole w charcter opisujace dir

        window->draw(*sprites["wall"]);
        for(auto& x : Tile::tiles_tab) for(auto& y : x) window->draw(*y->sprite);
        window->draw(*Hero1->sprite);
        //window->draw(hero_test);

        clock.restart();
        // end the current frame
        window->display();
    }

    return 0;

}
