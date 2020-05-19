#include "Header.h"

std::vector<std::unique_ptr<sf::Drawable>> create_shapes()
{
    std::vector<std::unique_ptr<sf::Drawable>> shapes;

    std::unique_ptr<sf::CircleShape> circle = std::make_unique<sf::CircleShape>(100.0);
    circle->setPosition(100.0, 300.0);
    circle->setFillColor(sf::Color(100, 250, 50));
    shapes.emplace_back(std::move(circle));

    std::unique_ptr<sf::RectangleShape> rectangle = std::make_unique<sf::RectangleShape>(sf::Vector2f(120.0, 60.0));
    rectangle->setPosition(500.0, 400.0);
    rectangle->setFillColor(sf::Color(100, 50, 250));
    shapes.emplace_back(std::move(rectangle));

    std::unique_ptr<sf::ConvexShape> triangle = std::make_unique<sf::ConvexShape>();
    triangle->setPointCount(3);
    triangle->setPoint(0, sf::Vector2f(0.0, 0.0));
    triangle->setPoint(1, sf::Vector2f(0.0, 100.0));
    triangle->setPoint(2, sf::Vector2f(140.0, 40.0));
    triangle->setOutlineColor(sf::Color::Red);
    triangle->setOutlineThickness(5);
    triangle->setPosition(600.0, 100.0);
    shapes.emplace_back(std::move(triangle));

    return shapes;
}


int main()
{

    // create the window
    //sf::RenderWindow window(sf::VideoMode(800, 600), "My window");
    //std::unique_ptr<sf::CircleShape> circle = std::make_unique<sf::CircleShape>(100.0);
    std::unique_ptr< sf::RenderWindow > window = std::make_unique<sf::RenderWindow>(sf::VideoMode(800, 600), "My window");
    window->setFramerateLimit(60);

    std::vector<std::unique_ptr <sf::Drawable> > shapes = create_shapes();

    /*
    sf::Texture texture_grass;
    if (!texture_grass.loadFromFile("../textures/grass.png")) {
        std::cerr << "Could not load texture" << std::endl;
        return 1;
    }
    texture_grass.setRepeated(true);
    */

    //Boot::Boot();
    //Boot::Boot(std::move(window));

    std::vector< sf::Texture > tekstury = LoadTextures();

    sf::Sprite grass;
    grass.setTexture(tekstury[0]);
    //grass.setTexture(Boot::getTekstury()["grass"]);
    double skala = 0.3;
    grass.setScale(skala, skala);
    grass.setTextureRect(sf::IntRect(0, 0, window->getSize().x*1/skala, window->getSize().y*1/skala));
    grass.setPosition(0,0);




    sf::Texture texture_gey;
    if(!texture_gey.loadFromFile("../textures/proba3d-2-filled.png")) { return 1; }

    sf::Texture texture_guy;
    if(!texture_guy.loadFromFile("../textures/proba3d-1.png")) { return 1; }

    sf::Sprite gey;
    gey.setTexture(texture_gey);
    //guy.setTextureRect(sf::IntRect(10, 20, 20, 15)); //left, top, width, height

    gey.setPosition(100,100);

    sf::Texture texture_wall;
    if(!texture_wall.loadFromFile("../textures/wall.png")) { return 1; }
    texture_wall.setRepeated(true);

    sf::Sprite wall;
    wall.setTexture(texture_wall);
    wall.setScale(0.3, 0.3);
    wall.setTextureRect(sf::IntRect(0, 0, 500, 500));
    wall.setPosition(0,0);

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
            gey.move(0,-1);
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            gey.move(0,1);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            gey.move(-1,0);
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            gey.move(1,0);
        }

        // clear the window with black color
        window->clear(sf::Color::Black);

        // draw everything here...
        for(const auto &x: shapes) window->draw(*x);



        // timer test

        sf::Time elapsed = clock.getElapsedTime();
        elapsed_S = elapsed.asSeconds();
        zliczanie += elapsed_S;
        //std::cout << bit-zliczanie << std::endl;

        if( bit-zliczanie <= 0.5 && bit-zliczanie >= -0.5 ) { // nawiasy bitu
            if(sw) gey.setTexture(texture_guy);
            else gey.setTexture(texture_gey);
            sw = !sw;
            zliczanie = 0;
        }

        window->draw(grass);
        window->draw(gey);


        clock.restart();
        // end the current frame
        window->display();
    }

    return 0;

}
