
#ifndef PADDLE_H
#define PADDLE_H

#include <SFML/Graphics.hpp>

#include "paddleEnums.h"

class Paddle
{
public:
    Paddle(sf::Texture &texture, PaddleType type);
    void moveUp();
    void moveDown();
    void setSpeed(int inSpeed);
    void setDifficulty(int inDifficulty);
    sf::Vector2f getPosition() const;
    void setPosition(const sf::RenderWindow &window, PaddlePosition position);
    sf::Sprite &getSprite();

private:
    sf::Sprite m_sprite;
    float m_velocity = 10.0f;
    static constexpr float INITIAL_SPEED = 10.0f; // Initial speed of the paddle
    static constexpr float INITIAL_PADDLE_SIZE = 0.5f;
    static constexpr float MARGIN = 30.0f; // Margin from the window edge
};

#endif // PADDLE_H
