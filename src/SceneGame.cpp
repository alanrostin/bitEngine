#include "SceneGame.hpp"

SceneGame::SceneGame(ContentPath& contentPath, ResourceManager<sf::Texture>& textureManager) 
    : contentPath(contentPath),  textureManager(textureManager)
{

}

void SceneGame::onCreate()
{
    std::shared_ptr<Object> player = std::make_shared<Object>();
    
    // Adds a component by calling our previously written template function.
    auto sprite = player -> addComponent<SpriteComponent>();
    sprite -> setTextureManager(&textureManager);

    auto movement = player -> addComponent<KeyboardMovementComponent>();
    movement -> setInput(&inputManager);

    auto animation = player -> addComponent<AnimationComponent>();
    int bitmanTextureId = textureManager.addResource(contentPath.getPath() + "player/viking_animation.png");
    const int frameWidth = 165;
    const int frameHeight = 145;

    std::shared_ptr<Animation> idleAnimation = std::make_shared<Animation>();

    const float idleAnimationSeconds = 0.2f;
    idleAnimation -> addFrame(bitmanTextureId, 600, 0, frameWidth, frameHeight, idleAnimationSeconds);
    idleAnimation -> addFrame(bitmanTextureId, 800, 0, frameWidth, frameHeight, idleAnimationSeconds);
    idleAnimation -> addFrame(bitmanTextureId, 0, 145, frameWidth, frameHeight, idleAnimationSeconds);
    idleAnimation -> addFrame(bitmanTextureId, 200, 145, frameWidth, frameHeight, idleAnimationSeconds);

    animation -> addAnimation(AnimationState::Idle, idleAnimation);

    objects.addObject(player);
}

void SceneGame::onDestroy()
{

}

void SceneGame::processInput()
{
    inputManager.update();
}

void SceneGame::update(float deltaTime)
{
    objects.processRemoveObjects();
    objects.processNewObjects();
    objects.update(deltaTime);
}

void SceneGame::lateUpdate(float deltaTime)
{
    objects.lateUpdate(deltaTime);
}

void SceneGame::render(Window& window)
{
    objects.render(window);
}
