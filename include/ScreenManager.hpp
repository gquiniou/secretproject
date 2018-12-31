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
  ScreenManager(sf::RenderWindow &window) : mWindow(&window){};
  void handleEvent(sf::Event event) { event.type; };
  void update(sf::Time dt) {   std::cout << dt.asMilliseconds() << "x" << std::endl;
 };
  void render(){};

  void changeScreen(Screen s);
  void registerScreen(Screen s);

private:
  sf::RenderWindow *mWindow;
  std::map<std::string, Screen *> screens;
  Screen *activeScreen;
};

#endif /* SCREENMANAGER_H_ */