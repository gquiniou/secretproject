//
// Created by greg on 13/01/2019.
//

#include <PauseScreen.hpp>
#include <cmath>


PauseScreen::PauseScreen(ScreenManager &sm) : Screen(sm) {
    f.loadFromFile("assets/Consequences.ttf");

    pausedText.setString("Paused");
    pausedText.setFont(f);
    pausedText.setFillColor(sf::Color::Red);
    pausedText.setCharacterSize(65);
    pausedText.setStyle(sf::Text::Bold);
    sf::FloatRect bounds = pausedText.getGlobalBounds();
    pausedText.setOrigin(bounds.width / 2, bounds.height / 2);
    pausedText.setPosition(640 / 2.0, 480 / 2.0); //TODO: remove hardcoded screen size

    messageText.setString("Press Q for main menu");
    messageText.setFont(f);
    messageText.setFillColor(sf::Color::Blue);
    messageText.setCharacterSize(25);
    bounds = messageText.getGlobalBounds();
    messageText.setOrigin(bounds.width / 2, bounds.height / 2);
    messageText.setPosition(640 / 2.0, 400); //TODO: remove hardcoded screen size

}

void PauseScreen::handleEvent(sf::Event &event) {
    if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape)) {
        std::cout << "esc pressed while paused !!" << std::endl;
        mScreenManager.changeScreen("game");
    }
    if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Q)) {
        std::cout << "Q pressed while paused !!" << std::endl;
        mScreenManager.changeScreen("menu");
    }    
}

void PauseScreen::update(sf::Time dt) {
    i += 3;
    pausedText.setRotation(i);
    pausedText.setScale(1.2 + 0.9 * sin(i * M_PI / 180), 1.2 + 0.9 * sin(i * M_PI / 180));
    pausedText.setPosition(320 + 200 * sin(i * M_PI / 180 * 0.4), 240 + 150 * cos(i * M_PI / 180 * 0.5));
}

void PauseScreen::render(sf::RenderWindow &window) {
    window.draw(pausedText);
    window.draw(messageText);
    window.draw(messageText);
}
