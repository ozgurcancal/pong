
#ifndef BALL_H
#define BALL_H

#include <SFML/Graphics.hpp>

class Ball {
public:
    Ball(sf::Texture& texture);
    void setPosition(const sf::RenderWindow& window);
    void move();
    sf::Sprite& getSprite();

private:
    sf::Sprite m_sprite;

};


#endif // BALL_H