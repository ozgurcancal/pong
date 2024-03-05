
#include "gameController.h"

#include <iostream>
using namespace std;

GameController::GameController(): m_window(sf::VideoMode(800, 600), "Pong Game") {

    m_paddle1 = m_gameObjectFactory.createPaddle(PaddleType::Blue);
    m_paddle2 = m_gameObjectFactory.createPaddle(PaddleType::Red);
    
    m_ball =  m_gameObjectFactory.createBall();
}

void GameController::run() {

    setup();
    while (m_window.isOpen()) {
        sf::Event event;
        while (m_window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                m_window.close();
            }

            if (event.type == sf::Event::KeyPressed) {    
                cout<<"key pressed";
                if (event.key.code == sf::Keyboard::W) {
                    cout<<"W is pressef";
                    auto cmd = m_commandHandler.createNew(CommandType::MOVEUP, m_paddle1.get());
                    if(cmd == nullptr){
                        throw std::invalid_argument("Command is null");
                    }
                    cmd->execute();
                }
                if (event.key.code == sf::Keyboard::S) {
                    auto cmd = m_commandHandler.createNew(CommandType::MOVEDOWN, m_paddle1.get());
                    cmd->execute();
                }
                if (event.key.code == sf::Keyboard::Up) {
                    auto cmd = m_commandHandler.createNew(CommandType::MOVEUP, m_paddle2.get());
                    cmd->execute();
                }
                if (event.key.code == sf::Keyboard::Down) {
                    auto cmd = m_commandHandler.createNew(CommandType::MOVEDOWN, m_paddle2.get());
                    cmd->execute();
                }
                if (event.key.code == sf::Keyboard::Escape) {
                    m_window.close();
                }
       
            }

            m_window.clear();

            
            m_window.draw(m_paddle1->getSprite());
            m_window.draw(m_paddle2->getSprite());
            m_window.draw(m_ball->getSprite());
            
            m_window.display();

            handleCollision(m_paddle1->getSprite(), m_paddle2->getSprite());
        }
    }
}

void GameController::setup(){


    setWindowPosition();

    m_paddle1->setPosition(m_window, PaddlePosition::Left);
    m_paddle2->setPosition(m_window, PaddlePosition::Right);

    m_ball->setPosition(m_window);



}

void GameController::handleCollision(sf::Sprite& sprite1, sf::Sprite& sprite2) 
{
    sf::FloatRect rect1 = sprite1.getGlobalBounds();
    sf::FloatRect rect2 = sprite2.getGlobalBounds();

    const float boundaryTop = 0;
    const float boundaryBottom = 600;
    const float moveDistance = 20;
   
    // Check if the bottom edge of the sprite has gone below the lower boundary (y = 600)
    if (rect1.top <= boundaryTop) {
        cout<<"collision with upper boundary detected\n";

        sprite1.move(0, moveDistance);

        m_window.clear();

        
        m_window.draw(sprite1);
        m_window.draw(sprite2);

        
        m_window.display();
        
    }else if (rect1.top + rect1.height >= boundaryBottom) {

        cout<<"collision with lower boundary detected\n";
        sprite1.move(0, -moveDistance);
        m_window.clear();

        
        m_window.draw(sprite1);
        m_window.draw(sprite2);

        
        m_window.display();
    }

    if(rect2.top <= boundaryTop){
        cout<<"collision with upper boundary detected\n";
        sprite2.move(0, moveDistance);
        m_window.clear();

        
        m_window.draw(sprite1);
        m_window.draw(sprite2);

        
        m_window.display();
    }else if(rect2.top + rect2.height >= boundaryBottom){
        cout<<"collision with lower boundary detected\n";
        sprite2.move(0, -moveDistance);
        m_window.clear();

        
        m_window.draw(sprite1);
        m_window.draw(sprite2);

        
        m_window.display();
    }
}

void GameController::setWindowPosition(){
    // Get the desktop mode to access the screen resolution
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();

    // Calculate the window position to center it
    unsigned int posX = (desktop.width / 2) - (m_window.getSize().x / 2);
    unsigned int posY = (desktop.height / 2) - (m_window.getSize().y / 2);

    // Set the window position
    m_window.setPosition(sf::Vector2i(posX, posY));
}
