#ifndef InstanceIdComponent_hpp
#define InstanceIdComponent_hpp

#include "Component.hpp"

class InstanceIdComponent : public Component
{
    public:
        InstanceIdComponent(Object* object);
        ~InstanceIdComponent();
        int getInstanceId() const;
    
    private:
        static int instanceIdCount;
        int instanceId;
};

#endif