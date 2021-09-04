#ifndef CameraComponent_hpp
#define CameraComponent_hpp

#include "Component.hpp"

class CameraComponent : public Component
{
    public:
        CameraComponent(Object* object);

        void lateUpdate(float deltaTime) override;
        void setWindow(Window* gameWindow);
    
    private:
        Window* window;
};

#endif