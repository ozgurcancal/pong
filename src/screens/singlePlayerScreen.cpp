
#include "singlePlayerScreen.h"

#include <thread>
#include <chrono>
#include <cmath> // Include cmath for fmod

SinglePlayerScreen::SinglePlayerScreen(sf::RenderWindow &window, std::shared_ptr<Paddle> &paddle1, std::shared_ptr<Paddle> &paddle2, std::shared_ptr<Ball> &ball,
                                       std::shared_ptr<CommandHandler> &commandHandler)
    : GameScreen(window, paddle1, paddle2, ball, commandHandler)
{
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

    // Only try to move paddle2 if the ball is on the right half of the screen and moving right
    if (m_ball->getPosition().x > window.getSize().x / 2)
    {

        if (!m_willFail)
        {
            if (m_ball->getPosition().y < m_paddle2->getPosition().y)
            {
                handleCommand(CommandType::MOVEUP, m_paddle2);
            }
            else if (m_ball->getPosition().y > m_paddle2->getPosition().y + m_paddle2->getSprite().getGlobalBounds().height)
            {
                handleCommand(CommandType::MOVEDOWN, m_paddle2);
            }
        }
        else
        {
            // implement behavior for when the AI decides to fail
        }
    }
}

void SinglePlayerScreen::handleCollision(sf::Sprite &spritePaddle1, sf::Sprite &spritePaddle2, sf::Sprite &spriteBall, sf::RenderWindow &window)
{

    sf::FloatRect rectSprite1 = spritePaddle1.getGlobalBounds();
    sf::FloatRect rectSprite2 = spritePaddle2.getGlobalBounds();
    sf::FloatRect rectBall = spriteBall.getGlobalBounds();

    // Reverse the ball's X direction when it collides with one of the paddles
    if (rectBall.intersects(rectSprite1))
    {
        m_ball->setVelocityX(m_ball->getVelocityX() * -1);

        float paddle2CenterY = m_paddle2->getPosition().y + m_paddle2->getSprite().getGlobalBounds().height / 2;

        // calculate final position of the ball
        sf::Vector2f ballVelocity = m_ball->getVelocity();
        float timeToReachPaddle = (window.getSize().x - m_ball->getPosition().x) / ballVelocity.x;
        m_finalBallPositionY = std::fmod((m_ball->getPosition().y + ballVelocity.y * timeToReachPaddle), window.getSize().y);

        m_deltaY = m_finalBallPositionY - paddle2CenterY;
        if (abs(m_deltaY) > window.getSize().y / 2)
        {
            m_willFail = true;
        }
        else
        {
            m_willFail = false;
        }
    }
    else if (rectBall.intersects(rectSprite2))
    {
        m_ball->setVelocityX(m_ball->getVelocityX() * -1);
        m_willFail = false;
    }

    auto drawBounce = [&spritePaddle1, &spritePaddle2, &window]()
    {
        window.clear();
        window.draw(spritePaddle1);
        window.draw(spritePaddle2);
        window.display();
    };

    // create a bounce
    if (rectSprite1.top <= BOUNDRY_TOP)
    {
        spritePaddle1.move(0, MOVE_DISTANCE);
        drawBounce();
    }
    else if (rectSprite1.top + rectSprite1.height >= BOUNDRY_BOTTOM)
    {
        spritePaddle1.move(0, -MOVE_DISTANCE);
        drawBounce();
    }

    if (rectSprite2.top <= BOUNDRY_TOP)
    {
        spritePaddle2.move(0, MOVE_DISTANCE);
        drawBounce();
    }
    else if (rectSprite2.top + rectSprite2.height >= BOUNDRY_BOTTOM)
    {
        spritePaddle2.move(0, -MOVE_DISTANCE);
        drawBounce();
    }
}
