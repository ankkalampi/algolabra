#include "render_component.hpp"

#include "../render/render_manager.hpp"
#include "SDL3/SDL_rect.h"
#include "systems/coordinate_system.hpp"

namespace components
{
systems::CoordinateSystem* RenderComponent::coordinateSystem = nullptr;

RenderComponent::RenderComponent(SDL_Rect& rect, SDL_Color& color)
    : x(rect.x), y(rect.y), w(rect.w), h(rect.h), Scolor(color)
{
    SDL_FRect* frptr = &frect;

    SDL_RectToFRect(&rect, frptr);

    // convert SDL_Color to uint32_t using bitwise operations
    this->color = (color.a << 24) | (color.b << 16) | (color.g << 8) | color.r;
}

// static processing method
void RenderComponent::process(RenderComponent& rendComp)
{
    // update rendercomponent x, y based on coordinacomponent
    // later this could be used to make camera translations etc

    rendComp.frect.x =
        float(coordinateSystem->getComponent(rendComp.entityId).x);
    rendComp.frect.y =
        float(coordinateSystem->getComponent(rendComp.entityId).y);
}

};  // namespace components