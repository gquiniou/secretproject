/*
 * ResourceManager.h
 *
 *  Created on: 23 janv. 2012
 *      Author: greg
 */

#ifndef RESOURCEMANAGER_H_
#define RESOURCEMANAGER_H_

#include <SFML/Graphics.hpp>
#include <iostream>
#include <map>
#include <memory>
#include <string>

typedef std::map<std::string, std::unique_ptr<sf::Texture>> TextureMap;

class ResourceManager {
public:
  static sf::Texture *getTexture(const std::string &filename) {
    static TextureMap textures;
    std::cout << "getTexture called " << filename << std::endl;

    TextureMap::iterator it = textures.find(filename);
    if (it == textures.end()) {
      std::unique_ptr<sf::Texture> temp(new sf::Texture);
      if (temp->loadFromFile(filename)) {
        textures.emplace(filename, std::move(temp));
        return textures[filename].get();
      } else {
        std::cout << "could not load texture" << std::endl;
      }
    } else {
      return it->second.get();
    }
    return nullptr;
  }
};
#endif /* RESOURCEMANAGER_H_ */
