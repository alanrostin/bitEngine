#include "KeyboardMovementComponent.hpp"
#include "Object.hpp"

KeyboardMovementComponent::KeyboardMovementComponent(Object* object) 
    : Component(object), moveSpeed(100)
{

}

void KeyboardMovementComponent::setInput(InputManager* inputManager)
{
    this -> inputManager = inputManager;
}

void KeyboardMovementComponent::setMovementSpeed(int moveSpeed)
{
    this -> moveSpeed = moveSpeed;
}

void KeyboardMovementComponent::update(float deltaTime)
{
    if (inputManager == nullptr)
    {
        return;
    }

    int xMove = 0;

    if (inputManager -> isKeyPressed(InputManager::Key::Left))
    {
        xMove = -moveSpeed;
    }
    else if (inputManager -> isKeyPressed(InputManager::Key::Right))
    {
        xMove = moveSpeed;
    }

    int yMove = 0;

    if (inputManager -> isKeyDown(InputManager::Key::Up))
    {
        yMove = -moveSpeed;
    }
    else if (inputManager -> isKeyDown(InputManager::Key::Down))
    {
        yMove = moveSpeed;
    }

    float xFrameMove = xMove * deltaTime;
    float yFrameMove = yMove * deltaTime;

    object -> transform -> addPosition(xFrameMove, yFrameMove);
}