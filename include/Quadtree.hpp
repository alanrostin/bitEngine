#ifndef Quadtree_hpp
#define Quadtree_hpp

#include <memory>
#include <vector>
#include "BoxColliderComponent.hpp"
#include "Object.hpp"
#include "Debug.hpp"

class Quadtree
{
    public:
        Quadtree();
        Quadtree(int maxObjects, int maxLevels, 
            int level, sf::FloatRect bounds, Quadtree* parent);
        
        void insertObject(std::shared_ptr<BoxColliderComponent> object);
        void removeObject(std::shared_ptr<BoxColliderComponent> object);
        void clear();

        std::vector<std::shared_ptr<BoxColliderComponent>> search(const sf::FloatRect& area);
        const sf::FloatRect& getBounds() const;

        void drawDebug();
    
    private:
        void search(const sf::FloatRect& area, 
            std::vector<std::shared_ptr<BoxColliderComponent>>& overlappingObjects);
        int getChildIndexForObject(const sf::FloatRect& objectBounds);
        void split();

        static const int thisTree = -1;
        static const int childNE = 0;
        static const int childNW = 1;
        static const int childSW = 2;
        static const int childSE = 3;

        int maxObjects;
        int maxLevels;

        Quadtree* parent;
        std::shared_ptr<Quadtree> children[4];
        std::vector<std::shared_ptr<BoxColliderComponent>> objects;

        int level;
        sf::FloatRect bounds;
};

#endif