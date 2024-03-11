
#include "singlePlayerScreen.h"

SinglePlayerScreen::SinglePlayerScreen(sf::RenderWindow &window, std::shared_ptr<Paddle> &paddle1, std::shared_ptr<Paddle> &paddle2, std::shared_ptr<Ball> &ball,
                                       std::shared_ptr<CommandHandler> &commandHandler)
    : GameScreen(window, paddle1, paddle2, ball, commandHandler)
{
    std::cout << "in gameScreen constructor\n";

    m_scoreItems[0] = sf::Text("0", m_font);
    m_scoreItems[0] = sf::Text("0", m_font);
    m_scoreItems[0].setPosition(470.f, 30.f);
    m_scoreItems[1].setPosition(570.f, 30.f);
}

void SinglePlayerScreen::handleInput(sf::RenderWindow &window, std::function<void(const std::string &)> switchScreenCallback)
{
    if (m_paddle1 == nullptr || m_paddle2 == nullptr || m_ball == nullptr)
    {
        throw std::invalid_argument("Paddle or ball is null");
    }

    std::cout << "in SinglePlayerScreen::handleInput\n";
    while (window.pollEvent(m_event))
    {
        std::cout << "in pollevent\n";
        if (m_event.type == sf::Event::Closed)
        {
            window.close();
        }

        if (m_event.type == sf::Event::KeyPressed)
        {
            std::cout << "in keypressed\n";
            if (m_event.key.code == sf::Keyboard::W)
            {
                handleCommand(CommandType::MOVEUP, m_paddle1);
            }
            if (m_event.key.code == sf::Keyboard::S)
            {
                handleCommand(CommandType::MOVEDOWN, m_paddle1);
            }
            if (m_event.key.code == sf::Keyboard::Escape)
            {
                switchScreenCallback("MenuScreen");
            }
        }
    }

    handleCommand(CommandType::MOVE, m_ball);
    handleBallOffScreen(window, switchScreenCallback);
    handlePaddle2(window);
}

void SinglePlayerScreen::handlePaddle2(sf::RenderWindow &window)
{
    if (m_paddle1 == nullptr || m_paddle2 == nullptr || m_ball == nullptr)
    {
        throw std::invalid_argument("Paddle or ball is null");
    }

    if (m_ball->getPosition().x > window.getSize().x / 2)
    {
        if (m_ball->getPosition().y < m_paddle2->getPosition().y)
        {
            handleCommand(CommandType::MOVEUP, m_paddle2);
        }
        else if (m_ball->getPosition().y > m_paddle2->getPosition().y)
        {
            handleCommand(CommandType::MOVEDOWN, m_paddle2);
        }
    }
}
