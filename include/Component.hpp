#ifndef Component_hpp
#define Component_hpp

#include "Window.hpp"

class Object;

class Component
{
    public:
        Component(Object* object) : object(object) {}
        virtual void awake() {}
        virtual void start() {}
        virtual void update(float deltaTime) {}
        virtual void lateUpdate(float deltaTime) {}
        // virtual void render(Window& window) {}
    
    protected:
        Object* object;
};

#endif