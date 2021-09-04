#include "CameraComponent.hpp"
#include "Object.hpp"

CameraComponent::CameraComponent(Object* object) : Component(object) {}

void CameraComponent::lateUpdate(float deltaTime)
{
    if (window)
    {
        sf::View view = window -> getView();
        const sf::Vector2f& targetPosition = object -> transform -> getPosition();

        view.setCenter(targetPosition.x, 550);
        window -> setView(view);
    }
}

void CameraComponent::setWindow(Window* gameWindow)
{
    window = gameWindow;
}