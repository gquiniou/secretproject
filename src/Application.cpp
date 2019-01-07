/*
 * Application.cpp
 *
 *  Created on: 2018/12/28
 *      Author: greg
 */
#include <Application.hpp>
#include <GameScreen.hpp>

Application::Application()
        : mWindow(sf::VideoMode(640, 480), "Game", sf::Style::Close),
          mscreenmanager(mWindow) {

    mWindow.setMouseCursorVisible(false);
    mWindow.setVerticalSyncEnabled(true);

//  GameScreen gs;
    mscreenmanager.registerScreen("game", *new GameScreen());
    mscreenmanager.changeScreen("game");
}

void Application::run() {

    const sf::Time TimePerFrame = sf::seconds(1.f / 60.f);
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;

    while (mWindow.isOpen()) {
        sf::Time dt = clock.restart();
        timeSinceLastUpdate += dt;
        while (timeSinceLastUpdate > TimePerFrame) {
            timeSinceLastUpdate -= TimePerFrame;

            processInput();
            update(TimePerFrame);

            // mWindow.close();
        }

        render();
    }
}

void Application::processInput() {
    sf::Event event;
    while (mWindow.pollEvent(event)) {
        mscreenmanager.handleEvent(event);

        if (event.type == sf::Event::Closed)
            mWindow.close();
    }
}

void Application::update(sf::Time dt) {
    mscreenmanager.update(dt);
    //std::cout << dt.asMilliseconds() << std::endl;
}

void Application::render() {

    mWindow.clear();
    mscreenmanager.render();
    mWindow.display();
}