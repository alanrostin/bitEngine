#ifndef Engine_hpp
#define Engine_hpp

#include <SFML/Graphics.hpp>
#include "Window.hpp"
#include <iostream>

class Engine
{
    public:
        Engine();
        void update();
        void lateUpdate();
        void render();
        bool isRunning() const;
    
    private:
        Window m_Window;
};

#endif