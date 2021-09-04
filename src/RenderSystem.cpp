#include "RenderSystem.hpp"

void RenderSystem::addObject(std::vector<std::shared_ptr<Object>>& objects)
{
    for (auto object : objects)
    {
        addObject(object);
    }
}

void RenderSystem::processRemove()
{
    for (auto& layer : drawables)
    {
        auto objIterator = layer.second.begin();

        while (objIterator != layer.second.end())
        {
            auto obj = *objIterator;

            if (!obj -> continueToRender())
            {
                objIterator = layer.second.erase(objIterator);
            }
            else
            {
                ++objIterator;
            }
        }
    }
}

void RenderSystem::addObject(std::shared_ptr<Object> object)
{
    std::shared_ptr<DrawableComponent> objectsDrawable = object -> getDrawable();

    if (objectsDrawable)
    {
        DrawLayer layer = objectsDrawable -> getDrawLayer();

        auto itr = drawables.find(layer);

        if (itr != drawables.end())
        {
            drawables[layer].push_back(objectsDrawable);
        }
        else
        {
            std::vector<std::shared_ptr<DrawableComponent>> objects;
            objects.push_back(objectsDrawable);
            drawables.insert(std::make_pair(layer, objects));
        }
    }
}

bool RenderSystem::layerSort(std::shared_ptr<DrawableComponent> a, std::shared_ptr<DrawableComponent> b)
{
    return a -> getSetOrder() < b -> getSetOrder();
}

void RenderSystem::sortObjects()
{
    for (auto& layer : drawables)
    {
        if (!std::is_sorted(layer.second.begin(), layer.second.end(), layerSort))
        {
            std::sort(layer.second.begin(), layer.second.end(), layerSort);
        }
    }
}

void RenderSystem::render(Window& window)
{
    sortObjects();

    for (auto& layer : drawables)
    {
        for (auto& drawable : layer.second)
        {
            drawable -> render(window);
        }
    }
}