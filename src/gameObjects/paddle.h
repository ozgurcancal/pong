
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
};

#endif // PADDLE_H
