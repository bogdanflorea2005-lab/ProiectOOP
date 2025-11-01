//
// Created by Bogda on 11/1/2025.
//

#ifndef CMAKESFMLPROJECT_TILE_H
#define CMAKESFMLPROJECT_TILE_H
#include "SFML/Graphics.hpp"


class Enemy;
class Player;

class Tile {
private:
    sf::Vector2f position;
    sf::Vector2u texSize;
    sf::Texture texture;

public:
    Tile(const std::string filePath, float x, float y) {
        texture.loadFromFile(filePath);
        texSize=texture.getSize();
        position.x = x;
        position.y = y;
    }

    Tile(const Tile& t) {
        position = t.position;
        texture = t.texture;
        texSize = t.texSize;
    }

    Tile(const Tile& t, float x, float y) {
        position=sf::Vector2f(x, y);
        texture=t.texture;
        texSize=texture.getSize();
    }

    void drawTile(sf::RenderWindow& w);

    sf::Vector2f getPosition();
    void setPosition(float x, float y);

    sf::Vector2u getTexSize();

    void checkCollision(Player& p);

    void checkCollision(Enemy& p);


};


#endif //CMAKESFMLPROJECT_TILE_H