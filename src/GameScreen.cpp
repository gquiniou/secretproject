//
// Created by greg on 06/01/2019.
//

#include "GameScreen.hpp"

GameScreen::GameScreen(ScreenManager *sm) : Screen(sm), myRectangle(sf::Vector2f(200, 200)) {
    myRectangle.setFillColor(sf::Color::White);
};

void GameScreen::handleEvent(sf::Event &event) {
    if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape)) {
        std::cout << "esc pressed  !!" << std::endl;
        mScreenManager->changeScreen("pause");
    }
}

void GameScreen::update(sf::Time dt) {
    //  Screen::update(dt);
    myRectangle.setPosition(i++ % 500, i++ % 500);
}

void GameScreen::render(sf::RenderWindow *window) {
    //  Screen::render(window);
    window->draw(myRectangle);
}
