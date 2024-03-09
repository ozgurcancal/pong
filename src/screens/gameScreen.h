

#ifndef GAMESCREEN_H
#define GAMESCREEN_H

#include "screen.h"
#include "commandHandler.h"
#include "component.h"
// #include "gameObjectFactory.h"

#include <iostream>

class GameScreen : public Screen
{

    // public:
    //     GameScreen(sf::RenderWindow& window);
    //     void init() override;
    //     void updateScreen(sf::RenderWindow& window) override;
    //     void draw(sf::RenderWindow& window) override;

public:
    GameScreen(sf::RenderWindow &window, std::shared_ptr<Paddle> &paddle1, std::shared_ptr<Paddle> &paddle2, std::shared_ptr<Ball> &ball,
               std::shared_ptr<CommandHandler> &commandHandler);

    // void handleInput(sf::RenderWindow &window, std::string &currentScreen) override;
    void handleInput(sf::RenderWindow &window, std::function<void(const std::string &)> switchScreenCallback) override;

    void draw(sf::RenderWindow &window) override;
    void menu(sf::RenderWindow &window);
    void drawScore(sf::RenderWindow &window);
    void handleScore();
    void handleBallOffScreen(sf::RenderWindow &window);

private:
    // sf::Font m_font;
    std::vector<sf::Text> m_scoreItems;
    sf::Event m_event;
    CommandHandler *m_commandHandler;
    // GameObjectFactory m_gameObjectFactory;
    Paddle *m_paddle1, *m_paddle2;
    Ball *m_ball;

    void refreshScreen(sf::RenderWindow &window);
    void handleCollision(sf::Sprite &ps1, sf::Sprite &ps2, sf::Sprite &pb, sf::RenderWindow &window);

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
};

#endif // GAMESCREEN_H