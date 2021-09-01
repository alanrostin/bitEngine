#include "RenderSystem.hpp"

void RenderSystem::addObject(std::vector<std::shared_ptr<Object>>& objects)
{
    for (auto object : objects)
    {
        addObject(object);
    }

    sortObjects();
}

void RenderSystem::processRemove()
{
    auto objIterator = drawables.begin();

    while (objIterator != drawables.end())
    {
        auto obj = *objIterator;

        if (obj -> isQueuedForRemove())
        {
            objIterator = drawables.erase(objIterator);
        }
        else
        {
            ++objIterator;
        }
    }
}

void RenderSystem::addObject(std::shared_ptr<Object> object)
{
    std::shared_ptr<DrawableComponent> draw = object -> getDrawable();

    if (draw)
    {
        drawables.emplace_back(object);
    }
}

void RenderSystem::sortObjects()
{
    std::sort(drawables.begin(), drawables.end(), 
        [](std::shared_ptr<Object> a, std::shared_ptr<Object> b) -> bool 
        {
            return a -> getDrawable() -> getSetOrder() < b -> getDrawable() -> getSetOrder();
        });
}

void RenderSystem::render(Window& window)
{
    for (auto& drawable : drawables)
    {
        drawable -> render(window);
    }
}