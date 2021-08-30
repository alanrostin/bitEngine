#ifndef SceneGame_hpp
#define SceneGame_hpp

#include "Scene.hpp"
#include "InputManager.hpp"
#include "Object.hpp"
#include "SpriteComponent.hpp"

class SceneGame : public Scene
{
    public:
        SceneGame();
        void onCreate() override;
        void onDestroy() override;
        void processInput() override;
        void update(float deltaTime) override;
        void render(Window& window) override;
    
    private:
        std::shared_ptr<Object> player;
        InputManager inputManager;
};

#endif