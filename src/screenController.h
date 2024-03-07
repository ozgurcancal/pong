

#ifndef SCREENCONTROLLER_H
#define SCREENCONTROLLER_H

#include "commands/commandHandler.h"
#include "component.h"
#include "gameObjects/gameObjectFactory.h"

class ScreenController {

public:
    ScreenController(sf::RenderWindow& window);

    void updateScreen(sf::RenderWindow& window);
    void draw(sf::RenderWindow& window);
    void menu(sf::RenderWindow& window);

private:
   // map <string, unique_ptr<Screen>> m_Screens;






    sf::Event m_event;
    CommandHandler m_commandHandler;
    GameObjectFactory m_gameObjectFactory;
    std::unique_ptr<Paddle> m_paddle1, m_paddle2;
    std::unique_ptr<Ball> m_ball;

    void handleCollision(sf::Sprite& ps1, sf::Sprite& ps2, sf::Sprite& pb, sf::RenderWindow& window);

    template <typename T>
    void handleCommand(CommandType command, T* component)
    {
        auto cmd = m_commandHandler.createNew(command, component);
        cmd->execute();
        if(cmd == nullptr){
            throw std::invalid_argument("Command is null");
        }
    }


};

#endif // SCREENCONTROLLER_H