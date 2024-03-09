

#include "optionsScreen.h"

#include <iostream>

OptionsScreen::OptionsScreen(sf::RenderWindow &window, std::shared_ptr<Paddle> &paddle1, std::shared_ptr<Paddle> &paddle2, std::shared_ptr<Ball> &ball, std::shared_ptr<CommandHandler> &commendHandler) : m_paddle1(paddle1), m_paddle2(paddle2), m_ball(ball), m_commandHandler(commendHandler)
{
    std::cout << "in OptionsScreen constructor\n";
    createScreen(window);
}
// {

//     std::cout << "in OptionsScreen constructor\n";
//     createScreen(window);
// }

void OptionsScreen::createScreen(sf::RenderWindow &window)
{
    if (m_paddle1 == nullptr || m_paddle2 == nullptr || m_ball == nullptr)
    {
        throw std::invalid_argument("Paddle or ball is null");
    }

    std::cout << "in OptionsScreen::init\n";

    // sf::Font font;
    if (!m_font.loadFromFile("sprites/GreatVibes.otf"))
    {
        throw std::invalid_argument("Failed to load font");
        std::cout << "Failed to load font" << std::endl;
    }
    sf::Text text;
    text.setFont(m_font); // Set the font

    text.setCharacterSize(50);           // Set the character size in pixels
    text.setFillColor(sf::Color::White); // Set the text color
    text.setPosition(300, 400);          // Set the position of the text in the window

    // menu

    // std::vector<sf::Text> menuItems;

    std::vector<std::string> titles = {"Game Speed"};
    sf::Text item;
    for (int i = 0; i < titles.size(); ++i)
    {

        item.setFont(m_font);
        item.setString(titles[i]);
        item.setCharacterSize(30);
        item.setFillColor(sf::Color::White);
        item.setPosition(350.f, 200.f + i * 50); // Adjust as needed
        m_menuItems.push_back(item);
    }

    item.setFont(m_font);
    item.setString("press esc for main menu");
    item.setPosition(250.f, 500.f); // Adjust as needed
    m_menuItems.push_back(item);
}

void OptionsScreen::handleInput(sf::RenderWindow &window, std::string &currentScreen)
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
            if (m_event.key.code == sf::Keyboard::Up)
            {
                //  handleCommand(CommandType::INCREASESPEED, m_paddle1.get());
                //  handleCommand(CommandType::INCREASESPEED, m_paddle2.get());
                handleCommand(CommandType::INCREASESPEED, m_ball.get(), m_paddle1.get(), m_paddle2.get());
                //  m_speed *= 1.5;
                std::cout << "speed increased\n";
                break;
            }

            if (m_event.key.code == sf::Keyboard::Escape)
            {
                currentScreen = "MenuScreen";
                break;
            }
        }
    }
}

void OptionsScreen::draw(sf::RenderWindow &window)
{

    std::cout << "in OptionsScreen::draw\n";
    // Clear the window
    window.clear();

    // Draw menu items
    for (auto &item : m_menuItems)
    {
        window.draw(item);
    }

    // Display the contents of the window
    window.display();
}

// void OptionsScreen::handleOnput(sf::RenderWindow &window, std::function<void(std::any)> callBack)
// {
//     std::cout << "in OptionsScreen::handleOnput\n";
//     std::cout << "in OptionsScreen::uhandleInput\n";
//     while (window.pollEvent(m_event))
//     {
//         std::cout << "in pollevent\n";
//         if (m_event.type == sf::Event::Closed)
//         {
//             window.close();
//         }

//         if (m_event.type == sf::Event::KeyPressed)
//         {
//             std::cout << "in keypressed\n";
//             if (m_event.key.code == sf::Keyboard::Up)
//             {
//                 // handleCommand(CommandType::MOVEUP, m_paddle1.get());
//             }

//             if (m_event.key.code == sf::Keyboard::Escape)
//             {
//                 // currentScreen = "OptionsScreen";
//                 break;
//             }
//         }
//     }
// }