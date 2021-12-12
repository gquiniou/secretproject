//
// Created by greg on 13/01/2019.
//
#include <ScreenManager.hpp>


void ScreenManager::handleEvent(sf::Event &event) {
    mActiveScreen->handleEvent(event);
}

void ScreenManager::update(sf::Time dt)  const {
    mActiveScreen->update(dt);
}

void ScreenManager::render() const {
    mActiveScreen->render(mWindow);
}

void ScreenManager::changeScreen(const std::string &name) {
    mActiveScreen = &*mScreens[name];
}

void ScreenManager::registerScreen(const std::string &name, std::unique_ptr<Screen> s) {
    mScreens[name] = std::move(s);
}

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
}
