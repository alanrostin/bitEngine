#ifndef DrawableComponent_hpp
#define DrawableComponent_hpp

#include <SFML/Graphics.hpp>
#include "Window.hpp"

class DrawableComponent
{
    public:
        DrawableComponent();
        virtual ~DrawableComponent();
        virtual void render(Window& window) = 0;
        void setSortOrder(int order);
        int getSetOrder() const;
    
    private:
        int sortOrder;
};

#endif