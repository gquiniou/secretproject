/*
 * Screen.hpp
 *
 *  Created on: 2018/12/28
 *      Author: greg
 */

#ifndef SCREEN_H_
#define SCREEN_H_

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/System/Time.hpp>

class Screen {
public:
    Screen() = default;

    virtual void handleEvent(sf::Event &event) = 0;

    virtual void update(sf::Time dt) = 0;

    virtual void render(sf::RenderWindow *) = 0;

private:
};

#endif /* SCREEN_H_ */