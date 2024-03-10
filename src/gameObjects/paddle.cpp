
#include "paddle.h"

#include <iostream> // std::std::cout icin eklendi

Paddle::Paddle(sf::Texture &paddleTexture, PaddleType type)
{
    if (type == PaddleType::Blue)
    {
        // Load the paddle texture from file
        if (!paddleTexture.loadFromFile("sprites/paddle1.png"))
        {
            std::cerr << "Failed to load paddle texture" << std::endl;
            throw "Failed to load paddle texture";
        }
        else
        {
            std::cout << "Paddle texture1 loaded" << std::endl;
        }
    }
    else if (type == PaddleType::Red)
    {
        // Load the paddle texture from file
        if (!paddleTexture.loadFromFile("sprites/paddle2.png"))
        {
            std::cerr << "Failed to load paddle texture" << std::endl;
            throw "Failed to load paddle texture";
        }
        else
        {
            std::cout << "Paddle texture2 loaded" << std::endl;
        }
    }
    else
    {
        std::cerr << "Invalid paddle type" << std::endl;
        throw "Invalid paddle type";
    }

    m_sprite.setTexture(paddleTexture);
}

sf::Sprite &Paddle::getSprite()
{
    return m_sprite;
}

void Paddle::moveUp()
{
    m_sprite.move(0, -m_velocity);
    std::cout << "Paddle moved up" << std::endl;
}

void Paddle::moveDown()
{
    m_sprite.move(0, m_velocity);
    std::cout << "Paddle moved down" << std::endl;
}

void Paddle::setSpeed(float inSpeed)
{
    m_velocity = inSpeed * m_initialSpeed;
}

sf::Vector2f Paddle::getPosition() const
{
    return m_sprite.getPosition();
}

void Paddle::setPosition(const sf::RenderWindow &window, PaddlePosition position)
{
    // Set the position of the paddle to either the left or right side of the screen
    if (position == PaddlePosition::Left)
    {
        // The x position is the margin from the left edge
        float posX = m_margin;

        // Center the sprite vertically within the window
        float posY = (window.getSize().y / 2.0f) - (m_sprite.getLocalBounds().height / 2.0f);

        m_sprite.setPosition(posX, posY);
    }
    else if (position == PaddlePosition::Right)
    {
        // Adjust posX for the right paddle
        float posX = window.getSize().x - m_sprite.getLocalBounds().width - m_margin;

        // Center the sprite vertically within the window
        float posY = (window.getSize().y / 2.0f) - (m_sprite.getLocalBounds().height / 2.0f);

        m_sprite.setPosition(posX, posY);
    }
    else
    {
        std::cerr << "Invalid paddle position" << std::endl;
        throw "Invalid paddle position";
    }
}
