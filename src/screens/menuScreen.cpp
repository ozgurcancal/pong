
#include "menuScreen.h"

#include <iostream>
#include <thread>
#include <chrono>

MenuScreen::MenuScreen(sf::RenderWindow &window)
{
    // uniq
    createScreen(window);
}

void MenuScreen::createScreen(sf::RenderWindow &window)
{
    std::cout << "in MenuScreen::init\n";

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

    std::vector<std::string> titles = {"Start", "Options", "Exit"};
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
    item.setString("press any key to continue");
    item.setPosition(250.f, 500.f); // Adjust as needed
    m_menuItems.push_back(item);
}

void MenuScreen::handleInput(sf::RenderWindow &window, std::string &currentScreen)
{
    std::cout << "in MenuScreen::uhandleInput\n";
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
            if (m_event.key.code == sf::Keyboard::Num1)
            {

                currentScreen = "GameScreen";
                break;
            }
            if (m_event.key.code == sf::Keyboard::Num2)
            {
                // switch screen
                currentScreen = "OptionsScreen";
                break;
            }
            if (m_event.key.code == sf::Keyboard::Escape)
            {
                window.close();
            }
        }
    }
}

void MenuScreen::draw(sf::RenderWindow &window)
{

    std::cout << "in MenuScreen::draw\n";
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