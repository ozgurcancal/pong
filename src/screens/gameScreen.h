

#ifndef GAMESCREEN_H
#define GAMESCREEN_H

#include "screen.h"
#include "commandHandler.h"

#include <iostream>

class GameScreen : public Screen
{
public:
    GameScreen(sf::RenderWindow &window, std::shared_ptr<Paddle> &paddle1, std::shared_ptr<Paddle> &paddle2, std::shared_ptr<Ball> &ball,
               std::shared_ptr<CommandHandler> &commandHandler);

    virtual void handleInput(sf::RenderWindow &window, std::function<void(const std::string &)> switchScreenCallback) = 0;
    virtual void handleCollision(sf::Sprite &spritePaddle1, sf::Sprite &spritePaddle2, sf::Sprite &spriteBall, sf::RenderWindow &window);
    void draw(sf::RenderWindow &window) override;
    void drawScore(sf::RenderWindow &window);
    void handleBallOffScreen(sf::RenderWindow &window, std::function<void(const std::string &)> &switchScreenCallback);

protected:
    std::array<sf::Text, 2> m_scoreItems;
    sf::Event m_event;
    CommandHandler *m_commandHandler;
    Paddle *m_paddle1, *m_paddle2;
    Ball *m_ball;

    void refreshScreen(sf::RenderWindow &window);

    template <typename T>
    void handleCommand(CommandType command, T *component)
    {
        auto cmd = m_commandHandler->createNew(command, component);
        cmd->execute();
        if (cmd == nullptr)
        {
            throw std::invalid_argument("Command is null");
        }
    }

    int m_ScoreX = 0;
    int m_ScoreY = 0;
    std::vector<std::string> m_scores = {"0", "0"};
    static constexpr float BOUNDRY_TOP = 0;
    static constexpr float BOUNDRY_BOTTOM = 600;
    static constexpr float MOVE_DISTANCE = 20;
};

#endif // GAMESCREEN_H