#ifndef DrawableComponent_hpp
#define DrawableComponent_hpp

#include <SFML/Graphics.hpp>
#include "Window.hpp"

enum class DrawLayer
{
    Default,
    Background,
    Foreground,
    Entities
};

class DrawableComponent
{
    public:
        DrawableComponent();
        virtual ~DrawableComponent();

        virtual void render(Window& window) = 0;
        virtual bool continueToRender() const = 0;

        void setSortOrder(int order);
        int getSetOrder() const;

        void setDrawLayer(DrawLayer drawLayer);
        DrawLayer getDrawLayer() const;
    
    private:
        int sortOrder;
        DrawLayer layer;
};

#endif