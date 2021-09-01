#include "KeyboardMovementComponent.hpp"
#include "Object.hpp"

KeyboardMovementComponent::KeyboardMovementComponent(Object* object) 
    : Component(object), moveSpeed(200)
{

}

void KeyboardMovementComponent::awake()
{
    animation = object -> getComponent<AnimationComponent>();
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
        animation -> setAnimationDirection(FacingDirection::Left);
    }
    else if (inputManager -> isKeyPressed(InputManager::Key::Right))
    {
        xMove = moveSpeed;
        animation -> setAnimationDirection(FacingDirection::Right);
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

    if (xMove == 0 && yMove == 0)
    {
        animation -> setAnimationState(AnimationState::Idle);
    }
    else
    {
        animation -> setAnimationState(AnimationState::Walk);
    }
}