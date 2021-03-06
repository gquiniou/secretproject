//
// Created by greg on 13/01/2019.
//

#ifndef SECRETPROJECT_PAUSESCREEN_HPP
#define SECRETPROJECT_PAUSESCREEN_HPP

#include <ScreenManager.hpp>
#include "Screen.hpp"
#include <SFML/Graphics/Text.hpp>

class PauseScreen : public Screen {

public:
    explicit PauseScreen(ScreenManager *);

    void handleEvent(sf::Event &event) override;

    void update(sf::Time dt) override;

    void render(sf::RenderWindow *window) override;

private:
    sf::Text pausedText;
    sf::Text messageText;
    sf::Font f;
    int i = 0;

};


#endif //SECRETPROJECT_PAUSESCREEN_HPP
