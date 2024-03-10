
#ifndef PADDLE_H
#define PADDLE_H

#include <SFML/Graphics.hpp>

// #include "component.h"

enum class PaddleType
{
    Blue,
    Red,
};

enum class PaddlePosition
{
    Left,
    Right,
};

class Paddle
{
public:
    Paddle(sf::Texture &texture, PaddleType type);
    void moveUp();
    void moveDown();
    void setSpeed(float inSpeed);
    sf::Vector2f getPosition() const;
    void setPosition(const sf::RenderWindow &window, PaddlePosition position);
    sf::Sprite &getSprite();

private:
    sf::Sprite m_sprite;
    float m_velocity = 10.0f;
    const float m_initialSpeed = 20.0f; // Initial speed of the paddle
    const float m_margin = 30.0f;       // Margin from the window edge
};

#endif // PADDLE_H
