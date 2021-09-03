#include "ObjectManager.hpp"

void ObjectManager::addObject(std::shared_ptr<Object> object)
{
    newObjects.push_back(object);
}

void ObjectManager::addObject(std::vector<std::shared_ptr<Object>>& objects)
{
    newObjects.insert(newObjects.end(), objects.begin(), objects.end());
}

void ObjectManager::update(float deltaTime)
{
    for (const auto& object : objects)
    {
        object -> update(deltaTime);
    }

    collidables.update();
}

void ObjectManager::lateUpdate(float deltaTime)
{
    for (auto& object : objects)
    {
        object -> lateUpdate(deltaTime);
    }
}

void ObjectManager::render(Window& window)
{
    drawables.render(window);
}

void ObjectManager::processNewObjects()
{
    if (newObjects.size() > 0)
    {
        for (const auto& object : newObjects)
        {
            object -> awake();
        }

        for (const auto& object : newObjects)
        {
            object -> start();
        }

        objects.insert(objects.end(), newObjects.begin(), newObjects.end());

        drawables.addObject(newObjects);
        collidables.addObject(newObjects);

        newObjects.clear();
    }
}

void ObjectManager::processRemoveObjects()
{
    bool removed = false;

    auto objectIterator = objects.begin();

    while (objectIterator != objects.end())
    {
        auto object = *objectIterator;

        if (object -> isQueuedForRemove())
        {
            objectIterator = objects.erase(objectIterator);
            removed = true;
        }
        else
        {
            ++objectIterator;
        }
    }

    if (removed)
    {
        drawables.processRemove();
        collidables.processRemove();
    }
}