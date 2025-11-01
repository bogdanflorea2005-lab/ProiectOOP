//
// Created by Bogda on 11/1/2025.
//

#ifndef OOP_PLAYER_H
#define OOP_PLAYER_H
#include <SFML/Graphics.hpp>

class Player {
private:
    int direction=0;
    sf::Vector2f position;
    bool isGrounded, pressedSpace=false, isDead=false;
    sf::Texture texture;
    sf::Vector2u texSize;
    sf::Vector2f velocity=sf::Vector2f(0, 0);
public:
    Player(std::string filePath, float x, float y) {
        texture.loadFromFile(filePath);
        texSize=texture.getSize();
        position.x=x;
        position.y=y;
    }

    void drawPlayer(sf::RenderWindow& window);

    void setPosition(float x, float y);
    sf::Vector2f getPosition();

    sf::Vector2u getTexSize();

    void setXVelocity(float x);
    void setYVelocity(float y);
    sf::Vector2f getVelocity();

    void setGrounded(bool isGrounded);
    bool getGrounded();

    void resetSpace();

    void setDead(bool isDead);
    bool getDead();

    void move();

    friend std::ostream& operator<<(std::ostream& os, Player& p){
        os << "X: " << p.position.x << ", Y: " << p.position.y <<", img size: "<< p.texSize.x<<"x"<<p.texSize.y<<"\n";
        return os;
    }
};


#endif //OOP_PLAYER_H