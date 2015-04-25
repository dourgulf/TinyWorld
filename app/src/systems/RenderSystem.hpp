#pragma once
#include "ecs/System.hpp"
#include "components/Visibility.hpp"
#include "components/Movement.hpp"
#include <GL/glew.h>

namespace ECS {
    template <typename T> class ComponentManager;
}
class MeshFactory;
class RenderSystem : public ECS::System {

public:

    RenderSystem(
        ECS::ComponentManager<Visibility>* vc,
        ECS::ComponentManager<Movement>* mc
    );

    void update();

private:

    void setGLStates();
    void unsetGLStates();

    MeshFactory* meshFactory;

    GLfloat lightPos[4] {0.f, 0.f, 10.f, 1.f};
    GLfloat lightAmb[4] {.1f, .1f, .1f, 1.f};
    GLfloat lightDif[4] {.8f, .8f, .8f, 1.f};

    ECS::ComponentManager<Visibility>* visibilityComponents;
    ECS::ComponentManager<Movement>* movementComponents;
};
