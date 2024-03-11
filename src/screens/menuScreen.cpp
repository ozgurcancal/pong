
#include "menuScreen.h"

MenuScreen::MenuScreen(sf::RenderWindow &window)
{
    refreshScreen(window);
}

void MenuScreen::refreshScreen(sf::RenderWindow &window)
{
    sf::Text text;
    text.setFont(m_font);
    text.setCharacterSize(50);
    text.setFillColor(sf::Color::White);
    text.setPosition(300, 400);

    std::vector<std::string> titles = {"1- Single Player", "2- Multiplayer", "3- Options"};
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
    item.setString("press any esc to exit");
    item.setPosition(350.f, 500.f); // Adjust as needed
    m_menuItems.push_back(item);
}

void MenuScreen::handleInput(sf::RenderWindow &window, std::function<void(const std::string &)> switchScreenCallback)
{
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
                switchScreenCallback("SinglePlayerScreen");
                break;
            }
            if (m_event.key.code == sf::Keyboard::Num2)
            {
                // switch screen
                switchScreenCallback("MultiPlayerScreen");
                break;
            }
            if (m_event.key.code == sf::Keyboard::Num3)
            {
                // switch screen
                switchScreenCallback("OptionsScreen");
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
    window.clear();

    // Draw menu items
    for (auto &item : m_menuItems)
    {
        window.draw(item);
    }

    window.display();
}