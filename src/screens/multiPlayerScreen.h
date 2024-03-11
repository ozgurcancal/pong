
#ifndef MULTI_PLAYER_SCREEN_H
#define MULTI_PLAYER_SCREEN_H

#include "gameScreen.h"

class MultiPlayerScreen final : public GameScreen
{

public:
    MultiPlayerScreen(sf::RenderWindow &window, std::shared_ptr<Paddle> &paddle1, std::shared_ptr<Paddle> &paddle2, std::shared_ptr<Ball> &ball,
                      std::shared_ptr<CommandHandler> &commandHandler);

    // void refreshScreen(sf::RenderWindow &window) override;
    void handleInput(sf::RenderWindow &window, std::function<void(const std::string &)> switchScreenCallback) override;
    // void draw(sf::RenderWindow &window) override;

private:
    // sf::Event m_event;
    // std::vector<sf::Text> m_menuItems;
};

#endif // MULTI_PLAYER_SCREEN_H