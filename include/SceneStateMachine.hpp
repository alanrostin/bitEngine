#ifndef SceneStateMachine_hpp
#define SceneStateMachine_hpp

#include <memory>
#include <unordered_map>
#include "Scene.hpp"
#include "Window.hpp"

class SceneStateMachine
{
    public:
        SceneStateMachine();

        // processInput, update, lateUpdate, and render
        // will be pass through methods. They will call the correspondingly
        // named methods of the active scene.
        void processInput();
        void update(float deltaTime);
        void lateUpdate(float deltaTime);
        void render(Window& window);

        // Adds a scene to the state machine and returns th id of that scene.
        int addScene(std::shared_ptr<Scene> scene);

        // Transitions to scene with specified id.
        void switchToScene(int sceneId);

        // Removes scene from state machine.
        void removeScene(int sceneId);
    
    private:
        // Stores all of the scenes associated with this state machine.
        std::unordered_map<int, std::shared_ptr<Scene>> scenes;

        // Stores a reference to the current scene. Used when rendering/updating.
        std::shared_ptr<Scene> currentScene;

        // Stores current scene id. This is incremented whenever a scene is added.
        int insertedSceneId;

};

#endif