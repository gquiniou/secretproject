/*
 * Screen.hpp
 *
 *  Created on: 2018/12/28
 *      Author: greg
 */

#ifndef SCREEN_H_
#define SCREEN_H_

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Time.hpp>

class Screen {
public:
  Screen(){};
  virtual void handleEvent(sf::Event event);
  virtual void update(sf::Time dt);
  virtual void render(sf::RenderWindow &);

private:
};

#endif /* SCREEN_H_ */