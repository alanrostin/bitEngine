#ifndef TransformComponent_hpp
#define TransformComponent_hpp

#include "Component.hpp"

class TransformComponent : public Component
{
    public:
        TransformComponent(Object* object);
        void setPosition(float x, float y);
        void setPosition(const sf::Vector2f& pos);
        void addPosition(float x, float y);
        void addPosition(sf::Vector2f pos);

        void setX(float x);
        void setY(float y);

        void addX(float x);
        void addY(float y);

        const sf::Vector2f& getPosition() const;

        void setStatic(bool isStatic);
        bool isStatic() const;
    
    private:
        sf::Vector2f position;
        bool isStaticTransform;
};

#endif