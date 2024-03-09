

#include "ball.h"

#include <iostream> // std::cout icin eklendi

Ball::Ball(sf::Texture &texture)
{
    // Load the paddle texture from file
    if (!texture.loadFromFile("sprites/ball.png"))
    {
        std::cerr << "Failed to load ball texture" << std::endl;
        throw "Failed to load ball texture";
    }
    else
    {
        std::cout << "Paddle ball loaded" << std::endl;
    }
    // to do
    //  Seed the random number generator with the time
    // srand((int)time(0));
    //  Initialize random engine and distribution once
    static std::random_device rd;                             // Obtain a random number from hardware
    static std::mt19937 eng(rd());                            // Seed the generator
    static std::uniform_real_distribution<> distr(-1.0, 1.0); // Define range
    float initialSpeed = 1.0f;                                // Constant speed for the ball
    // Ensure the ball does not move vertically or horizontally
    do
    {
        m_velocityX = distr(eng);
        m_velocityY = distr(eng);
    } while (m_velocityX == 0 || m_velocityY == 0);

    // Normalize the direction vector
    float length = std::sqrt(m_velocityX * m_velocityX + m_velocityY * m_velocityY);
    m_velocityX /= length;
    m_velocityY /= length;

    // Apply the constant speed to the direction
    m_velocityX = m_velocityX * initialSpeed;
    m_velocityY = m_velocityY * initialSpeed;

    m_sprite.setTexture(texture);
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
    if (m_sprite.getPosition().y < 0 || m_sprite.getPosition().y > 550)
    {
        m_velocityY = -m_velocityY; // Reverse vertical velocity
    }
    // random move
    m_sprite.move(m_velocityX, m_velocityY);
    std::cout << "Ball moved" << std::endl;
}

void Ball::increaseSpeed()
{
    // Increase the speed of the ball
    m_velocityX *= 1.5f;
    m_velocityY *= 1.5f;
}

void Ball::setVelocityX(float velocityX)
{
    m_velocityX = velocityX;
}

void Ball::setVelocityY(float velocityY)
{
    m_velocityY = velocityY;
}
