
#ifndef MULTI_PLAYER_SCREEN_H
#define MULTI_PLAYER_SCREEN_H

#include "gameScreen.h"

class MultiPlayerScreen final : public GameScreen
{
public:
    MultiPlayerScreen(sf::RenderWindow &window, std::shared_ptr<Paddle> &paddle1, std::shared_ptr<Paddle> &paddle2, std::shared_ptr<Ball> &ball,
                      std::shared_ptr<CommandHandler> &commandHandler);

    void handleInput(sf::RenderWindow &window, std::function<void(const std::string &)> switchScreenCallback) override;

private:
};

#endif // MULTI_PLAYER_SCREEN_H