/*
 * ScreenManager.hpp
 *
 *  Created on: 2018/12/28
 *      Author: greg
 */

#ifndef SCREENMANAGER_H_
#define SCREENMANAGER_H_

#include <Screen.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Window/Event.hpp>
#include <map>
#include <iostream>

class ScreenManager {

public:
    explicit ScreenManager(sf::RenderWindow *window) : mWindow(window) {};

    void handleEvent(sf::Event &event);

    void update(sf::Time dt);

    void render();

    void changeScreen(const std::string &name);

    void registerScreen(const std::string &name, Screen &s);

    ~ScreenManager() {
        for (auto x : screens) {
            delete x.second;
        }
    };
private:
    sf::RenderWindow *mWindow;
    std::map<std::string, Screen *> screens;
    Screen *activeScreen = nullptr;
};

#endif /* SCREENMANAGER_H_ */