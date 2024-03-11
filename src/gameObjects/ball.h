
#ifndef BALL_H
#define BALL_H

#include <SFML/Graphics.hpp>

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
    void setSpeed(int inSpeed);
    void setDifficulty(int inDifficulty);
    sf::Sprite &getSprite();
    float getVelocityX() const;
    float getVelocityY() const;
    sf::Vector2f getVelocity() const;

private:
    sf::Sprite m_sprite;
    float m_velocityX;
    float m_velocityY;
    static constexpr float INITIAL_SPEED = 1.5f; // Initial speed of the ball
    static constexpr float INITIAL_BALL_SIZE = 0.8f;
    static constexpr float BOUNDRY_TOP = 0;
    static constexpr float BOUNDRY_BOTTOM = 550;
};

#endif // BALL_H