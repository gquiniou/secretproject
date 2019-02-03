/*
 * MenuScreen.hpp
 *
 *  Created on: 2 f�vr. 2019
 *      Author: Greg
 */

#ifndef MENUSCREEN_HPP_
#define MENUSCREEN_HPP_

#include <ScreenManager.hpp>
#include <Screen.hpp>
#include <SFML/Graphics/Text.hpp>


class MenuScreen: public Screen {

enum menuoptions {none, play, quit};

public:
	explicit MenuScreen(ScreenManager *);

    void handleEvent(sf::Event &event) override;

    void update(sf::Time dt) override;

    void render(sf::RenderWindow *window) override;

private: 
	sf::Text playoption;
	sf::Text quitoption;
	sf::Font f;
	menuoptions selected = none;
};

#endif /* MENUSCREEN_HPP_ */
