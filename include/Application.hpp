/*
 * Application.hpp
 *
 *  Created on: 2018/12/28
 *      Author: greg
 */

#ifndef APPLICATION_H_
#define APPLICATION_H_

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Time.hpp>
#include <ScreenManager.hpp>

class Application {
public:
    Application();

    void run();

private:
    void processInput();

    void update(sf::Time dt);

    void render();

    sf::RenderWindow mWindow;
    ScreenManager mScreenManager;
};

#endif /* APPLICATION_H_ */