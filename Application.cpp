/*
 * Application.cpp
 *
 *  Created on: 2018/12/28
 *      Author: greg
 */
#include <Application.hpp>


Application::Application() : mWindow(sf::VideoMode(640, 480), "Game", sf::Style::Close) {

    mWindow.setMouseCursorVisible(false);
    mWindow.setVerticalSyncEnabled(true);

}

void Application::run() {

}