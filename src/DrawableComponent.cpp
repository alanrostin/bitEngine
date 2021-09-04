#include "DrawableComponent.hpp"

DrawableComponent::DrawableComponent() : sortOrder(0), layer(DrawLayer::Default) {}

DrawableComponent::~DrawableComponent() {}

void DrawableComponent::setSortOrder(int order)
{
    sortOrder = order;
}

int DrawableComponent::getSetOrder() const
{
    return sortOrder;
}

void DrawableComponent::setDrawLayer(DrawLayer drawLayer)
{
    layer = drawLayer;
}

DrawLayer DrawableComponent::getDrawLayer() const
{
    return layer;
}