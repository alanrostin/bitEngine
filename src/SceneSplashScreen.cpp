#include "SceneSplashScreen.hpp"

SceneSplashScreen::SceneSplashScreen(ContentPath& contentPath, SceneStateMachine& sceneStateMachine, 
    Window& window, ResourceManager<sf::Texture>& textureManager) 
    : contentPath(contentPath), sceneStateMachine(sceneStateMachine), window(window), 
    switchToState(0), currentSeconds(0.0f), showForSeconds(3.0f), 
    textureManager(textureManager)
{

}

void SceneSplashScreen::onCreate()
{
    int textureId = textureManager.addResource(contentPath.getPath() + "splash-screen.png");
    
    if (textureId >= 0)
    {
        std::shared_ptr<sf::Texture> texture = textureManager.getResource(textureId);
        splashSprite.setTexture(*texture);
        sf::FloatRect spriteSize = splashSprite.getLocalBounds();
        splashSprite.setOrigin(spriteSize.width * 0.5f, spriteSize.height * 0.5f);
        sf::Vector2u windowCenter = window.getCenter();
        splashSprite.setPosition(windowCenter.x, windowCenter.y);
    }   
}

void SceneSplashScreen::onActivate()
{
    currentSeconds = 0.0f;
}

void SceneSplashScreen::onDestroy()
{

}

void SceneSplashScreen::setSwitchToScene(int sceneId)
{
    switchToState = sceneId;
}

void SceneSplashScreen::update(float deltaTime)
{
    currentSeconds += deltaTime;

    if (currentSeconds >= showForSeconds)
    {
        sceneStateMachine.switchToScene(switchToState);
    }
}

void SceneSplashScreen::render(Window& window)
{
    window.render(splashSprite);
}