//
// Created by greg on 13/01/2019.
//

#include <PauseScreen.hpp>
#include <cmath>

void PauseScreen::handleEvent(sf::Event &event) {
    if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape)) {
        std::cout << "esc pressed while paused !!" << std::endl;
        mScreenManager->changeScreen("game");
    }
}

void PauseScreen::update(sf::Time dt) {
    i += 3;
    mytext.setRotation(i);
    mytext.setScale(1.2 + 0.9 * sin(i * M_PI / 180), 1.2 + 0.9 * sin(i * M_PI / 180));
    mytext.setPosition(320 + 200 * sin(i * M_PI / 180 * 0.4), 240 + 150 * cos(i * M_PI / 180 * 0.5));
}

void PauseScreen::render(sf::RenderWindow &window) {
    window.draw(mytext);
}