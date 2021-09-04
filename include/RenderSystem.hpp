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
        static bool layerSort(std::shared_ptr<DrawableComponent> a, std::shared_ptr<DrawableComponent> b);
        void addObject(std::shared_ptr<Object> object);
        void sortObjects();
        std::map<DrawLayer, std::vector<std::shared_ptr<DrawableComponent>>> drawables;
};

#endif