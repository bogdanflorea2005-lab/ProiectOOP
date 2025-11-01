//
// Created by Bogda on 11/1/2025.
//

#include "Enemy.h"

void Enemy::drawEnemy(sf::RenderWindow &window)  {
    sf::Sprite sprite(texture);
    sprite.setTexture(texture);
    sprite.setOrigin(sf::Vector2f(texSize.x/2,texSize.y/2));
    sprite.setPosition(position);
    sprite.setScale(sf::Vector2f(1, 1));
    window.draw(sprite);
}

void Enemy::setPosition(float x, float y) {
    position = sf::Vector2f(x, y);
}
sf::Vector2f Enemy::getPosition() {
    return position;
}
//////////////////////////////////////////////////////////////////////
void Enemy::setVelocity(float x, float y) {
    velocity = sf::Vector2f(x, y);
}
sf::Vector2f Enemy::getVelocity() {
    return velocity;
}
//////////////////////////////////////////////////////////////////////
sf::Vector2u Enemy::getTexSize() {
    return texSize;
}
//////////////////////////////////////////////////////////////////////
void Enemy::seekPlayer(Player& p) {
    float distance=abs(p.getPosition().x-position.x);
    if (position.x<p.getPosition().x && distance>30) {
        velocity.x+=0.25;
        if (velocity.x>=6) {
            velocity.x=6;
        }
        position.x+=velocity.x;
    }
    else
        if (position.x>p.getPosition().x && distance>30) {
            velocity.x-=0.25;
            if (velocity.x>=-6) {
                velocity.x=-6;
            }
            position.x+=velocity.x;
        }

    if (abs(p.getPosition().x-position.x)<40) {
        p.setDead(true);
    }

    velocity.y+=1;
    if (velocity.y==6) {
        velocity.y = 6;
    }
    position.y+=velocity.y;
}
