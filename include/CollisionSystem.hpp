#ifndef CollisionSystem_hpp
#define CollisionSystem_hpp

#include <vector>
#include <memory>
#include <set>
#include "Object.hpp"
#include "Quadtree.hpp"
#include "Bitmask.hpp"

class CollisionSystem
{
    public:
        CollisionSystem();
        void addObject(std::vector<std::shared_ptr<Object>>& objects);
        void processRemove();
        void update();
    
    private:
        void resolve();
        void processCollisions(std::vector<std::shared_ptr<Object>>& first, 
            std::vector<std::shared_ptr<Object>>& second);
        
        std::map<CollisionLayer, Bitmask> collisionLayers;
        std::map<CollisionLayer, std::vector<std::shared_ptr<BoxColliderComponent>>> collidables;

        Quadtree collisionTree;
};

#endif