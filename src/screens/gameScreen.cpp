

#include "gameScreen.h"
#include <thread>
#include <chrono>

GameScreen::GameScreen(sf::RenderWindow &window)
{
    std::cout << "in gameScreen constructor\n";
    createScreen(window);
}

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

void GameScreen::handleInput(sf::RenderWindow &window, std::string &currentScreen)
{
    std::cout << "in GameScreen::handleInput\n";
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
                currentScreen = "MenuScreen";
            }
        }
    }

    handleCommand(CommandType::MOVE, m_ball.get());
}

void GameScreen::draw(sf::RenderWindow &window)
{
    std::cout << "in GameScreen::draw\n";
    window.clear();
    window.draw(m_paddle1->getSprite());
    window.draw(m_paddle2->getSprite());
    window.draw(m_ball->getSprite());
    window.display();

    std::this_thread::sleep_for(std::chrono::milliseconds(15));
    handleCollision(m_paddle1->getSprite(), m_paddle2->getSprite(), m_ball->getSprite(), window);
}

void GameScreen::handleCollision(sf::Sprite &spritePaddle1, sf::Sprite &spritePaddle2, sf::Sprite &spriteBall, sf::RenderWindow &window)
{

    sf::FloatRect rectSprite1 = spritePaddle1.getGlobalBounds();
    sf::FloatRect rectSprite2 = spritePaddle2.getGlobalBounds();
    sf::FloatRect rectBall = spriteBall.getGlobalBounds();

    if (rectBall.intersects(rectSprite1))
    {

        m_ball->setVelocityX(1);
    }
    else if (rectBall.intersects(rectSprite2))
    {
        // Ball intersects with paddle2
        // You would handle this similarly to the collision with paddle1
        // This example assumes the logic is the same for both paddles

        // Reverse the ball's X direction
        m_ball->setVelocityX(-1);
    }

    // m_ball->move();

    // window.clear();

    // window.draw(spritePaddle1);
    // window.draw(spritePaddle2);

    // window.display();

    const float boundaryTop = 0;
    const float boundaryBottom = 600;
    const float moveDistance = 20;

    // Check if the bottom edge of the sprite has gone below the lower boundary (y = 600)
    if (rectSprite1.top <= boundaryTop)
    {
        std::cout << "collision with upper boundary detected\n";

        spritePaddle1.move(0, moveDistance);

        window.clear();

        window.draw(spritePaddle1);
        window.draw(spritePaddle2);

        window.display();
    }
    else if (rectSprite1.top + rectSprite1.height >= boundaryBottom)
    {

        std::cout << "collision with lower boundary detected\n";
        spritePaddle1.move(0, -moveDistance);
        window.clear();

        window.draw(spritePaddle1);
        window.draw(spritePaddle2);

        window.display();
    }

    if (rectSprite2.top <= boundaryTop)
    {
        std::cout << "collision with upper boundary detected\n";
        spritePaddle2.move(0, moveDistance);
        window.clear();

        window.draw(spritePaddle1);
        window.draw(spritePaddle2);

        window.display();
    }
    else if (rectSprite2.top + rectSprite2.height >= boundaryBottom)
    {
        std::cout << "collision with lower boundary detected\n";
        spritePaddle2.move(0, -moveDistance);
        window.clear();

        window.draw(spritePaddle1);
        window.draw(spritePaddle2);

        window.display();
    }
}