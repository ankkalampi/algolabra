#pragma once

#include "debuggable.hpp"
#include "render/render_manager.hpp"
#include "runtime/runtime.hpp"
#include "runtime/systems_manager.hpp"

#include <optional>
#include <typeindex>
#include <typeinfo>
#include <unordered_map>
#include <variant>

// this system stuff should maybe go to dedicated system manager class
// better yet, this std::variant and system pointer map stuff should be
// automatically handled using some static magic in component and system

namespace runtime
{

struct Runtime : public debug::Debuggable {
    uint32_t tick;
    bool running;

    SDL_Event event;

    // this system stuff should maybe go to dedicated system manager class
    // better yet, this std::variant and system pointer map stuff should be
    // automatically handled using some static magic in component and system

    // end of systems stuff
    engine::SystemsManager systemsManager;
    render::RenderManager renderManager;

    Runtime();

    void run();
};

};  // namespace runtime