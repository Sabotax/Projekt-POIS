#include "Music.h"

Music::Music(std::shared_ptr<sf::Sound> soundtrack)
{
    soundtrack = std::make_shared< sf::Sound >();
    this->soundtrack = soundtrack;
}
