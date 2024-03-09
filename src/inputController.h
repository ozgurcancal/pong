

#ifndef INPUTCONTROLLER_H
#define INPUTCONTROLLER_H

#include "commands/commandHandler.h"
#include "component.h"
#include "gameObjects/gameObjectFactory.h"
#include "screens/screenManager.h"
#include <map>

class InputController
{

public:
    InputController(sf::RenderWindow &window);

    void handleInput(sf::RenderWindow &window);
    void draw(sf::RenderWindow &window);
    void menu(sf::RenderWindow &window);

private:
    // std::map<std::string, std::unique_ptr<Screen>> m_Screens;

    // sf::Event m_event;
    CommandHandler m_commandHandler;
    // GameObjectFactory m_gameObjectFactory;
    // std::unique_ptr<Paddle> m_paddle1, m_paddle2;
    // std::unique_ptr<Ball> m_ball;
    std::unique_ptr<ScreenManager> m_screenManager;

    // void handleCollision(sf::Sprite &ps1, sf::Sprite &ps2, sf::Sprite &pb, sf::RenderWindow &window);

    // template <typename T>
    // void handleCommand(CommandType command, T *component)
    // {
    //     auto cmd = m_commandHandler.createNew(command, component);
    //     cmd->execute();
    //     if (cmd == nullptr)
    //     {
    //         throw std::invalid_argument("Command is null");
    //     }
    // }
};

#endif // INPUTCONTROLLER_H