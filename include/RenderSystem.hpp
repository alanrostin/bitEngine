#ifndef RenderSystem_hpp
#define RenderSystem_hpp

#include <map>
#include "DrawableComponent.hpp"
#include "Object.hpp"

class RenderSystem
{
    public:
        void addObject(std::vector<std::shared_ptr<Object>>& object);
        void processRemove();
        void render(Window& window);
    
    private:
        void addObject(std::shared_ptr<Object> object);
        void sortObjects();
        std::vector<std::shared_ptr<Object>> drawables;
};

#endif