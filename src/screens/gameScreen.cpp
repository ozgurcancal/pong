

#include "gameScreen.h"
#include <thread>
#include <chrono>

GameScreen::GameScreen(sf::RenderWindow &window, std::shared_ptr<Paddle> &paddle1, std::shared_ptr<Paddle> &paddle2, std::shared_ptr<Ball> &ball, std::shared_ptr<CommandHandler> &commendHandler) : m_paddle1(paddle1.get()), m_paddle2(paddle2.get()), m_ball(ball.get()), m_commandHandler(commendHandler.get())
{
    std::cout << "in gameScreen constructor\n";

    m_scoreItems.push_back(sf::Text("0", m_font));
    m_scoreItems.push_back(sf::Text("0", m_font));
    m_scoreItems[0].setPosition(470.f, 30.f);
    m_scoreItems[1].setPosition(570.f, 30.f);
}

void GameScreen::refreshScreen(sf::RenderWindow &window)
{
    m_ball->reset(window);
}

void GameScreen::handleInput(sf::RenderWindow &window, std::function<void(const std::string &)> switchScreenCallback)
{
    if (m_paddle1 == nullptr || m_paddle2 == nullptr || m_ball == nullptr)
    {
        throw std::invalid_argument("Paddle or ball is null");
    }

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

void GameScreen::draw(sf::RenderWindow &window)
{
    std::cout << "in draw\n";
    window.clear();
    window.draw(m_paddle1->getSprite());
    window.draw(m_paddle2->getSprite());
    window.draw(m_ball->getSprite());
    drawScore(window);
    window.display();

    std::this_thread::sleep_for(std::chrono::milliseconds(5));
    handleCollision(m_paddle1->getSprite(), m_paddle2->getSprite(), m_ball->getSprite(), window);
}

void GameScreen::handleBallOffScreen(sf::RenderWindow &window, std::function<void(const std::string &)> &switchScreenCallback)
{
    if (m_ball->getSprite().getPosition().x < 0)
    {
        m_ScoreY++;
        refreshScreen(window);
    }
    else if (m_ball->getSprite().getPosition().x > 800)
    {
        m_ScoreX++;
        refreshScreen(window);
    }
    else if (m_ScoreX == 5 || m_ScoreY == 5)
    {
        m_ScoreX = 0;
        m_ScoreY = 0;
        switchScreenCallback("GameOverScreen");
    }

    m_scores[0] = std::to_string(m_ScoreX);
    m_scores[1] = std::to_string(m_ScoreY);
    sf::Text item;

    for (int i = 0; i < m_scores.size(); ++i)
    {
        item.setFont(m_font);
        item.setString(m_scores[i]);
        item.setCharacterSize(50);
        item.setFillColor(sf::Color::White);
        item.setPosition(window.getSize().x / 2 - 75 + (150 * i), 30.f);
        m_scoreItems[i] = item;
    }
}

void GameScreen::drawScore(sf::RenderWindow &window)
{

    for (auto &item : m_scoreItems)
    {
        window.draw(item);
    }
}

void GameScreen::handleCollision(sf::Sprite &spritePaddle1, sf::Sprite &spritePaddle2, sf::Sprite &spriteBall, sf::RenderWindow &window)
{

    sf::FloatRect rectSprite1 = spritePaddle1.getGlobalBounds();
    sf::FloatRect rectSprite2 = spritePaddle2.getGlobalBounds();
    sf::FloatRect rectBall = spriteBall.getGlobalBounds();

    // Reverse the ball's X direction when it collides with one of the paddles
    if (rectBall.intersects(rectSprite1))
    {
        m_ball->setVelocityX(m_ball->getVelocityX() * -1);
    }
    else if (rectBall.intersects(rectSprite2))
    {
        m_ball->setVelocityX(m_ball->getVelocityX() * -1);
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
        std::cout << "collision with upper boundary detected\n";
        spritePaddle1.move(0, MOVE_DISTANCE);
        drawBounce();
    }
    else if (rectSprite1.top + rectSprite1.height >= BOUNDRY_BOTTOM)
    {
        std::cout << "collision with lower boundary detected\n";
        spritePaddle1.move(0, -MOVE_DISTANCE);
        drawBounce();
    }

    if (rectSprite2.top <= BOUNDRY_TOP)
    {
        std::cout << "collision with upper boundary detected\n";
        spritePaddle2.move(0, MOVE_DISTANCE);
        drawBounce();
    }
    else if (rectSprite2.top + rectSprite2.height >= BOUNDRY_BOTTOM)
    {
        std::cout << "collision with lower boundary detected\n";
        spritePaddle2.move(0, -MOVE_DISTANCE);
        drawBounce();
    }
}
