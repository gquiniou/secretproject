//
// Created by greg on 28/01/2019.
//

#ifndef SECRETPROJECT_GAMEWORLD_HPP
#define SECRETPROJECT_GAMEWORLD_HPP

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Window/Event.hpp>

class GameWorld {
    enum gameState {  WAITING, PLAYING, GAMEOVER};

public:
    void initLevel();
    void handleEvent(sf::Event &event);
    void update(sf::Time dt);
    void render(sf::RenderWindow *window);

private:
    gameState mGS;
};



#endif //SECRETPROJECT_GAMEWORLD_HPP
