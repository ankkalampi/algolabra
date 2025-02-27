#include "entity_storage.hpp"

#include "components/component_storage.hpp"
#include "components/render_component.hpp"

namespace entity
{
EntityStorage::EntityStorage()
    : componentStorage(components::ComponentStorage())
{
    addDebugName("ENTITY_STORAGE");
    addDebugProperty("componentStorage", &componentStorage);
    printDebugInfo();
}

std::vector<std::any> EntityStorage::generateEntity(EntityType type)
{
    std::vector<std::any> components;
    switch (type) {
    case Plant:
        components.push_back(components::RenderComponent::generateComponent(
            componentStorage.REDBOX));
        break;
    case Herbivore1:
        components.push_back(components::RenderComponent::generateComponent(
            componentStorage.BLUEBOX));
        components.push_back(components::BehaviorComponent::generateComponent(
            componentStorage.CIRCLES));
        break;
    case Herbivore2:
        components.push_back(components::RenderComponent::generateComponent(
            componentStorage.BLUEBOX));
        components.push_back(components::BehaviorComponent::generateComponent(
            componentStorage.STRAIGHTANDBACK));
        break;
    case Herbivore3:
        components.push_back(components::RenderComponent::generateComponent(
            componentStorage.BLUEBOX));
        components.push_back(components::BehaviorComponent::generateComponent(
            componentStorage.STAY));
        break;
    case Herbivore4:
        components.push_back(components::RenderComponent::generateComponent(
            componentStorage.BLUEBOX));
        components.push_back(components::BehaviorComponent::generateComponent(
            componentStorage.CAREFUL));
        break;
    case Carnivore1:
        components.push_back(components::RenderComponent::generateComponent(
            componentStorage.GREENBOX));
        components.push_back(components::BehaviorComponent::generateComponent(
            componentStorage.CIRCLES));
        break;
    case Carnivore2:
        components.push_back(components::RenderComponent::generateComponent(
            componentStorage.GREENBOX));
        components.push_back(components::BehaviorComponent::generateComponent(
            componentStorage.STRAIGHTANDBACK));
        break;
    case Carnivore3:
        components.push_back(components::RenderComponent::generateComponent(
            componentStorage.GREENBOX));
        components.push_back(components::BehaviorComponent::generateComponent(
            componentStorage.CAREFUL));
        break;
    }

    return components;
}

}  // namespace entity