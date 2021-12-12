//
// Created by greg on 28/01/2019.
//

#include <iostream>
#include "GameWorld.hpp"
#include "ResourceManager.hpp"


template <typename T>
std::ostream& operator<<(std::ostream& os, const sf::Vector2<T> v){
  os  << "sf::Vector2: " << v.x << ", " << v.y << ';';
  return os;
}

void GameWorld::initLevel() {
    mGS = WAITING;
    sf::Texture *sprites = ResourceManager::getTexture("assets/breakout_sprites.png");

    sf::IntRect rects[4];

    rects[0] = sf::IntRect(0, 0, 31, 31);
    rects[1] = sf::IntRect(40, 0, 31, 31);
    rects[2] = sf::IntRect(80, 0, 31, 31);
    rects[3] = sf::IntRect(160, 0, 31, 31);

    //TODO: clear all entities

    //creating a few brick entities
    for (int i = 0; i < 150; i++) {
        auto myentity = registry.create();
        registry.assign<velocity>(myentity, rand() % 10 - 5, rand() % 10 -5);
        sf::Sprite s(*sprites, rects[i % 4]);
        //std::cout << "i " << i << " i%sizeof(rects) " << i % sizeof(rects) << std::endl;
        registry.assign<commoninfo>(myentity, s);
        registry.assign<rectCollidable>(myentity, 400, 300, 31, 31);
    }
    std::cout << "init" << std::endl;
}

void GameWorld::handleEvent(sf::Event &event) {

}

void GameWorld::update(sf::Time dt) {
    auto view = registry.view<commoninfo, velocity, rectCollidable>();
    for(auto entity: view) {
        auto &cinfo  = view.get<commoninfo>(entity);
        auto &vel = view.get<velocity>(entity);
        cinfo.updatePos(vel);

        auto &colinfo = view.get<rectCollidable>(entity);
        colinfo.updatePos(vel);

//        sf::Sprite s = cinfo.sprite;
//sf::Vector2f  pos1 = s.getPosition();
//        s.setPosition(s.getPosition().x + vel.vel.x, s.getPosition().y + vel.vel.y);
//        sf::Vector2f  pos2 = s.getPosition();
//std::cout << pos1 << " " << pos2 << std::endl;
        // ...
    }

}

void GameWorld::render(sf::RenderWindow &window) {
    auto view = registry.view<commoninfo>();
    for(auto entity: view) {
        auto &info = view.get(entity);
        window.draw(info.sprite);
    }
}