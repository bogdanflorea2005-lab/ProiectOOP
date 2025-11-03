#include <iostream>
#include <SFML/Graphics.hpp>

#include "Enemy.h"
#include "Player.h"
#include "Tile.h"

void displayImage(sf::RenderWindow& w, std::string imagePath) {
    sf::Texture texture;
    texture.loadFromFile(imagePath);
    sf::Sprite sprite(texture);
    sprite.setOrigin(sf::Vector2f(texture.getSize().x/2, texture.getSize().y/2));
    sprite.setPosition(sf::Vector2f(w.getSize().x / 2, w.getSize().y / 2));
    sprite.setScale(sf::Vector2f(10, 10));
    w.draw(sprite);
}

int main()
{
    auto window = sf::RenderWindow(sf::VideoMode({1920u, 1080u}), "CMake SFML Project");
    window.setFramerateLimit(144);

    std::string filePath1="Textures/placeholder.png";
    std::string tilePath ="Textures/placeholderTile.png";
    std::string tilePath2 ="Textures/placeholderTile2.png";
    std::string enemyPath = "Textures/placeholderEnemy.png";
    std::string lBozo="Textures/Lbozo.png";

    Player p(filePath1, 500, 300);
    std::cout<<p;
    Tile tile(tilePath, 300, 200);
    Tile tile2(tilePath, 1100, 150);
    Tile tile3(tilePath2, 450, 650);
    Tile tile4(tile3, 450 + 555, 650);
    Tile tile5(tile4, 450+555+555, 650);
    Enemy e(enemyPath, 1200, 300);

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
        }

        window.clear();
        p.drawPlayer(window);


        e.drawEnemy(window);
        e.seekPlayer(p);
        tile.drawTile(window);
        tile2.drawTile(window);
        tile3.drawTile(window);
        tile4.drawTile(window);
        tile5.drawTile(window);
        tile.checkCollision(p);
        tile2.checkCollision(p);
        tile3.checkCollision(p);
        tile4.checkCollision(p);
        tile5.checkCollision(p);
        tile.checkCollision(e);
        tile2.checkCollision(e);
        tile3.checkCollision(e);
        tile4.checkCollision(e);
        tile5.checkCollision(e);
        p.move();
        if (p.getDead()==false) {

        }else {
            displayImage(window, lBozo);
        }
        window.display();
    }
}
