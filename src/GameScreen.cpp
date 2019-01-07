//
// Created by greg on 06/01/2019.
//

#include "GameScreen.hpp"
#include <iostream>

GameScreen::GameScreen() = default;

void GameScreen::handleEvent(sf::Event &event) {
    if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape)) {
        std::cout << "esc pressed !!" << std::endl;
    }
}

void GameScreen::update(sf::Time dt) {
    //  Screen::update(dt);
}

void GameScreen::render(sf::RenderWindow *window) {
    //  Screen::render(window);
}
