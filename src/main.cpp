
#include "gameEngine.h"

int main()
{
    GameEngine gameController;
    gameController.run();

    return 0;
}

// while (window.isOpen()) {
//     sf::Event event;
//     while (window.pollEvent(event)) {
//         if (event.type == sf::Event::Closed)
//             window.close();
//     }

//     // Check for parallel key presses
//     bool isWPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::W);
//     bool isAPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::A);
//     bool isSPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::S);
//     bool isDPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::D);

//     // Example action based on key presses
//     if (isWPressed) {
//         // Move up
//     }
//     if (isAPressed) {
//         // Move left
//     }
//     if (isSPressed) {
//         // Move down
//     }
//     if (isDPressed) {
//         // Move right
//     }

//     // Other game logic...

//     window.display();
// }