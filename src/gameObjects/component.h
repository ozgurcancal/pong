

#ifndef COMPONENT_H
#define COMPONENT_H

#include <string>

enum class ComponentType {
    Paddle,
    Ball,
};

class Component {

public:
    virtual std::string getType() = 0; 
    virtual void update() = 0;
    virtual void render() = 0;
    virtual void handleInput() = 0;
    virtual ~Component() = default;

};

#endif // COMPONENT_H