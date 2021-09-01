#ifndef KeyboardMovementComponent_hpp
#define KeyboardMovementComponent_hpp

#include "Component.hpp"
#include "InputManager.hpp"
#include "AnimationComponent.hpp"

class KeyboardMovementComponent : public Component
{
    public:
        KeyboardMovementComponent(Object* object);

        void awake() override;

        void setInput(InputManager* inputManager);
        void setMovementSpeed(int moveSpeed);
        void update(float deltaTime) override;
    
    private:
        int moveSpeed;
        InputManager* inputManager;

        std::shared_ptr<AnimationComponent> animation;
};

#endif