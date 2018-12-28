/*
 * Application.hpp
 *
 *  Created on: 2018/12/28
 *      Author: greg
 */

#ifndef APPLICATION_H_
#define APPLICATION_H_

#include <SFML/System/Time.hpp>
#include <SFML/Graphics/RenderWindow.hpp>


class Application {
public:
    Application();
    void run();

private:
    void processInput();
	void update(sf::Time dt);
    void render();

	static const sf::Time TimePerFrame;
	sf::RenderWindow mWindow;
};


#endif /* APPLICATION_H_ */