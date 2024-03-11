
#include "paddle.h"

#include <iostream>

Paddle::Paddle(sf::Texture &paddleTexture, PaddleType type)
{
    if (type == PaddleType::BLUE)
    {
        m_type = PaddleType::BLUE;
        // Load the paddle texture from file
        if (!paddleTexture.loadFromFile("assets/paddle1.png"))
        {
            std::cerr << "Failed to load paddle texture" << std::endl;
            throw "Failed to load paddle texture";
        }
        else
        {
            m_sprite.setScale(INITIAL_PADDLE_SIZE, INITIAL_PADDLE_SIZE);
        }
    }
    else if (type == PaddleType::RED)
    {
        m_type = PaddleType::RED;
        // Load the paddle texture from file
        if (!paddleTexture.loadFromFile("assets/paddle2.png"))
        {
            std::cerr << "Failed to load paddle texture" << std::endl;
            throw "Failed to load paddle texture";
        }
        else
        {
            m_sprite.setScale(INITIAL_PADDLE_SIZE, INITIAL_PADDLE_SIZE);
        }
    }
    else
    {
        std::cerr << "Invalid paddle type" << std::endl;
        throw "Invalid paddle type";
    }

    m_sprite.setTexture(paddleTexture);
}

void Paddle::reset(const sf::RenderWindow &window)
{
    if (m_type == PaddleType::BLUE)
        setPosition(window, PaddlePosition::LEFT);
    else if (m_type == PaddleType::RED)
        setPosition(window, PaddlePosition::RIGHT);
}

sf::Sprite &Paddle::getSprite()
{
    return m_sprite;
}

void Paddle::moveUp()
{
    m_sprite.move(0, -m_velocity);
}

void Paddle::moveDown()
{
    m_sprite.move(0, m_velocity);
}

void Paddle::setSpeed(int inSpeed)
{
    m_velocity = inSpeed * INITIAL_SPEED;
}

void Paddle::setDifficulty(int inDifficulty)
{
    // reset size of paddle
    if (inDifficulty == 1)
    {
        m_sprite.setScale(INITIAL_PADDLE_SIZE * 2, INITIAL_PADDLE_SIZE * 2);
    }
    else if (inDifficulty == 2)
    {
        m_sprite.setScale(INITIAL_PADDLE_SIZE, INITIAL_PADDLE_SIZE);
    }
    else if (inDifficulty == 3)
    {
        m_sprite.setScale(INITIAL_PADDLE_SIZE / 2, INITIAL_PADDLE_SIZE / 2);
    }
    else
    {
        std::cerr << "Invalid difficulty" << std::endl;
        throw "Invalid difficulty";
    }
}

sf::Vector2f Paddle::getPosition() const
{
    return m_sprite.getPosition();
}

void Paddle::setPosition(const sf::RenderWindow &window, PaddlePosition position)
{
    // Set the position of the paddle to either the left or right side of the screen
    if (position == PaddlePosition::LEFT)
    {
        // The x position is the margin from the left edge
        float posX = MARGIN;

        // Center the sprite vertically within the window
        float posY = (window.getSize().y / 2.0f) - (m_sprite.getLocalBounds().height / 2.0f);

        m_sprite.setPosition(posX, posY);
    }
    else if (position == PaddlePosition::RIGHT)
    {
        // Adjust posX for the right paddle
        float posX = window.getSize().x - m_sprite.getLocalBounds().width - MARGIN;

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
