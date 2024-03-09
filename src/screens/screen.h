

#ifndef SCREEN_H
#define SCREEN_H

#include <SFML/Graphics.hpp>
#include <string>
#include <functional>
#include <iostream>
#include <any>

class Screen
{
public:
    virtual void createScreen(sf::RenderWindow &window) = 0;

    // virtual void handleOnput(sf::RenderWindow &window, std::function<void(std::any)> callBack) = 0;
    virtual void handleInput(sf::RenderWindow &window, std::string &currentScreen) = 0;
    virtual void draw(sf::RenderWindow &window) = 0;
    virtual ~Screen() = default;
    float m_speed = 1.0f;

private:
};

#endif // SCREEN_H

// std::function<ReturnType(ArgType)> func;

// SingleArgFunctionWrapper(std::function<ReturnType(ArgType)> f) : func(f) {}
