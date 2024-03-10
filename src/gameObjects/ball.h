
#ifndef BALL_H
#define BALL_H

#include <SFML/Graphics.hpp>
#include <random>

// #include "component.h"

class Ball
{
public:
    Ball(sf::Texture &texture);
    void reset(const sf::RenderWindow &window);

    sf::Vector2f getPosition() const;
    void setPosition(const sf::RenderWindow &window);
    void setVelocityX(float velocityX);
    void setVelocityY(float velocityY);
    void move();
    void setSpeed(float inSpeed);
    sf::Sprite &getSprite();
    float getVelocityX() const;
    float getVelocityY() const;

private:
    sf::Sprite m_sprite;
    float m_velocityX;
    float m_velocityY;
    const float m_initialSpeed = 2.0f; // Initial speed of the ball
};

#endif // BALL_H