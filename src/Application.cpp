/*
 * Application.cpp
 *
 *  Created on: 2018/12/28
 *      Author: greg
 */
#include <Application.hpp>
#include <MenuScreen.hpp>
#include <GameScreen.hpp>
#include <PauseScreen.hpp>

Application::Application()
        : mWindow(sf::VideoMode(640, 480), "Game", sf::Style::Close),
          mScreenManager(&mWindow) {

    mWindow.setMouseCursorVisible(false);
    mWindow.setVerticalSyncEnabled(true);

    mScreenManager.registerScreen("menu", std::make_unique<MenuScreen>(&mScreenManager));
    mScreenManager.registerScreen("game", std::make_unique<GameScreen>(&mScreenManager));
    mScreenManager.registerScreen("pause", std::make_unique<PauseScreen>(&mScreenManager));
    mScreenManager.changeScreen("menu");
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

        if (mScreenManager.getDone()) {
            break;
        }

        render();
    }
}

void Application::processInput() {
    sf::Event event;
    while (mWindow.pollEvent(event)) {
        mScreenManager.handleEvent(event);

        if (event.type == sf::Event::Closed)
            mWindow.close();
    }
}

void Application::update(sf::Time dt) {
    mScreenManager.update(dt);
}

void Application::render() {
    mWindow.clear();
    mScreenManager.render();
    mWindow.display();
}
