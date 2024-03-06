
#ifndef BALL_H
#define BALL_H

#include <SFML/Graphics.hpp>
#include <random>

class Ball {
public:
    Ball(sf::Texture& texture);
    sf::Vector2f getPosition()const;
    void setPosition(const sf::RenderWindow& window);
    void setVelocityX(float velocityX);
    void setVelocityY(float velocityY);
    void move();
    sf::Sprite& getSprite();

private:
    sf::Sprite m_sprite;
    float m_velocityX;
    float m_velocityY;
};


#endif // BALL_H