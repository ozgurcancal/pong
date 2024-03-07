

#include "gameScreen.h"

void GameScreen::createScreen(sf::RenderWindow &window)
{
    std::cout << "in createScreen\n";
    m_paddle1 = m_gameObjectFactory.createPaddle(PaddleType::Blue);
    m_paddle2 = m_gameObjectFactory.createPaddle(PaddleType::Red);
    m_ball = m_gameObjectFactory.createBall();

    m_paddle1->setPosition(window, PaddlePosition::Left);
    m_paddle2->setPosition(window, PaddlePosition::Right);

    m_ball->setPosition(window);
}

void GameScreen::updateScreen(sf::RenderWindow &window)
{
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
                handleCommand(CommandType::MOVEUP, m_paddle1.get());
            }
            if (m_event.key.code == sf::Keyboard::S)
            {
                handleCommand(CommandType::MOVEDOWN, m_paddle1.get());
            }
            if (m_event.key.code == sf::Keyboard::Up)
            {
                handleCommand(CommandType::MOVEUP, m_paddle2.get());
            }
            if (m_event.key.code == sf::Keyboard::Down)
            {
                handleCommand(CommandType::MOVEDOWN, m_paddle2.get());
            }
            if (m_event.key.code == sf::Keyboard::Escape)
            {
                window.close();
            }
        }
    }

    handleCommand(CommandType::MOVE, m_ball.get());
}

void GameScreen::draw(sf::RenderWindow &window)
{
    std::cout << "in draw\n";
    window.clear();
    window.draw(m_paddle1->getSprite());
    window.draw(m_paddle2->getSprite());
    window.draw(m_ball->getSprite());
    window.display();
}