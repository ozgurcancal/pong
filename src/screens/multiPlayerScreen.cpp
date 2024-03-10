
#include "multiPlayerScreen.h"

MultiPlayerScreen::MultiPlayerScreen(sf::RenderWindow &window, std::shared_ptr<Paddle> &paddle1, std::shared_ptr<Paddle> &paddle2, std::shared_ptr<Ball> &ball,
                                     std::shared_ptr<CommandHandler> &commandHandler)
    : GameScreen(window, paddle1, paddle2, ball, commandHandler)
{
    std::cout << "in gameScreen constructor\n";

    m_scoreItems.push_back(sf::Text("0", m_font));
    m_scoreItems.push_back(sf::Text("0", m_font));
    m_scoreItems[0].setPosition(470.f, 30.f);
    m_scoreItems[1].setPosition(570.f, 30.f);
}