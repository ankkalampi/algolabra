#include "render_component.hpp"

#include "systems/coordinate_system.hpp"

namespace components
{
systems::CoordinateSystem* RenderComponent::coordinateSystem = nullptr;

RenderComponent::RenderComponent(int entityId,
                                 const SDL_Rect& rect,
                                 const SDL_Color& color)
    : Component(entityId), x(rect.x), y(rect.y), w(rect.w), h(rect.h)
{
    // convert SDL_Color to uint32_t using bitwise operations
    this->color = (color.a << 24) | (color.b << 16) | (color.g << 8) | color.r;
}

// static processing method
void RenderComponent::process(RenderComponent& rendComp)
{
    // update rendercomponent x, y based on coordinacomponent
    // later this could be used to make camera translations etc
    rendComp.x = static_cast<CoordinateComponent&>(
                     coordinateSystem->getComponent(rendComp.entityId))
                     .x;
    rendComp.y = static_cast<CoordinateComponent&>(
                     coordinateSystem->getComponent(rendComp.entityId))
                     .y;
}
};  // namespace components