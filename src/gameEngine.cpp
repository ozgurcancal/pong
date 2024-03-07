
#include "gameEngine.h"
#include "screenManager.h"

#include <iostream>
#include <thread>
#include <mutex>
#include <atomic>
#include <chrono>


using namespace std;

GameEngine::GameEngine(): m_window(sf::VideoMode(800, 600), "Pong Game") {

    m_screenController = std::make_unique<ScreenController>(m_window);
}

// the three main stages of the game loop
// while (mIsRunning) {
//     ProcessInput();
//     UpdateGame();
//     Draw();
// }
void GameEngine::run() {
    std::cout<<"Gameengine::run\n";
    setup();
                

   // m_screenController->menu(m_window);
   ScreenManager screenManager(m_window);


    while (m_window.isOpen()) {

        m_screenController->updateScreen(m_window);
        m_screenController->draw(m_window);

    }
}

void GameEngine::setup(){
    std::cout<<"Gameengine in setup\n";
    setWindowPosition();

}

void GameEngine::setWindowPosition(){
    // Get the desktop mode to access the screen resolution
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();

    // Calculate the window position to center it
    unsigned int posX = (desktop.width / 2) - (m_window.getSize().x / 2);
    unsigned int posY = (desktop.height / 2) - (m_window.getSize().y / 2);

    // Set the window position
    m_window.setPosition(sf::Vector2i(posX, posY));
}
