
#include "gameController.h"

#include <iostream>
#include <thread>
#include <mutex>
#include <atomic>
#include <chrono>

using namespace std;

GameController::GameController(): m_window(sf::VideoMode(800, 600), "Pong Game") {

    m_paddle1 = m_gameObjectFactory.createPaddle(PaddleType::Blue);
    m_paddle2 = m_gameObjectFactory.createPaddle(PaddleType::Red);
    m_ball =  m_gameObjectFactory.createBall();
}

// the three main stages of the game loop
// while (mIsRunning) {
//     ProcessInput();
//     UpdateGame();
//     GenerateOutput();
// }
void GameController::run() {

    setup();
                
   // Load a font
    sf::Font font;
    if (!font.loadFromFile("sprites/GreatVibes.otf")) {
        throw std::invalid_argument("Failed to load font");
        std::cout<<"Failed to load font"<<std::endl;
    }
                sf::Text text;
                text.setFont(font); // Set the font

                text.setCharacterSize(50); // Set the character size in pixels
                text.setFillColor(sf::Color::White); // Set the text color
                text.setPosition(300, 400); // Set the position of the text in the window

    //menu
 
        std::vector<sf::Text> menuItems;

        const std::string titles[] = {"Start", "Options", "Exit"};
        for (int i = 0; i < 3; ++i) {
            sf::Text item;
            item.setFont(font);
            item.setString(titles[i]);
            item.setCharacterSize(30);
            item.setFillColor(sf::Color::White);
            item.setPosition(350.f, 200.f + i * 50); // Adjust as needed
            menuItems.push_back(item);
        }

            // Clear the window
            m_window.clear();

            // Draw menu items
            for (auto& item : menuItems) {
                m_window.draw(item);
            }

            // Display the contents of the window
            m_window.display();

//problem with this part
    // while(std::cin.get() == 's'){
    //     cout<<"s is pressed";
    // }
    

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

        }
            
            m_window.clear();
            m_window.draw(m_paddle1->getSprite());
            m_window.draw(m_paddle2->getSprite());
            m_window.draw(m_ball->getSprite());

            m_window.display();
            std::this_thread::sleep_for(std::chrono::milliseconds(10));

 

            auto cmd = m_commandHandler.createNew(CommandType::MOVE, m_ball.get());
            cmd->execute();




           handleCollision(m_paddle1->getSprite(), m_paddle2->getSprite(), m_ball->getSprite());
            

            if(m_ball->getSprite().getPosition().x < 0 ){
                mutex m_mutex;
                std::lock_guard<mutex> lock(m_mutex);
                m_window.clear();
                text.setString("oyuncu2 tebrikssss!!!!!!!"); // Set the string to display
                m_window.draw(text);
                m_window.display();
               std::this_thread::sleep_for(std::chrono::milliseconds(2000));
               break;
            
            }else if (m_ball->getSprite().getPosition().x > 800)
            {
                mutex m_mutex;
                std::lock_guard<mutex> lock(m_mutex);
                m_window.clear();
                text.setString("oyuncu1 tebrikssss!!!!!!!"); // Set the string to display
                m_window.draw(text);
                m_window.display();
               std::this_thread::sleep_for(std::chrono::milliseconds(2000));
               break;
            }


    }
}

void GameController::setup(){


    setWindowPosition();

    m_paddle1->setPosition(m_window, PaddlePosition::Left);
    m_paddle2->setPosition(m_window, PaddlePosition::Right);

    m_ball->setPosition(m_window);



}

void GameController::handleCollision(sf::Sprite& spritePaddle1, sf::Sprite& spritePaddle2, sf::Sprite& spriteBall) 
{
    sf::FloatRect rectSprite1 = spritePaddle1.getGlobalBounds();
    sf::FloatRect rectSprite2 = spritePaddle2.getGlobalBounds();
    sf::FloatRect rectBall = spriteBall.getGlobalBounds();


    if (rectBall.intersects(rectSprite1)) {

        m_ball->setVelocityX(1);

    } else if (rectBall.intersects(rectSprite2)) {
        // Ball intersects with paddle2
        // You would handle this similarly to the collision with paddle1
        // This example assumes the logic is the same for both paddles

        // Reverse the ball's X direction
        m_ball->setVelocityX(-1);
    }


    m_ball->move();
    
        m_window.clear();

        
        m_window.draw(spritePaddle1);
        m_window.draw(spritePaddle2);

        
        m_window.display();

    const float boundaryTop = 0;
    const float boundaryBottom = 600;
    const float moveDistance = 20;
   
    // Check if the bottom edge of the sprite has gone below the lower boundary (y = 600)
    if (rectSprite1.top <= boundaryTop) {
        cout<<"collision with upper boundary detected\n";

        spritePaddle1.move(0, moveDistance);

        m_window.clear();

        
        m_window.draw(spritePaddle1);
        m_window.draw(spritePaddle2);

        
        m_window.display();
    }else if (rectSprite1.top + rectSprite1.height >= boundaryBottom) {

        cout<<"collision with lower boundary detected\n";
        spritePaddle1.move(0, -moveDistance);
        m_window.clear();

        
        m_window.draw(spritePaddle1);
        m_window.draw(spritePaddle2);

        
        m_window.display();

      
    }

    if(rectSprite2.top <= boundaryTop){
        cout<<"collision with upper boundary detected\n";
        spritePaddle2.move(0, moveDistance);
        m_window.clear();

        
        m_window.draw(spritePaddle1);
        m_window.draw(spritePaddle2);

        
        m_window.display();
     
    }else if(rectSprite2.top + rectSprite2.height >= boundaryBottom){
        cout<<"collision with lower boundary detected\n";
        spritePaddle2.move(0, -moveDistance);
        m_window.clear();

        
        m_window.draw(spritePaddle1);
        m_window.draw(spritePaddle2);

        
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
