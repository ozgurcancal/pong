

#ifndef OPTIONSSCREEN_H
#define OPTIONSSCREEN_H

#include "screen.h"
#include "commandHandler.h"
#include <map>
// #include "component.h"

class OptionsScreen : public Screen
{
public:
    OptionsScreen(sf::RenderWindow &window, std::shared_ptr<Paddle> &paddle1, std::shared_ptr<Paddle> &paddle2, std::shared_ptr<Ball> &ball, std::shared_ptr<CommandHandler> &commandHandler);
    void handleInput(sf::RenderWindow &window, std::function<void(const std::string &)> switchScreenCallback) override;
    void draw(sf::RenderWindow &window) override;

private:
    sf::Event m_event;
    std::map<std::string, std::pair<sf::Text, sf::Vector2f>> m_menuItems;

    std::shared_ptr<CommandHandler> m_commandHandler;
    std::shared_ptr<Paddle> m_paddle1, m_paddle2;
    std::shared_ptr<Ball> m_ball;

    void refreshScreen(sf::RenderWindow &window) override;

    template <typename... T>
    void handleCommand(CommandType command, float input, T *...components)
    {
        auto cmd = m_commandHandler->createNew(command, input, components...);
        cmd->execute();
        if (cmd == nullptr)
        {
            throw std::invalid_argument("Command is null");
        }
    }

    void highlightMenuItem(float x, float y);
    // Create a circle shape to act as the marker
    sf::CircleShape m_speedMarker;
    sf::CircleShape m_difficultyMarker;
};

#endif // OPTIONSSCREEN_H
