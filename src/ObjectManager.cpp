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
    for (auto& object : objects)
    {
        object -> update(deltaTime);
    }
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
    for (auto& object : objects)
    {
        object -> render(window);
    }
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
        newObjects.clear();
    }
}

void ObjectManager::processRemoveObjects()
{
    auto objectIterator = objects.begin();

    while (objectIterator != objects.end())
    {
        auto object = **objectIterator;

        if (object.isQueuedForRemove())
        {
            objectIterator = objects.erase(objectIterator);
        }
        else
        {
            ++objectIterator;
        }
    }
}