#ifndef ObjectManager_hpp
#define ObjectManager_hpp

#include <memory>
#include <vector>
#include "Object.hpp"
#include "RenderSystem.hpp"
#include "CollisionSystem.hpp"

class ObjectManager
{
    public:
        void addObject(std::shared_ptr<Object> object);
        void addObject(std::vector<std::shared_ptr<Object>>& objects);

        void update(float deltaTime);
        void lateUpdate(float deltaTime);
        void render(Window& window);
        void processNewObjects();
        void processRemoveObjects();
    
    private:
        std::vector<std::shared_ptr<Object>> objects;
        std::vector<std::shared_ptr<Object>> newObjects;
        RenderSystem drawables;
        CollisionSystem collidables;
};

#endif