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
#include <iostream>
#include <map>
#include <memory>
#include <Screen.hpp>

class Screen;

class ScreenManager : public sf::NonCopyable {

public:
  explicit ScreenManager(sf::RenderWindow &window) : mWindow(window){};

  void handleEvent(sf::Event &event);

  void update(sf::Time dt) const;

  void render() const;

  void changeScreen(const std::string &name);

  void registerScreen(const std::string &, std::unique_ptr<Screen>);

  void setDone(bool);

  bool getDone() const;

  ~ScreenManager();

private:
  sf::RenderWindow &mWindow;
  std::map<std::string, std::unique_ptr<Screen>> mScreens;
  Screen *mActiveScreen = nullptr;
  bool mDone = false;
};

#endif /* SCREENMANAGER_H_ */
