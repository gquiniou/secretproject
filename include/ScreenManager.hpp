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

class ScreenManager : public sf::NonCopyable {

public:
    explicit ScreenManager(sf::RenderWindow *window) : mWindow(window) {};

    void handleEvent(sf::Event &event);

    void update(sf::Time dt);

    void render();

    void changeScreen(const std::string &name);

    void registerScreen(const std::string &name, Screen &s);

    ~ScreenManager();

private:
    sf::RenderWindow *mWindow;
    //TODO: use smart pointers for Screens
    std::map<std::string, Screen *> screens;
    Screen *activeScreen = nullptr;
};

#endif /* SCREENMANAGER_H_ */