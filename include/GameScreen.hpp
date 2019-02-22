//
// Created by greg on 06/01/2019.
//

#ifndef SECRETPROJECT_GAMESCREEN_HPP
#define SECRETPROJECT_GAMESCREEN_HPP

#include <ScreenManager.hpp>
#include <Screen.hpp>
#include <GameWorld.hpp>
#include <SFML/Graphics/RectangleShape.hpp>


class GameScreen : public Screen {
public:
    explicit GameScreen(ScreenManager *);

    void handleEvent(sf::Event &event) override;

    void update(sf::Time dt) override;

    void render(sf::RenderWindow *window) override;

private:
    GameWorld mWorld;
};


#endif //SECRETPROJECT_GAMESCREEN_HPP
