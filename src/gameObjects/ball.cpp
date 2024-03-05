

#include "ball.h"

#include <iostream> // std::cout icin eklendi

Ball::Ball(sf::Texture& texture)
{
    // Load the paddle texture from file
    if (!texture.loadFromFile("sprites/ball.png")) {
        std::cerr << "Failed to load ball texture" << std::endl;
        throw "Failed to load ball texture";
    }else{
        std::cout<<"Paddle ball loaded"<<std::endl;
    
    }

    m_sprite.setTexture(texture);
}

void Ball::setPosition(const sf::RenderWindow& window)
{
        // Calculate the center position for the sprite
    float posX = (window.getSize().x / 2.0f) - (m_sprite.getLocalBounds().width / 2.0f);
    float posY = (window.getSize().y / 2.0f) - (m_sprite.getLocalBounds().height / 2.0f);

    // Set the sprite's position to the center of the window
    m_sprite.setPosition(posX, posY);

}

sf::Sprite& Ball::getSprite()
{
    return m_sprite;
}