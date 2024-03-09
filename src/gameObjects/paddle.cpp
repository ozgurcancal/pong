
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
    //  m_sprite.move(0, -20); // Negative y value to move up
    std::cout << "Paddle moved up" << std::endl;
    // collision_flag = true;
}

void Paddle::moveDown()
{
    m_sprite.move(0, m_velocity);
    //  m_sprite.move(0, 20); // Negative y value to move up
    std::cout << "Paddle moved down" << std::endl;
    // Execute move down command
}

void Paddle::setSpeed(float inSpeed)
{
    m_velocity = inSpeed * 20.0f;
}

sf::Vector2f Paddle::getPosition() const
{
    return m_sprite.getPosition();
}

void Paddle::setPosition(const sf::RenderWindow &window, PaddlePosition position)
{
    // Set the position of the paddle to either the left or right side of the screen
    // sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
    if (position == PaddlePosition::Left)
    {
        float margin = 30.0f; // Margin from the left edge of the window

        // The x position is the margin from the left edge
        float posX = margin;

        // Center the sprite vertically within the window
        float posY = (window.getSize().y / 2.0f) - (m_sprite.getLocalBounds().height / 2.0f);

        m_sprite.setPosition(posX, posY);
    }
    else if (position == PaddlePosition::Right)
    {
        float margin = 30.0f;                                                       // Margin from the right edge of the window
        float posX = window.getSize().x - m_sprite.getLocalBounds().width - margin; // Adjust posX for the right paddle

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
