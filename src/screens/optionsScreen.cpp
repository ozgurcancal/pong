

#include "optionsScreen.h"

#include <iostream>

OptionsScreen::OptionsScreen(sf::RenderWindow &window, std::shared_ptr<Paddle> &paddle1, std::shared_ptr<Paddle> &paddle2, std::shared_ptr<Ball> &ball, std::shared_ptr<CommandHandler> &commendHandler) : m_paddle1(paddle1), m_paddle2(paddle2), m_ball(ball), m_commandHandler(commendHandler)
{
    std::cout << "in OptionsScreen constructor\n";
    m_menuItems =
        {
            {"GameSpeed", std::make_pair(sf::Text("Game Speed", m_font, 25), sf::Vector2f(100.0f, 200.0f))},
            {"Slow", std::make_pair(sf::Text("1- Slow", m_font, 22), sf::Vector2f(300.0f, 200.0f))},
            {"Moderate", std::make_pair(sf::Text("2- Moderate", m_font, 22), sf::Vector2f(450.0f, 200.0f))},
            {"Fast", std::make_pair(sf::Text("3- Fast", m_font, 22), sf::Vector2f(600.0f, 200.0f))}};

    refreshScreen(window);

    // Create a circle shape to act as the marker
    m_marker.setRadius(5);
    m_marker.setFillColor(sf::Color::Red);
    m_marker.setPosition(m_menuItems["Moderate"].second);
}

void OptionsScreen::refreshScreen(sf::RenderWindow &window)
{
    if (m_paddle1 == nullptr || m_paddle2 == nullptr || m_ball == nullptr)
    {
        throw std::invalid_argument("Paddle or ball is null");
    }

    std::cout << "in OptionsScreen::init\n";

    // std::vector<sf::Text> menuItems;
    // sf::Text txt("Game Speed", m_font, 25);
    // txt.setPosition(100, 200);

    // //  m_menuItems.push_back(txt);

    // std::vector<std::string> titles = {"1-Slow", "2-Moderate", "3-Fast"};
    // sf::Text item;
    // for (int i = 0; i < titles.size(); ++i)
    // {
    //     item.setFont(m_font);
    //     item.setString(titles[i]);
    //     item.setCharacterSize(22);
    //     item.setFillColor(sf::Color::White);
    //     item.setPosition(350.f + i * 150, 200.f); // Adjust as needed
    //                                               // m_menuItems.push_back(item);
    // }

    // item.setFont(m_font);
    // item.setString("press esc for main menu");
    // item.setPosition(250.f, 500.f); // Adjust as needed
    //                                 //  m_menuItems.push_back(item);
}

void OptionsScreen::handleInput(sf::RenderWindow &window, std::function<void(const std::string &)> switchScreenCallback)
{
    std::cout << "in OptionsScreen::uhandleInput\n";
    while (window.pollEvent(m_event))
    {
        std::cout << "in pollevent\n";
        if (m_event.type == sf::Event::Closed)
        {
            window.close();
        }

        if (m_event.type == sf::Event::KeyPressed)
        {
            if (m_event.key.code == sf::Keyboard::Num1)
            {
                handleCommand(CommandType::SETSPEED, 1, m_ball.get(), m_paddle1.get(), m_paddle2.get());
                std::cout << "speed decreased\n";
                m_marker.setPosition(m_menuItems["Slow"].second);
                // switchScreenCallback("MenuScreen");
                break;
            }

            if (m_event.key.code == sf::Keyboard::Num2)
            {
                handleCommand(CommandType::SETSPEED, 2, m_ball.get(), m_paddle1.get(), m_paddle2.get());
                std::cout << "speed set to moderate\n";
                m_marker.setPosition(m_menuItems["Moderate"].second);
                // switchScreenCallback("MenuScreen");
                break;
            }

            if (m_event.key.code == sf::Keyboard::Num3)
            {
                handleCommand(CommandType::SETSPEED, 3, m_ball.get(), m_paddle1.get(), m_paddle2.get());
                std::cout << "speed increased\n";
                m_marker.setPosition(m_menuItems["Fast"].second);
                // switchScreenCallback("MenuScreen");
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

    std::cout << "in OptionsScreen::draw\n";
    window.clear();

    // Draw menu items
    for (auto &item : m_menuItems)
    {
        auto txt = item.second.first;
        txt.setPosition(item.second.second);
        window.draw(txt);
        window.draw(m_marker);
    }

    window.display();
}

void OptionsScreen::highlightMenuItem(float x, float y)
{
    // Create a circle shape to act as the marker
    // 10 is the radius of the circle
    m_marker.setFillColor(sf::Color::Red); // Set the marker's color
    m_marker.setPosition(x, y);            // Position it centered around (300, 200)
}