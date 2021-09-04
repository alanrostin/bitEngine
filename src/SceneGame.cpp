#include "SceneGame.hpp"

SceneGame::SceneGame(ContentPath& contentPath, 
    ResourceManager<sf::Texture>& textureManager, Window& window) 
    : contentPath(contentPath),  textureManager(textureManager), 
    tileMapParser(textureManager), window(window) {}

void SceneGame::onCreate()
{
    std::shared_ptr<Object> player = std::make_shared<Object>();

    player -> transform -> setPosition(100, 550);
    
    // Adds a component by calling our previously written template function.
    auto sprite = player -> addComponent<SpriteComponent>();
    sprite -> setTextureManager(&textureManager);
    sprite -> setDrawLayer(DrawLayer::Entities);

    auto movement = player -> addComponent<KeyboardMovementComponent>();
    movement -> setInput(&inputManager);

    auto animation = player -> addComponent<AnimationComponent>();
    int bitmanTextureId = textureManager.addResource(contentPath.getPath() + "viking_animation.png");

    const int frameWidth = 165;
    const int frameHeight = 145;

    std::shared_ptr<Animation> idleAnimation = std::make_shared<Animation>(FacingDirection::Right);

    const float idleAnimationSeconds = 0.2f;
    idleAnimation -> addFrame(bitmanTextureId, 600, 0, frameWidth, frameHeight, idleAnimationSeconds);
    idleAnimation -> addFrame(bitmanTextureId, 800, 0, frameWidth, frameHeight, idleAnimationSeconds);
    idleAnimation -> addFrame(bitmanTextureId, 0, 145, frameWidth, frameHeight, idleAnimationSeconds);
    idleAnimation -> addFrame(bitmanTextureId, 200, 145, frameWidth, frameHeight, idleAnimationSeconds);

    animation -> addAnimation(AnimationState::Idle, idleAnimation);

    std::shared_ptr<Animation> walkAnimation = std::make_shared<Animation>(FacingDirection::Right);

    const float walkAnimationFrameSeconds = 0.15f;
    walkAnimation -> addFrame(bitmanTextureId, 600, 290, frameWidth, frameHeight, walkAnimationFrameSeconds);
    walkAnimation -> addFrame(bitmanTextureId, 800, 290, frameWidth, frameHeight, walkAnimationFrameSeconds);
    walkAnimation -> addFrame(bitmanTextureId, 0, 435, frameWidth, frameHeight, walkAnimationFrameSeconds);
    walkAnimation -> addFrame(bitmanTextureId, 200, 435, frameWidth, frameHeight, walkAnimationFrameSeconds);
    walkAnimation -> addFrame(bitmanTextureId, 400, 435, frameWidth, frameHeight, walkAnimationFrameSeconds);

    animation -> addAnimation(AnimationState::Walk, walkAnimation);

    auto collider = player -> addComponent<BoxColliderComponent>();
    collider -> setSize(frameWidth * 0.4f, frameHeight * 0.5f);
    collider -> setOffset(0.0f, 14.0f);
    collider -> setLayer(CollisionLayer::Player);
    // collider -> setCollidable(sf::FloatRect(0, 0, frameWidth, frameHeight));
    // collider -> setLayer(CollisionLayer::Player);

    auto camera = player -> addComponent<CameraComponent>();
    camera -> setWindow(&window);
    objects.addObject(player);

    sf::Vector2i mapOffset(-160, 180);
    std::vector<std::shared_ptr<Object>> levelTiles 
        = tileMapParser.parse(contentPath.getPath() + "testmap1.tmx", mapOffset);
    
    objects.addObject(levelTiles);
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
    Debug::render(window);
}
