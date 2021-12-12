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

struct velocity {
    explicit velocity(sf::Vector2f v) : vel(v) {};

    velocity(int x, int y) : vel(sf::Vector2f(x, y)) {};
    sf::Vector2f vel;
};


struct rectCollidable {
    rectCollidable(float x, float y, float w, float h) {
        aabb.min = c2V(x, y);
        aabb.max = c2V(x + w, y + h);
    };

    void updatePos(velocity &v) {
        aabb.min.x += v.vel.x;
        aabb.max.x += v.vel.x;
        aabb.min.y += v.vel.y;
        aabb.max.y += v.vel.y;

    }

    c2AABB aabb;
};
struct circleCollidable {
    circleCollidable(float x, float y, float r) {
        circle.p = c2V(x, y);
        circle.r = r;
    }

    void updatePos(velocity &v) {
        circle.p.x += v.vel.x;
        circle.p.y += v.vel.y;
    }
    c2Circle circle;
};



struct commoninfo {
    commoninfo(sf::Sprite s) : sprite(std::move(std::move(s))) {
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
    void render(sf::RenderWindow &window);

private:
    gameState mGS;
    entt::registry<> registry;
};



#endif //SECRETPROJECT_GAMEWORLD_HPP
