/*
 * MenuScreen.cpp
 *
 *  Created on: 2 f�vr. 2019
 *      Author: Greg
 */

#include "MenuScreen.hpp"

void horizPosition(sf::Text &target, float vertpos) {
	//
	sf::FloatRect bounds = target.getGlobalBounds();
	target.setOrigin(bounds.width / 2, bounds.height / 2);
    target.setPosition(640 / 2.0, vertpos); //TODO: remove hardcoded screen size
}

void highlightOption(sf::Text &target, bool highlight) {
	if (highlight) {
		target.setOutlineColor(sf::Color::Red);
		target.setOutlineThickness(5);
	} else {
		target.setOutlineThickness(0);
	}
}

MenuScreen::MenuScreen(ScreenManager *sm) : Screen(sm) {
    f.loadFromFile("assets/Consequences.ttf");

	playoption.setString("Play");
	playoption.setFont(f);
	playoption.setFillColor(sf::Color::Blue);
	playoption.setCharacterSize(40);
	horizPosition(playoption, 200);

	quitoption.setString("Quit");
	quitoption.setFont(f);
	quitoption.setFillColor(sf::Color::Blue);
	quitoption.setCharacterSize(40);
	horizPosition(quitoption, 250);

}


void MenuScreen::handleEvent(sf::Event &event) {
    if ((event.type == sf::Event::KeyPressed)) {
		switch (event.key.code)
		{
			case sf::Keyboard::Down:
        		std::cout << "down pressed !!" << std::endl;
				if (selected == none) {
					selected = play;
				} else if (selected == play) {
					selected = quit;	
				} else if (selected == quit) {
					selected = play;
				}
				break;

			case sf::Keyboard::Up:
        		std::cout << "up pressed" << std::endl;		
				if (selected == none) {
					selected = play;
				} else if (selected == play) {
					selected = quit;	
				} else if (selected == quit) {
					selected = play;
				}						
				break;

			case sf::Keyboard::Enter:
        		std::cout << "Enter pressed" << std::endl;				
				if (selected == play) {
					mScreenManager->changeScreen("game");
				} else if (selected == quit) {
					mScreenManager->quit();
				}
				break;				

			default:
				break;
		}
    }
}

void MenuScreen::update(sf::Time dt) {
	highlightOption(playoption, selected == play);
	highlightOption(quitoption, selected == quit);
}

void MenuScreen::render(sf::RenderWindow *window) {
	window->draw(playoption);
	window->draw(quitoption);
}
