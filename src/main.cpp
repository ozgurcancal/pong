#include <SFML/Graphics.hpp>
#include "commandHandler.h"
#include "commands/moveUp.h"
#include "commands/moveDown.h"
#include "commands/paddleFactory.h"

#include "gameController.h"
#include <iostream>

using namespace std;

int isCollidingWithUpperBoundary(sf::Sprite& sprite1, sf::Sprite& sprite2) {
    // Get the global bounding box of the sprite
    auto upperBound1 = sprite1.getGlobalBounds().top;
    auto upperBound2 = sprite2.getGlobalBounds().top;
    
    // Check if the top edge of the sprite has gone above the upper boundary (y = 0)
    if (upperBound1 <= 0) {
        return true;

    }else if (upperBound2 <= 0) {
        return true;
    }

    return false;

}

int isCollidingWithLowerBoundary(sf::Sprite& sprite1, sf::Sprite& sprite2) {
    // Get the global bounding box of the sprite
    auto lowerBound1 = sprite1.getGlobalBounds().top + sprite1.getGlobalBounds().height;
    auto lowerBound2 = sprite2.getGlobalBounds().top + sprite2.getGlobalBounds().height;
    
    // Check if the bottom edge of the sprite has gone below the lower boundary (y = 600)
    if (lowerBound1 >= 600) {
        return true;
    }else if (lowerBound2 >= 600) {
        return true;
    }

    return false;
}


int main()
{

    GameController gameController;
    gameController.run();
//     sf::Texture paddleTexture1;
//     sf::Texture paddleTexture2;

//     PaddleFactory pc;


//     CommandHandler commandHandler;

//     sf::RenderWindow window(sf::VideoMode(800, 600), "Pong Game");


//     // Get the desktop mode to access the screen resolution
//     sf::VideoMode desktop = sf::VideoMode::getDesktopMode();

//     // Calculate the window position to center it
//     unsigned int posX = (desktop.width / 2) - (window.getSize().x / 2);
//     unsigned int posY = (desktop.height / 2) - (window.getSize().y / 2);

//     // Set the window position
//     window.setPosition(sf::Vector2i(posX, posY));

//     Paddle paddle1 = pc.createPaddle(paddleTexture1, PaddleType::Blue);
//     Paddle paddle2 = pc.createPaddle(paddleTexture2, PaddleType::Red);

//     paddle1.setPosition(window, PaddlePosition::Left);
//     paddle2.setPosition(window, PaddlePosition::Right);

    
//     while (window.isOpen()) {
//         sf::Event event;
//         while (window.pollEvent(event)) {
                    
//             if (event.type == sf::Event::Closed)
//                 window.close();

//             if (event.type == sf::Event::KeyPressed) {    
//                 cout<<"key pressed";
//                 if (event.key.code == sf::Keyboard::W) {
//                 cout<<"W is pressef";
//                     std::unique_ptr cmd = commandHandler.createNew(CommandType::MOVEUP, &paddle1);
//                     if(cmd == nullptr){
//                         throw std::invalid_argument("Command is null");
//                     }
//                     cmd->execute();
//                 }
//                 if (event.key.code == sf::Keyboard::S) {
//                     auto cmd = commandHandler.createNew(CommandType::MOVEDOWN, &paddle1);
//                     cmd->execute();
//                 }
//                 if (event.key.code == sf::Keyboard::Up) {
//                     auto cmd = commandHandler.createNew(CommandType::MOVEUP, &paddle2);
//                     cmd->execute();
//                 }
//                 if (event.key.code == sf::Keyboard::Down) {
//                     auto cmd = commandHandler.createNew(CommandType::MOVEDOWN, &paddle2);
//                     cmd->execute();
//                 }
//                 if (event.key.code == sf::Keyboard::Escape) {
//                     window.close();
//                 }
       
//             }

//             window.clear();

            
//             window.draw(paddle1.getSprite());
//             window.draw(paddle2.getSprite());

            
//             window.display();

          
//             if(isCollidingWithUpperBoundary(paddle1.getSprite(), paddle2.getSprite())) {

//                 cout<<"collision with upper boundary detected\n";

//                 paddle1.getSprite().move(0, 20);

//                 window.clear();

                
//                 window.draw(paddle1.getSprite());
//                 window.draw(paddle2.getSprite());

                
//                 window.display();

//                 //bounce
//             }
//             else if(isCollidingWithLowerBoundary(paddle1.getSprite(), paddle2.getSprite())) {
//                 cout<<"collision with lower boundary detected\n";
//                 paddle1.getSprite().move(0, -20);
//                 window.clear();
// ;
            
//                 window.draw(paddle1.getSprite());
//                 window.draw(paddle2.getSprite());

                
//                 window.display();

//                 //bounce
//             }
   
//         }



//         // Game logic and rendering here
//     }
    return 0;

}
