#pragma once
#include <vector>
#include <initializer_list>
#include "ComponentManagerBase.hpp"
#include "Id.hpp"

namespace ECS {

class System
{

public:

    System(std::initializer_list<ComponentManagerBase*> c);

    virtual ~System() = default;

    virtual void initialize();
    virtual void update();
    virtual void update(float time);

    std::vector<id>* getEntities();

private:

    void onEntityAdded(id entity);
    void onEntityRemoved(id entity);

    std::vector<id> entities {};
    std::vector<ComponentManagerBase*> componentManagers {};
};
}
