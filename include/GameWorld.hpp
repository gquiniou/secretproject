//
// Created by greg on 28/01/2019.
//

#ifndef SECRETPROJECT_GAMEWORLD_HPP
#define SECRETPROJECT_GAMEWORLD_HPP

#include "cute_c2.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <entt/entt.hpp>
#include <iostream>
#include <utility> #include <utility>

struct rectCollidable {

};
struct circleCollidable {
    c2Circle circle;
    //  circle.p = c2V(200, 200);
    //  circle.r = 20;

};


struct velocity {
    explicit velocity(sf::Vector2f v) : vel(v) {};
    velocity(int x, int y) : vel(sf::Vector2f(x, y)) {};
    sf::Vector2f vel;
};

struct commoninfo {
    commoninfo(sf::Vector2f p, sf::Sprite s) : pos(p), sprite(std::move(std::move(s))) {
        sprite.setOrigin(sprite.getLocalBounds().width /2, sprite.getLocalBounds().height /2);
    };
    void updatePos(velocity &v) {
        pos = pos + v.vel;
        if (pos.x < 0 || pos.x > 800) v.vel.x = -v.vel.x;             
        if (pos.y < 0 || pos.y > 600) v.vel.y = -v.vel.y; 

        sprite.setPosition(pos);
    }
    sf::Vector2f pos;
    sf::Sprite sprite;
};

struct attributes {
    int hitpoints;
};

class GameWorld {
    enum gameState {WAITING, PLAYING, GAMEOVER};

public:
    void initLevel();
    void handleEvent(sf::Event &event);
    void update(sf::Time dt);
    void render(sf::RenderWindow *window);

private:
    gameState mGS;
    entt::registry<> registry;
};



#endif //SECRETPROJECT_GAMEWORLD_HPP
