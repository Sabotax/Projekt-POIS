#include "Header.h"

int main()
{

    // create the window
    //sf::RenderWindow window(sf::VideoMode(800, 600), "My window");
    //std::unique_ptr<sf::CircleShape> circle = std::make_unique<sf::CircleShape>(100.0);
    std::unique_ptr< sf::RenderWindow > window = std::make_unique<sf::RenderWindow>(sf::VideoMode(800, 600), "My window");
    window->setFramerateLimit(60);

    std::map<std::string, sf::Texture> tekstury = LoadTextures();

    std::cout << window->getSize().x << " \t" << window->getSize().y << std::endl;


    // na dole mur, który będzie rozdzielał drobnie tilesy
    std::map<std::string, sf::Sprite> sprites; // kolejnosc w vectorze bedzie oznaczala kolejnosc rysowania
    sprites.emplace("wall",InitiateMapWall(tekstury["wall"],window->getSize()));
    sprites.emplace("hero1",InitiateHero(tekstury["hero1"],window->getSize()));

    double bit = 5.0; // co 5 sekund tura
    double zliczanie = 0;
    double elapsed_S = 0;
    bool sw = true; // switch

    sf::Clock clock;

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
            sprites["hero1"].move(0,-1);
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            sprites["hero1"].move(0,1);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            sprites["hero1"].move(-1,0);
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            sprites["hero1"].move(1,0);
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
        for (std::reverse_iterator<std::map<std::string,sf::Sprite>::iterator> it=sprites.rbegin(); it!=sprites.rend(); it++) {
            window->draw(it->second);
        }

        clock.restart();
        // end the current frame
        window->display();
    }

    return 0;

}
