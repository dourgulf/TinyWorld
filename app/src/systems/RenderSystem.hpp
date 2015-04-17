#pragma once
#include "ecs/System.hpp"
#include "components/Visibility.hpp"
#include "components/Position.hpp"
#include <SFML/OpenGL.hpp>

namespace ECS {
    template <typename T> class ComponentManager;
}
class MeshFactory;
class RenderSystem : public ECS::System {

public:

    RenderSystem(
        ECS::ComponentManager<Visibility>* vc,
        ECS::ComponentManager<Position>* pc
    );

    void initialize();
    void update();

private:

    MeshFactory* meshFactory;

    GLfloat lightPos[4] {0.f, 0.f, 10.f, 1.f};
    GLfloat lightAmb[4] {.5f, .5f, .5f, 0.f};
    GLfloat lightDif[4] {.5f, .5f, .5f, 1.f};

    ECS::ComponentManager<Visibility>* visibilityComponents;
    ECS::ComponentManager<Position>* positionComponents;
};
