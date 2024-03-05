
#ifndef PADDLE_H
#define PADDLE_H

#include <SFML/Graphics.hpp>

enum class PaddleType {
    Blue,
    Red,
};

enum class PaddlePosition {
    Left,
    Right,
};



class Paddle {
public:
    Paddle(sf::Texture& texture, PaddleType type);
    void moveUp();
    void moveDown();
    sf::Vector2f getPosition()const;
    void setPosition(const sf::RenderWindow& window, PaddlePosition position);
    sf::Sprite& getSprite();

private:
    sf::Sprite m_sprite;
   

};


#endif // PADDLE_H

