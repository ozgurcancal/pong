#include <SFML/Graphics.hpp>
#include "inputHandler.h"
#include "commands/moveUp.h"
#include "commands/moveDown.h"
#include <iostream>

using namespace std;

int main()
{
    Paddle paddle;
    MoveUp moveUp(&paddle);
    MoveDown moveDown(&paddle);

    InputHandler inputHandler(&moveUp, &moveDown);

    sf::Window window(sf::VideoMode(800, 600), "Pong Game");

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {

            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::KeyPressed) {
                
                if (event.key.code == sf::Keyboard::W) {
                    inputHandler.onPressW();
                }
                if (event.key.code == sf::Keyboard::S) {
                    inputHandler.onPressS();
                }
                if (event.key.code == sf::Keyboard::Escape) {
                    window.close();
                }
            }
        }

        // Game logic and rendering here
    }
    return 0;

}
