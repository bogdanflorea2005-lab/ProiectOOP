//
// Created by Bogda on 11/1/2025.
//

#ifndef CMAKESFMLPROJECT_ENEMY_H
#define CMAKESFMLPROJECT_ENEMY_H
#include "Player.h"
#include "SFML/System/Vector2.hpp"
#include "SFML/Graphics.hpp"


class Enemy {
    private:
    sf::Texture texture;
    sf::Vector2f position;
    sf::Vector2u texSize;
    sf::Vector2f velocity=sf::Vector2f(0,0);

    public:
    Enemy(std::string filePath, float x, float y) {
        texture.loadFromFile(filePath);
        texSize=texture.getSize();
        position.x=x;
        position.y=y;
    }

    Enemy(const Enemy& e) {
        texture = e.texture;
        position = e.position;
        texSize = e.texSize;
    }

    void drawEnemy(sf::RenderWindow& window);

    void setPosition(float x, float y);
    sf::Vector2f getPosition();

    void setVelocity(float x, float y);
    sf::Vector2f getVelocity();

    sf::Vector2u getTexSize();

    void seekPlayer(Player& p);

    friend std::ostream& operator<<(std::ostream& os, const Enemy& e) {
        os << "X: " << e.position.x << ", Y: " << e.position.y << ", img size: "<<e.texSize.x<<"x"<<e.texSize.y;
        return os;
    }
};


#endif //CMAKESFMLPROJECT_ENEMY_H