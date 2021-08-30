#ifndef KeyboardMovementComponent_hpp
#define KeyboardMovementComponent_hpp

#include "Component.hpp"
#include "InputManager.hpp"

class KeyboardMovementComponent : public Component
{
    public:
        KeyboardMovementComponent(Object* object);
        void setInput(InputManager* inputManager);
        void setMovementSpeed(int moveSpeed);
        void update(float deltaTime) override;
    
    private:
        int moveSpeed;
        InputManager* inputManager;
};

#endif