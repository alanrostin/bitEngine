#include "DrawableComponent.hpp"

DrawableComponent::DrawableComponent() : sortOrder(0)
{

}

DrawableComponent::~DrawableComponent()
{

}

void DrawableComponent::setSortOrder(int order)
{
    sortOrder = order;
}

int DrawableComponent::getSetOrder() const
{
    return sortOrder;
}