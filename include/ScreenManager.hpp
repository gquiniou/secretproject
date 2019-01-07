/*
 * ScreenManager.hpp
 *
 *  Created on: 2018/12/28
 *      Author: greg
 */

#ifndef SCREENMANAGER_H_
#define SCREENMANAGER_H_

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Window/Event.hpp>
#include <Screen.hpp>
#include <map>
#include <iostream>


class ScreenManager {
public:
    explicit ScreenManager(sf::RenderWindow &window) {
        mWindow = &window;
    };

    void handleEvent(sf::Event &event) {
        activeScreen->handleEvent(event);
    };

    void update(sf::Time dt) {
        activeScreen->update(dt);
    };

    void render() {
        // std::cout << "in render" << std::endl;
        activeScreen->render(mWindow);
    };

    void changeScreen(const std::string &name) {
        activeScreen = screens[name];
    }

    void registerScreen(const std::string &name, Screen &s) {
        screens[name] = &s;
    };

private:
    sf::RenderWindow *mWindow;
    std::map<std::string, Screen *> screens;
    Screen *activeScreen = nullptr;
};

#endif /* SCREENMANAGER_H_ */