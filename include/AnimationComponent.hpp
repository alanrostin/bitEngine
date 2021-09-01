#ifndef AnimationComponent_hpp
#define AnimationComponent_hpp

#include "Component.hpp"
#include "Animation.hpp"
#include "SpriteComponent.hpp"

enum class AnimationState
{
    None,
    Idle,
    Walk
};

class AnimationComponent : public Component
{
    public:
        AnimationComponent(Object* object);
        void awake() override;
        void update(float deltaTime) override;

        void addAnimation(AnimationState state, 
            std::shared_ptr<Animation> animation);
        void setAnimationState(AnimationState state);
        const AnimationState& getAnimationState() const;
        void setAnimationDirection(FacingDirection facingDirection);
    
    private:
        std::shared_ptr<SpriteComponent> sprite;
        std::map<AnimationState, std::shared_ptr<Animation>> animations;
        std::pair<AnimationState, std::shared_ptr<Animation>> currentAnimation;
};

#endif