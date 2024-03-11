
#include "multiPlayerScreen.h"

MultiPlayerScreen::MultiPlayerScreen(sf::RenderWindow &window, std::shared_ptr<Paddle> &paddle1, std::shared_ptr<Paddle> &paddle2, std::shared_ptr<Ball> &ball,
                                     std::shared_ptr<CommandHandler> &commandHandler)
    : GameScreen(window, paddle1, paddle2, ball, commandHandler)
{
    m_scoreItems[0] = sf::Text("0", m_font);
    m_scoreItems[0] = sf::Text("0", m_font);
    m_scoreItems[0].setPosition(470.f, 30.f);
    m_scoreItems[1].setPosition(570.f, 30.f);
}

void MultiPlayerScreen::handleInput(sf::RenderWindow &window, std::function<void(const std::string &)> switchScreenCallback)
{
    if (m_paddle1 == nullptr || m_paddle2 == nullptr || m_ball == nullptr)
    {
        throw std::invalid_argument("Paddle or ball is null");
    }

    while (window.pollEvent(m_event))
    {
        if (m_event.type == sf::Event::Closed)
        {
            window.close();
        }

        if (m_event.type == sf::Event::KeyPressed)
        {
            if (m_event.key.code == sf::Keyboard::W)
            {
                handleCommand(CommandType::MOVEUP, m_paddle1);
            }
            if (m_event.key.code == sf::Keyboard::S)
            {
                handleCommand(CommandType::MOVEDOWN, m_paddle1);
            }
            if (m_event.key.code == sf::Keyboard::Up)
            {
                handleCommand(CommandType::MOVEUP, m_paddle2);
            }
            if (m_event.key.code == sf::Keyboard::Down)
            {
                handleCommand(CommandType::MOVEDOWN, m_paddle2);
            }
            if (m_event.key.code == sf::Keyboard::Escape)
            {
                switchScreenCallback("MenuScreen");
            }
        }
    }

    handleCommand(CommandType::MOVE, m_ball);
    handleBallOffScreen(window, switchScreenCallback);
}