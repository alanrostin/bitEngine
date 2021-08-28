#include "SceneSplashScreen.hpp"

SceneSplashScreen::SceneSplashScreen(SceneStateMachine& sceneStateMachine, Window& window) 
    : sceneStateMachine(sceneStateMachine), window(window), 
    switchToState(0), currentSeconds(0.f), showForSeconds(3.f)
{

}

void SceneSplashScreen::onCreate()
{
    splashTexture.loadFromFile("content/backgrounds/splash-screen.png");
    splashSprite.setTexture(splashTexture);

    sf::FloatRect spriteSize = splashSprite.getLocalBounds();
    splashSprite.setOrigin(spriteSize.width * 0.5f, spriteSize.height * 0.5f);
    splashSprite.setScale(0.5f, 0.5f);
    sf::Vector2u windowCenter = window.getCenter();

    splashSprite.setPosition(windowCenter.x, windowCenter.y);
}

void SceneSplashScreen::onActivate()
{
    currentSeconds = 0.0f;
}

void SceneSplashScreen::onDestroy()
{

}

void SceneSplashScreen::setSwitchToScene(unsigned int sceneId)
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