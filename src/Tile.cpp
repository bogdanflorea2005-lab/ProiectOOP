//
// Created by Bogda on 11/1/2025.
//

#include "Tile.h"

#include "Enemy.h"
#include "Player.h"

void Tile::drawTile(sf::RenderWindow& window) {
    sf::Sprite sprite(texture);
    sprite.setOrigin(sf::Vector2f(texSize.x/2,texSize.y/2));
    sprite.setPosition(sf::Vector2f(position.x,position.y));
    sprite.setScale(sf::Vector2f(1, 1));
    window.draw(sprite);
}

sf::Vector2f Tile::getPosition() {
    return position;
}

void Tile::setPosition(float x, float y) {
    position.x=x;
    position.y=y;
}

sf::Vector2u Tile::getTexSize() {
    return texSize;
}

void Tile::checkCollision(Player &p) {
    if (p.getVelocity().x>0) {
        if (p.getPosition().x+p.getTexSize().x/2+p.getVelocity().x>position.x-texSize.x/2 && p.getPosition().x<position.x-texSize.x/2 && (p.getPosition().y>position.y-texSize.y/2 && p.getPosition().y-p.getTexSize().y/2<position.y+texSize.y/2)) {
            p.setPosition(position.x-texSize.x/2-p.getTexSize().x/2, p.getPosition().y);
            p.setXVelocity(0);
        }
    }

    if (p.getVelocity().x<0) {
        if (p.getPosition().x-p.getTexSize().x/2+p.getVelocity().x<position.x+texSize.x/2 && p.getPosition().x>position.x+texSize.x/2 && (p.getPosition().y>position.y-texSize.y/2 && p.getPosition().y-p.getTexSize().y/2<position.y+texSize.y/2)) {
            p.setPosition(position.x+texSize.x/2+p.getTexSize().x/2, p.getPosition().y);
            p.setXVelocity(0);
        }
    }

    if (p.getVelocity().y>=0) {
        if (p.getPosition().y+p.getTexSize().y/2+p.getVelocity().y>position.y-texSize.y/2 && p.getPosition().y<position.y-texSize.y/2 && (p.getPosition().x+p.getTexSize().x/2>position.x-texSize.x/2 && p.getPosition().x-p.getTexSize().x/2<position.x+texSize.x/2)) {
            p.setPosition(p.getPosition().x, position.y-texSize.y/2-p.getTexSize().y/2);
            p.setYVelocity( 0);
            p.setGrounded(true);
            p.resetSpace();
        }
    }

    if (p.getVelocity().y<0) {
        if (p.getPosition().y>position.y+texSize.y/2 && p.getPosition().y-p.getTexSize().y/2+p.getVelocity().y<position.y+texSize.y/2 && (p.getPosition().x+p.getTexSize().x/2>position.x-texSize.x/2 && p.getPosition().x-p.getTexSize().x/2<position.x+texSize.x/2)) {
            p.setPosition(p.getPosition().x, position.y+texSize.y/2+p.getTexSize().y/2);
            p.setYVelocity(0);
        }
    }
}

void Tile::checkCollision(Enemy &p) {
    if (p.getVelocity().x>0) {
        if (p.getPosition().x+p.getTexSize().x/2+p.getVelocity().x>position.x-texSize.x/2 && p.getPosition().x<position.x-texSize.x/2 && (p.getPosition().y>position.y-texSize.y/2 && p.getPosition().y-p.getTexSize().y/2<position.y+texSize.y/2)) {
            p.setPosition(position.x-texSize.x/2-p.getTexSize().x/2, p.getPosition().y);
            p.setVelocity(0, p.getVelocity().y);
        }
    }

    if (p.getVelocity().x<0) {
        if (p.getPosition().x-p.getTexSize().x/2+p.getVelocity().x<position.x+texSize.x/2 && p.getPosition().x>position.x+texSize.x/2 && (p.getPosition().y>position.y-texSize.y/2 && p.getPosition().y-p.getTexSize().y/2<position.y+texSize.y/2)) {
            p.setPosition(position.x+texSize.x/2+p.getTexSize().x/2, p.getPosition().y);
            p.setVelocity(0, p.getVelocity().y);
        }
    }

    if (p.getVelocity().y>=0) {
        if (p.getPosition().y+p.getTexSize().y/2+p.getVelocity().y>position.y-texSize.y/2 && p.getPosition().y<position.y-texSize.y/2 && (p.getPosition().x+p.getTexSize().x/2>position.x-texSize.x/2 && p.getPosition().x-p.getTexSize().x/2<position.x+texSize.x/2)) {
            p.setPosition(p.getPosition().x, position.y-texSize.y/2-p.getTexSize().y/2);
            p.setVelocity(p.getVelocity().x, 0);
        }
    }

    if (p.getVelocity().y<0) {
        if (p.getPosition().y>position.y+texSize.y/2 && p.getPosition().y-p.getTexSize().y/2+p.getVelocity().y<position.y+texSize.y/2 && (p.getPosition().x+p.getTexSize().x/2>position.x-texSize.x/2 && p.getPosition().x-p.getTexSize().x/2<position.x+texSize.x/2)) {
            p.setPosition(p.getPosition().x, position.y+texSize.y/2+p.getTexSize().y/2);
            p.setVelocity(p.getVelocity().x, 0);
        }
    }
}
