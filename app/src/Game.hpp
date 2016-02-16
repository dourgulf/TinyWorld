#pragma once

#include <ecs/EntityManager.hpp>
#include <ecs/ComponentManager.hpp>

#include <systems/RenderSystem.hpp>
#include <systems/MovementSystem.hpp>

#include <components/Life.hpp>
#include <components/Movement.hpp>
#include <components/Visibility.hpp>

#include <graphic/Renderer.hpp>

class Game
{
public:

    Game();

    void draw();
    void update(float seconds);
    void reload();

private:

    float previousUpdateSeconds = 0.f;

    void setupWorld();
    void addEntity();
    void addTestEntity();

    ecs::EntityManager entities;

    ecs::ComponentManager<Life> lifeComponents = ecs::ComponentManager<Life>();
    ecs::ComponentManager<Movement> movementComponents = ecs::ComponentManager<Movement>();
    ecs::ComponentManager<Visibility> visibilityComponents = ecs::ComponentManager<Visibility>();

    RenderSystem renderSystem;
    MovementSystem movementSystem;

    Renderer renderer;
};
