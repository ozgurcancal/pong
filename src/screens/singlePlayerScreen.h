

#ifndef SINGLE_PLAYER_SCREEN_H
#define SINGLE_PLAYER_SCREEN_H

#include "gameScreen.h"

class SinglePlayerScreen : public GameScreen
{

public:
    SinglePlayerScreen(sf::RenderWindow &window, std::shared_ptr<Paddle> &paddle1, std::shared_ptr<Paddle> &paddle2, std::shared_ptr<Ball> &ball,
                       std::shared_ptr<CommandHandler> &commandHandler);

    void handleInput(sf::RenderWindow &window, std::function<void(const std::string &)> switchScreenCallback) override;
    void handleCollision(sf::Sprite &spritePaddle1, sf::Sprite &spritePaddle2, sf::Sprite &spriteBall, sf::RenderWindow &window) override;
    // void handleBallOffScreen(sf::RenderWindow &window, std::function<void(const std::string &)> &switchScreenCallback) override;

private:
    void handlePaddle2(sf::RenderWindow &window);
    float m_finalBallPositionY;
};

#endif // SINGLE_PLAYER_SCREEN_H