

#ifndef OPTIONSSCREEN_H
#define OPTIONSSCREEN_H

#include "screen.h"
#include "commandHandler.h"
#include "component.h"

class OptionsScreen : public Screen
{

public:
    OptionsScreen(sf::RenderWindow &window, std::shared_ptr<Paddle> &paddle1, std::shared_ptr<Paddle> &paddle2, std::shared_ptr<Ball> &ball, std::shared_ptr<CommandHandler> &commandHandler);
    // void handleOnput(sf::RenderWindow &window, std::function<void(std::any)> callBack) override;
    void handleInput(sf::RenderWindow &window, std::string &currentScreen) override;
    void draw(sf::RenderWindow &window) override;

private:
    void createScreen(sf::RenderWindow &window) override;
    // Fix: Add a data type and a variable name to the declaration
    sf::Event m_event;
    std::vector<sf::Text> m_menuItems;
    sf::Font m_font;

    std::shared_ptr<CommandHandler> m_commandHandler;
    // GameObjectFactory m_gameObjectFactory;
    std::shared_ptr<Paddle> m_paddle1;
    std::shared_ptr<Paddle> m_paddle2;
    std::shared_ptr<Ball> m_ball;

    template <typename... T>
    void handleCommand(CommandType command, T *...components)
    {
        auto cmd = m_commandHandler->createNew(command, components...);
        cmd->execute();
        if (cmd == nullptr)
        {
            throw std::invalid_argument("Command is null");
        }
    }
};

#endif // OPTIONSSCREEN_H
