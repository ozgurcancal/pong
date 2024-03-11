

#include "ball.h"
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iostream>

Ball::Ball(sf::Texture &texture)
{
    // Load the paddle texture from file
    if (!texture.loadFromFile("assets/ball.png"))
    {
        std::cerr << "Failed to load ball texture" << std::endl;
        throw "Failed to load ball texture";
    }
    else
    {
        std::cout << "Paddle ball loaded" << std::endl;
    }

    m_sprite.setTexture(texture);
    m_sprite.setScale(INITIAL_BALL_SIZE, INITIAL_BALL_SIZE);

    // Seed the random number generator with the current time
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // Ensure the ball does not move vertically
    do
    {
        // Generate random value between -1.0 and 1.0
        m_velocityX = static_cast<float>(std::rand()) / RAND_MAX * 2.0 - 1.0;
        m_velocityY = static_cast<float>(std::rand()) / RAND_MAX * 2.0 - 1.0;
    } while (m_velocityX < 0.3f && m_velocityX > -0.3f && m_velocityY == 0.0f);

    // Normalize the direction vector
    float length = std::sqrt(m_velocityX * m_velocityX + m_velocityY * m_velocityY);
    m_velocityX /= length;
    m_velocityY /= length;

    // Apply the constant speed to the direction
    m_velocityX = m_velocityX * INITIAL_SPEED;
    m_velocityY = m_velocityY * INITIAL_SPEED;
}

void Ball::reset(const sf::RenderWindow &window)
{
    float prevSpeed = std::sqrt(m_velocityX * m_velocityX + m_velocityY * m_velocityY); // Constant speed for the ball
                                                                                        // Seed the random number generator with the current time
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // Ensure the ball does not move vertically
    do
    {
        // Generate random value between -1.0 and 1.0
        m_velocityX = static_cast<float>(std::rand()) / RAND_MAX * 2.0 - 1.0;
        m_velocityY = static_cast<float>(std::rand()) / RAND_MAX * 2.0 - 1.0;
    } while (m_velocityX < 0.3f && m_velocityX > -0.3f && m_velocityY == 0.0f);

    // Normalize the direction vector
    float length = std::sqrt(m_velocityX * m_velocityX + m_velocityY * m_velocityY);
    m_velocityX /= length;
    m_velocityY /= length;

    // Apply the constant speed to the direction
    m_velocityX = m_velocityX * prevSpeed;
    m_velocityY = m_velocityY * prevSpeed;

    setPosition(window);
}

sf::Vector2f Ball::getPosition() const
{
    return m_sprite.getPosition();
}

void Ball::setPosition(const sf::RenderWindow &window)
{
    // Calculate the center position for the sprite
    float posX = (window.getSize().x / 2.0f) - (m_sprite.getLocalBounds().width / 2.0f);
    float posY = (window.getSize().y / 2.0f) - (m_sprite.getLocalBounds().height / 2.0f);

    // Set the sprite's position to the center of the window
    m_sprite.setPosition(posX, posY);
}

sf::Sprite &Ball::getSprite()
{
    return m_sprite;
}

void Ball::move()
{
    // to do 0 ve 550 icin configurasyon degeri uret header da
    if (m_sprite.getPosition().y < BOUNDRY_TOP || m_sprite.getPosition().y > BOUNDRY_BOTTOM)
    {
        m_velocityY = -m_velocityY; // Reverse vertical velocity
    }

    m_sprite.move(m_velocityX, m_velocityY);
    std::cout << "Ball moved" << std::endl;
}

void Ball::setSpeed(int inSpeed)
{
    // Increase the speed of the ball
    m_velocityX = inSpeed;
    m_velocityY = inSpeed;
}

sf::Vector2f Ball::getVelocity() const
{
    return sf::Vector2f(m_velocityX, m_velocityY);
}

void Ball::setDifficulty(int inDifficulty)
{

    if (inDifficulty == 1)
    {
        // increase size of ball
        m_sprite.setScale(INITIAL_BALL_SIZE * 2, INITIAL_BALL_SIZE * 2);
        // decrease ball speed
        m_velocityX = INITIAL_SPEED / 2;
        m_velocityY = INITIAL_SPEED / 2;
    }
    else if (inDifficulty == 2)
    {
        m_sprite.setScale(INITIAL_BALL_SIZE, INITIAL_BALL_SIZE);
        m_velocityX = INITIAL_SPEED;
        m_velocityY = INITIAL_SPEED;
    }
    else if (inDifficulty == 3)
    {
        // decrease size of ball
        m_sprite.setScale(INITIAL_BALL_SIZE / 2, INITIAL_BALL_SIZE / 2);
        // increase ball speed
        m_velocityX = INITIAL_SPEED * 2;
        m_velocityY = INITIAL_SPEED * 2;
    }
    else
    {
        std::cerr << "Invalid difficulty" << std::endl;
        throw "Invalid difficulty";
    }
}

void Ball::setVelocityX(float velocityX)
{
    m_velocityX = velocityX;
}

void Ball::setVelocityY(float velocityY)
{
    m_velocityY = velocityY;
}

float Ball::getVelocityX() const
{
    return m_velocityX;
}

float Ball::getVelocityY() const
{
    return m_velocityY;
}
