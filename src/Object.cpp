#include "Object.hpp"

Object::Object() : queuedForRemove(false)
{
    transform = addComponent<TransformComponent>();
}

void Object::awake()
{
    for (int i = components.size() - 1; i >= 0; i--)
    {
        components[i] -> awake();
    }
}

void Object::start()
{
    for (int i = components.size() - 1; i >= 0; i--)
    {
        components[i] -> start();
    }
}

void Object::update(float deltaTime)
{
    for (int i = components.size() - 1; i >= 0; i--)
    {
        components[i] -> update(deltaTime);
    }
}

void Object::lateUpdate(float deltaTime)
{
    for (int i = components.size() - 1; i >= 0; i--)
    {
        components[i] -> lateUpdate(deltaTime);
    }
}

void Object::render(Window& window)
{
    drawable -> render(window);
}

void Object::queueForRemove()
{
    queuedForRemove = true;
}

bool Object::isQueuedForRemove()
{
    return queuedForRemove;
}

std::shared_ptr<DrawableComponent> Object::getDrawable()
{
    return drawable;
}