

#ifndef GAMESCREEN_H
#define GAMESCREEN_H

#include "screen.h"
#include "commandHandler.h"
#include "component.h"
#include "gameObjectFactory.h"

#include <iostream>

class GameScreen : public Screen
{

    // public:
    //     GameScreen(sf::RenderWindow& window);
    //     void init() override;
    //     void updateScreen(sf::RenderWindow& window) override;
    //     void draw(sf::RenderWindow& window) override;

public:
    GameScreen(sf::RenderWindow &window);

    void handleInput(sf::RenderWindow &window, std::string &currentScreen) override;
    void draw(sf::RenderWindow &window) override;
    void menu(sf::RenderWindow &window);

private:
    sf::Event m_event;
    CommandHandler m_commandHandler;
    GameObjectFactory m_gameObjectFactory;
    std::unique_ptr<Paddle> m_paddle1, m_paddle2;
    std::unique_ptr<Ball> m_ball;

    void createScreen(sf::RenderWindow &window) override;
    void handleCollision(sf::Sprite &ps1, sf::Sprite &ps2, sf::Sprite &pb, sf::RenderWindow &window);

    template <typename T>
    void handleCommand(CommandType command, T *component)
    {
        auto cmd = m_commandHandler.createNew(command, component);
        cmd->execute();
        if (cmd == nullptr)
        {
            throw std::invalid_argument("Command is null");
        }
    }
};

#endif // GAMESCREEN_H