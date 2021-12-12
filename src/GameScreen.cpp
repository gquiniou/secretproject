//
// Created by greg on 06/01/2019.
//

#include "GameScreen.hpp"

GameScreen::GameScreen(ScreenManager &sm) : Screen(sm) {
    mWorld.initLevel();
}

void GameScreen::handleEvent(sf::Event &event) {
    if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape)) {
        std::cout << "esc pressed  !!" << std::endl;
        mScreenManager.changeScreen("pause");
    }
}

void GameScreen::update(sf::Time dt) {
    mWorld.update(dt);
}

void GameScreen::render(sf::RenderWindow &window) {
    mWorld.render(window);
}
