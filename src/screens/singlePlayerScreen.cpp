
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
        // eger paddle in suan ki pozisyonu ile topun final pozisyonu arasinda ki mesafe ekran boyunun yarisindan buyukse
        if (m_paddle2->getPosition().y - m_finalBallPositionY > window.getSize().y / 3 && m_finalBallPositionY)
        {
            std::cout << "m_paddle2->getPosition().y " << m_paddle2->getPosition().y << "\n";
            std::cout << "m_finalBallPositionY = " << m_finalBallPositionY << "\n";
            if (m_finalBallPositionY - 10 > m_paddle2->getPosition().y)
                handleCommand(CommandType::MOVEDOWN, m_paddle2);
        }
        else if (m_ball->getPosition().y < m_paddle2->getPosition().y)
        {
            handleCommand(CommandType::MOVEUP, m_paddle2);
        }
        else if (m_ball->getPosition().y > m_paddle2->getPosition().y)
        {
            handleCommand(CommandType::MOVEDOWN, m_paddle2);
        }
    }
}
// void GameScreen::handleBallOffScreen(sf::RenderWindow &window, std::function<void(const std::string &)> &switchScreenCallback)
// {
//     std::cout << "in handleBallOffScreen\n";
//     if (m_ball->getSprite().getPosition().x < 0)
//     {
//         m_ScoreY++;
//         std::cout << "before refresh\n";
//         refreshScreen(window);
//     }
//     else if (m_ball->getSprite().getPosition().x > 800)
//     {
//         m_ScoreX++;
//         std::cout << "before refresh\n";
//         refreshScreen(window);
//     }
//     else if (m_ScoreX == 5 || m_ScoreY == 5)
//     {
//         m_ScoreX = 0;
//         m_ScoreY = 0;
//         std::cout << "before callback\n";
//         switchScreenCallback("GameOverScreen");
//     }

//     std::cout << "in handleBallOffScreen2\n";
//     m_scores[0] = std::to_string(m_ScoreX);
//     m_scores[1] = std::to_string(m_ScoreY);
//     sf::Text item;

//     std::cout << "m_scores.size() = " << m_scores.size() << "\n";
//     for (int i = 0; i < m_scores.size(); ++i)
//     {
//         item.setFont(m_font);
//         item.setString(m_scores[i]);
//         item.setCharacterSize(50);
//         item.setFillColor(sf::Color::White);
//         item.setPosition(window.getSize().x / 2 - 75 + (150 * i), 30.f);
//         m_scoreItems[i] = item;
//     }
//     std::cout << "in handleBallOffScreen3\n";
// }
void SinglePlayerScreen::handleCollision(sf::Sprite &spritePaddle1, sf::Sprite &spritePaddle2, sf::Sprite &spriteBall, sf::RenderWindow &window)
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
        // calculate final position of the ball
        sf::Vector2f ballVelocity = m_ball->getVelocity();
        float timeToReachPaddle = (window.getSize().x / 2 - m_ball->getPosition().x) / ballVelocity.x;
        m_finalBallPositionY = m_ball->getPosition().y + ballVelocity.y * timeToReachPaddle;

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
