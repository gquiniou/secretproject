//
// Created by greg on 06/01/2019.
//

#ifndef SECRETPROJECT_GAMESCREEN_HPP
#define SECRETPROJECT_GAMESCREEN_HPP

#include "Screen.hpp"

class GameScreen : public Screen {
public:
    GameScreen();

    void handleEvent(sf::Event &event) override;

    void update(sf::Time dt) override;

    void render(sf::RenderWindow *window) override;
};


#endif //SECRETPROJECT_GAMESCREEN_HPP
