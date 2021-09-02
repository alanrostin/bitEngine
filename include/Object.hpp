#ifndef Object_hpp
#define Object_hpp

#include <memory>
#include <vector>

#include "Window.hpp"
#include "Component.hpp"
#include "TransformComponent.hpp"
#include "DrawableComponent.hpp"
#include "InstanceIdComponent.hpp"

class Object
{
    public:
        Object();
        // Awake is called when object created.
        // Use to ensure required components are present
        void awake();
        // Start is called after awake method.
        // Use to initialize variables.
        void start();

        void update(float deltaTime);
        void lateUpdate(float deltaTime);
        void render(Window& window);

        template<typename T> std::shared_ptr<T> addComponent()
        {
            // This ensures that we only try to add a class that derives from Component.
            static_assert(std::is_base_of<Component, T>::value, "T must derive from Component");

            // Check that we don't already have a component of this type.
            for (auto& existingComponent : components)
            {
                if (std::dynamic_pointer_cast<T>(existingComponent))
                {
                    return std::dynamic_pointer_cast<T>(existingComponent);
                }
            }

            // The object does not have this component so we create it and add it to our list.
            std::shared_ptr<T> newComponent = std::make_shared<T>(this);
            components.push_back(newComponent);

            // Check if the component is a drawable
            if (std::dynamic_pointer_cast<DrawableComponent>(newComponent))
            {
                drawable = std::dynamic_pointer_cast<DrawableComponent>(newComponent);
            }
            
            return newComponent;
        };

        template<typename T> std::shared_ptr<T> getComponent()
        {
            static_assert(std::is_base_of<Component, T>::value, "T must derive from Component");
            
            // Check that we don't already have a component of this type.
            for (auto& existingComponent : components)
            {
                if (std::dynamic_pointer_cast<T>(existingComponent))
                {
                    return std::dynamic_pointer_cast<T>(existingComponent);
                }
            }

            return nullptr;
        };

        std::shared_ptr<DrawableComponent> getDrawable();

        void queueForRemove();
        bool isQueuedForRemove();

        std::shared_ptr<TransformComponent> transform;
        std::shared_ptr<InstanceIdComponent> instanceId;
    
    private:
        std::vector<std::shared_ptr<Component>> components;
        std::shared_ptr<DrawableComponent> drawable;
        bool queuedForRemove;
};

#endif