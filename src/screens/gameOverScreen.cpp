
#include "gameOverScreen.h"

GameOverScreen::GameOverScreen(sf::RenderWindow &window)
{
    m_menuItems.push_back(sf::Text("Game Over", m_font, 50));
    m_menuItems.push_back(sf::Text("Press Enter to go to Menu", m_font, 25));
    m_menuItems.push_back(sf::Text("Press Esc to Exit", m_font, 25));
    m_menuItems[0].setPosition(150, 100);
    m_menuItems[1].setPosition(200, 300);
    m_menuItems[2].setPosition(200, 400);
}

void GameOverScreen::refreshScreen(sf::RenderWindow &window)
{
}

void GameOverScreen::handleInput(sf::RenderWindow &window, std::function<void(const std::string &)> switchScreenCallback)
{
    while (window.pollEvent(m_event))
    {
        if (m_event.type == sf::Event::Closed)
        {
            window.close();
        }
        if (m_event.type == sf::Event::KeyPressed)
        {
            if (m_event.key.code == sf::Keyboard::Enter)
            {
                switchScreenCallback("MenuScreen");
            }
            else if (m_event.key.code == sf::Keyboard::Escape)
            {
                window.close();
            }
        }
    }
}

void GameOverScreen::draw(sf::RenderWindow &window)
{
    window.clear();

    for (auto &item : m_menuItems)
    {
        window.draw(item);
    }

    window.display();
}