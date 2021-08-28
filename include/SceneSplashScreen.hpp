#ifndef SceneSplashScreen_hpp
#define SceneSplashScreen_hpp

#include <SFML/Graphics.hpp>
#include "SceneStateMachine.hpp"

class SceneSplashScreen : public Scene
{
    public:
        SceneSplashScreen(SceneStateMachine& sceneStateMachine, Window& window);
        void onCreate() override;
        void onDestroy() override;
        void onActivate() override;
        void setSwitchToScene(unsigned int sceneId);
        void update(float deltaTime) override;
        void render(Window& window) override;
    
    private:
        sf::Texture splashTexture;
        sf::Sprite splashSprite;
        SceneStateMachine& sceneStateMachine;
        Window& window;

        float showForSeconds;
        float currentSeconds;

        // The state to transition to when this scene's time expires.
        unsigned int switchToState;
};

#endif