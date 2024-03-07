
#include "menuScreen.h"

#include <iostream>
#include <thread>
#include <chrono>

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

void MenuScreen::updateScreen(sf::RenderWindow &window)
{
    std::cout << "in MenuScreen::update\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
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

    bool keyPressed = false;
    while (window.pollEvent(m_event) || !keyPressed)
    {
        if (m_event.type == sf::Event::Closed)
        {
            window.close();
        }
        if (m_event.type == sf::Event::KeyPressed)
        {
            keyPressed = true;
            break;
        }
    }
}