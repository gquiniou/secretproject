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
    activeScreen->render(mWindow);
};

void ScreenManager::changeScreen(const std::string &name) {
    activeScreen = &*screens[name];
}

void ScreenManager::registerScreen(const std::string &name, std::unique_ptr<Screen> s) {
    screens[name] = std::move(s);
};

void ScreenManager::setDone(bool done) {
    mDone = done;
}

bool ScreenManager::getDone() {
    return mDone;
}

ScreenManager::~ScreenManager() {
   // for (auto x : screens) {
   //     delete x.second;
   // }
};
