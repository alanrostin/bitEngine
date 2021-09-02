#include "InstanceIdComponent.hpp"

int InstanceIdComponent::instanceIdCount = 0;

InstanceIdComponent::InstanceIdComponent(Object* object) 
    : Component(object), instanceId(instanceIdCount++)
{

}

InstanceIdComponent::~InstanceIdComponent() {}

int InstanceIdComponent::getInstanceId() const
{
    return instanceId;
}