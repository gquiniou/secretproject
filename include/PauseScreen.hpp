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
    explicit PauseScreen(ScreenManager *sm) : Screen(sm) {
        f.loadFromFile("assets/Consequences.ttf");

        mytext.setString("Paused");
        mytext.setFont(f);
        mytext.setFillColor(sf::Color::Red);
        mytext.setCharacterSize(65);
        mytext.setStyle(sf::Text::Bold);
        sf::FloatRect bounds = mytext.getGlobalBounds();
        mytext.setOrigin(bounds.width / 2, bounds.height / 2);
        mytext.setPosition(640 / 2.0, 480 / 2.0);


    };

    void handleEvent(sf::Event &event) override;

    void update(sf::Time dt) override;

    void render(sf::RenderWindow *window) override;

private:
    sf::Text mytext;
    sf::Font f;
    int i = 0;

};


#endif //SECRETPROJECT_PAUSESCREEN_HPP
