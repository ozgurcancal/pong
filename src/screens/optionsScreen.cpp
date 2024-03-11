

#include "optionsScreen.h"

OptionsScreen::OptionsScreen(sf::RenderWindow &window, std::shared_ptr<Paddle> &paddle1, std::shared_ptr<Paddle> &paddle2, std::shared_ptr<Ball> &ball, std::shared_ptr<CommandHandler> &commendHandler) : m_paddle1(paddle1), m_paddle2(paddle2), m_ball(ball), m_commandHandler(commendHandler)
{
    auto windowSize = window.getSize();
    float refX = windowSize.x * 0.125f;
    float refY = windowSize.y * 0.3333f;
    m_menuItems =
        {
            {"GameSpeed", std::make_pair(sf::Text("Game Speed", m_font, 25), sf::Vector2f(refX, refY))},
            {"Slow", std::make_pair(sf::Text("1- Slow", m_font, 22), sf::Vector2f(refX + 200.0f, refY))},
            {"Moderate", std::make_pair(sf::Text("2- Moderate", m_font, 22), sf::Vector2f(refX + 350.0f, refY))},
            {"Fast", std::make_pair(sf::Text("3- Fast", m_font, 22), sf::Vector2f(refX + 500.0f, refY))},
            {"Difficulty", std::make_pair(sf::Text("Difficulty", m_font, 25), sf::Vector2f(refX, refY + 100.0f))},
            {"Easy", std::make_pair(sf::Text("4- Easy", m_font, 22), sf::Vector2f(refX + 200.0f, refY + 100.0f))},
            {"Medium", std::make_pair(sf::Text("5- Medium", m_font, 22), sf::Vector2f(refX + 350.0f, refY + 100.0f))},
            {"Hard", std::make_pair(sf::Text("6- Hard", m_font, 22), sf::Vector2f(refX + 500.0f, refY + 100.0f))},
            {"Menu", std::make_pair(sf::Text("Press ESC to go back to menu", m_font, 22), sf::Vector2f(refX + 200.0f, refY + 300.0f))}

        };

    refreshScreen(window);

    // Create circle shapes to act as the marker
    m_speedMarker.setRadius(5);
    m_speedMarker.setFillColor(sf::Color::Red);
    m_speedMarker.setPosition(m_menuItems["Moderate"].second);

    m_difficultyMarker.setRadius(5);
    m_difficultyMarker.setFillColor(sf::Color::Red);
    m_difficultyMarker.setPosition(m_menuItems["Medium"].second);
}

void OptionsScreen::refreshScreen(sf::RenderWindow &window)
{
}

void OptionsScreen::handleInput(sf::RenderWindow &window, std::function<void(const std::string &)> switchScreenCallback)
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
            if (m_event.key.code == sf::Keyboard::Num1)
            {
                handleCommand(CommandType::SETSPEED, 1, m_ball.get(), m_paddle1.get(), m_paddle2.get());
                m_speedMarker.setPosition(m_menuItems["Slow"].second);
                break;
            }

            if (m_event.key.code == sf::Keyboard::Num2)
            {
                handleCommand(CommandType::SETSPEED, 2, m_ball.get(), m_paddle1.get(), m_paddle2.get());
                m_speedMarker.setPosition(m_menuItems["Moderate"].second);
                break;
            }

            if (m_event.key.code == sf::Keyboard::Num3)
            {
                handleCommand(CommandType::SETSPEED, 3, m_ball.get(), m_paddle1.get(), m_paddle2.get());
                m_speedMarker.setPosition(m_menuItems["Fast"].second);
                break;
            }

            if (m_event.key.code == sf::Keyboard::Num4)
            {
                handleCommand(CommandType::SETDIFFICULTY, 1, m_ball.get(), m_paddle1.get(), m_paddle2.get());
                m_difficultyMarker.setPosition(m_menuItems["Easy"].second);
                break;
            }

            if (m_event.key.code == sf::Keyboard::Num5)
            {
                handleCommand(CommandType::SETDIFFICULTY, 2, m_ball.get(), m_paddle1.get(), m_paddle2.get());
                m_difficultyMarker.setPosition(m_menuItems["Medium"].second);
                break;
            }

            if (m_event.key.code == sf::Keyboard::Num6)
            {
                handleCommand(CommandType::SETDIFFICULTY, 3, m_ball.get(), m_paddle1.get(), m_paddle2.get());
                m_difficultyMarker.setPosition(m_menuItems["Hard"].second);
                break;
            }

            if (m_event.key.code == sf::Keyboard::Escape)
            {
                switchScreenCallback("MenuScreen");
                break;
            }
        }
    }
}

void OptionsScreen::draw(sf::RenderWindow &window)
{
    window.clear();

    // Draw menu items
    for (auto &item : m_menuItems)
    {
        auto txt = item.second.first;
        txt.setPosition(item.second.second);
        window.draw(txt);
        window.draw(m_speedMarker);
        window.draw(m_difficultyMarker);
    }

    window.display();
}

void OptionsScreen::highlightMenuItem(float x, float y)
{
    // Create a circle shape to act as the marker
    // 10 is the radius of the circle
    m_speedMarker.setFillColor(sf::Color::Red); // Set the marker's color
    m_speedMarker.setPosition(x, y);            // Position it centered around (300, 200)
}