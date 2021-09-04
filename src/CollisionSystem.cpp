#include "CollisionSystem.hpp"

CollisionSystem::CollisionSystem() : collisionTree(5, 5, 0, {0, 0, 4200, 900}, nullptr)
{
    Bitmask defaultCollisions;
    defaultCollisions.setBit((int)CollisionLayer::Default);
    collisionLayers.insert(std::make_pair(CollisionLayer::Default, defaultCollisions));
    collisionLayers.insert(std::make_pair(CollisionLayer::Tile, Bitmask(0)));

    Bitmask playerCollisions;
    playerCollisions.setBit((int)CollisionLayer::Default);
    playerCollisions.setBit((int)CollisionLayer::Tile);
    collisionLayers.insert(std::make_pair(CollisionLayer::Player, playerCollisions));
}

void CollisionSystem::addObject(std::vector<std::shared_ptr<Object>>& objects)
{
    for (auto object : objects)
    {
        auto collider = object -> getComponent<BoxColliderComponent>();

        if (collider)
        {
            CollisionLayer layer = collider -> getLayer();            
            auto itr = collidables.find(layer);

            if (itr != collidables.end())
            {
                collidables[layer].push_back(collider);
            }
            else
            {
                std::vector<std::shared_ptr<BoxColliderComponent>> objs;
                objs.push_back(collider);
                collidables.insert(std::make_pair(layer, objs));
            }
        }
    }
}

void CollisionSystem::processRemove()
{
    for (auto& layer : collidables)
    {
        auto itr = layer.second.begin();

        while (itr != layer.second.end())
        {
            if ((*itr) -> object -> isQueuedForRemove())
            {
                itr = layer.second.erase(itr);
            }
            else
            {
                ++itr;
            }
        }
    }
}

void CollisionSystem::update()
{
    collisionTree.drawDebug();
    collisionTree.clear();

    for (auto maps = collidables.begin(); maps != collidables.end(); ++maps)
    {
        for (auto collidable : maps -> second)
        {
            collisionTree.insertObject(collidable);
        }
    }

    resolve();
}

void CollisionSystem::resolve()
{
    for (auto maps = collidables.begin(); maps != collidables.end(); ++maps)
    {
        if (collisionLayers[maps -> first].getMask() == 0)
        {
            continue;
        }

        for (auto collidable : maps -> second)
        {
            if (collidable -> object -> transform -> isStatic())
            {
                continue;
            }

            std::vector<std::shared_ptr<BoxColliderComponent>> collisions 
                = collisionTree.search(collidable -> getCollidable());
            
            for (auto collision : collisions)
            {
                if (collidable -> object -> instanceId -> getInstanceId() 
                    == collision -> object -> instanceId -> getInstanceId())
                {
                    continue;
                }

                bool layersCollide = collisionLayers[collidable -> getLayer()].getBit(((int)collision -> getLayer()));

                if (layersCollide)
                {
                    Manifold manifold = collidable -> intersects(collision);

                    if (manifold.colliding)
                    {
                        Debug::drawRect(collision -> getCollidable(), sf::Color::Red);
                        Debug::drawRect(collidable -> getCollidable(), sf::Color::Red);

                        if (collision -> object -> transform -> isStatic())
                        {
                            collidable -> resolveOverlap(manifold);
                        }
                        else
                        {
                            collidable -> resolveOverlap(manifold);
                        }
                    }
                }
            }
        }
    }
}