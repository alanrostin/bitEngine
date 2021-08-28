#ifndef Scene_hpp
#define Scene_hpp

#include "Window.hpp"

class Scene
{
    public:
        // Called when scene initially created. Called once.
        virtual void onCreate() = 0;

        // Called when scene destroyed. Called at most once
        // (if a scene is not removed from the game, this will never be called)
        virtual void onDestroy() = 0;

        // Called whenever a scene is transitioned into.
        virtual void onActivate() {};

        // Called whenever a transition out of a scene occurs.
        virtual void onDeactivate() {};

        virtual void processInput() {};
        virtual void update(float deltaTime) {};
        virtual void lateUpdate(float deltaTime) {};
        virtual void render(Window& window) {};
};

#endif