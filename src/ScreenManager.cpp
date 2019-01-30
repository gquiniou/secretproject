//
// Created by greg on 13/01/2019.
//
#include <ScreenManager.hpp>


void ScreenManager::handleEvent(sf::Event &event) {
    activeScreen->handleEvent(event);
};

void ScreenManager::update(sf::Time dt) {
    activeScreen->update(dt);
};

void ScreenManager::render() {
    activeScreen->render(*mWindow);
};

void ScreenManager::changeScreen(const std::string &name) {
    activeScreen = screens[name];
}

void ScreenManager::registerScreen(const std::string &name, Screen &s) {
    screens[name] = &s;
};

ScreenManager::~ScreenManager() {
    for (auto x : screens) {
        delete x.second;
    }
};