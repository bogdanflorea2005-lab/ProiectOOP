//
// Created by Bogda on 11/1/2025.
//

#include "Player.h"

void Player::setPosition(float x, float y) {
    position = sf::Vector2f(x, y);
}
sf::Vector2f Player::getPosition() {
    return position;
}
//////////////////////////////////////////////////////////////
void Player::setGrounded(bool isGrounded) {
    this->isGrounded = isGrounded;
}
bool isGrounded() {
    return isGrounded;
}
//////////////////////////////////////////////////////////////
sf::Vector2u Player::getTexSize() {
    return this->texSize;
}
//////////////////////////////////////////////////////////////
void Player::setXVelocity(float x) {
    this->velocity.x=x;
}
void Player::setYVelocity(float y) {
    this->velocity.y=y;
}
sf::Vector2f Player::getVelocity() {
    return this->velocity;
}
//////////////////////////////////////////////////////////////
void Player::drawPlayer(sf::RenderWindow& window) {
    sf::Sprite sprite(texture);
    sprite.setOrigin(sf::Vector2f(texSize.x/2,texSize.y/2));
    sprite.setPosition(sf::Vector2f(position.x,position.y));
    sprite.setScale(sf::Vector2f(1, 1));
    window.draw(sprite);
}
//////////////////////////////////////////////////////////////
void Player::resetSpace() {
    pressedSpace=false;
}
//////////////////////////////////////////////////////////////
void Player::setDead(bool isDead) {
    this->isDead = isDead;
}
bool Player::getDead() {
    return isDead;
}
//////////////////////////////////////////////////////////////
void Player::move() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)==1 && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)==0) {
        velocity.x += 0.25;
        if (velocity.x>=6) {
            velocity.x = 6;
        }
        position.x+=velocity.x;
    }else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)==1 && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)==0) {
        velocity.x -= 0.25;
        if (velocity.x<=-6) {
            velocity.x = -6;
        }
        position.x+=velocity.x;
    }else{
        direction=velocity.x/abs(velocity.x);
        if (abs(velocity.x)>0) {
            velocity.x -= 0.25*direction;
        }
        position.x+=velocity.x;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)==1 && isGrounded==true) {
        isGrounded = false;
        velocity.y=0;
        velocity.y -=15;
        position.y+=velocity.y;
    }

    velocity.y+=0.25;
    if (velocity.y>=5) {
        velocity.y = 5;
    }
    position.y+=velocity.y;
}

