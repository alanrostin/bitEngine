#include "AnimationComponent.hpp"
#include "Object.hpp"

AnimationComponent::AnimationComponent(Object* object) 
    : Component(object), currentAnimation(AnimationState::None, nullptr)
{

}

void AnimationComponent::awake()
{
    sprite = object -> getComponent<SpriteComponent>();
}

void AnimationComponent::update(float deltaTime)
{
    if (currentAnimation.first != AnimationState::None)
    {
        bool newFrame = currentAnimation.second -> updateFrame(deltaTime);

        if (newFrame)
        {
            const FrameData* frameData = currentAnimation.second -> getCurrentFrame();
            sprite -> load(frameData -> id);
            sprite -> setTextureRect(frameData -> x, frameData -> y, frameData -> width, frameData-> height);
        }
    }
}

void AnimationComponent::addAnimation(AnimationState state, std::shared_ptr<Animation> animation)
{
    auto inserted = animations.insert(std::make_pair(state, animation));

    if (currentAnimation.first == AnimationState::None)
    {
        setAnimationState(state);
    }
}

void AnimationComponent::setAnimationState(AnimationState state)
{
    if (currentAnimation.first == state)
    {
        return;
    }

    auto animation = animations.find(state);

    if (animation != animations.end())
    {
        currentAnimation.first = animation -> first;
        currentAnimation.second = animation -> second;
        currentAnimation.second -> reset();
    }
}

const AnimationState& AnimationComponent::getAnimationState() const
{
    return currentAnimation.first;
}

void AnimationComponent::setAnimationDirection(FacingDirection facingDirection)
{
    if (currentAnimation.first != AnimationState::None)
    {
        currentAnimation.second -> setDirection(facingDirection);
    }
}