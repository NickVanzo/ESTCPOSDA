#include "Component.h"
#include "BoxColliderComponent.h"

namespace  MyEngine {
    class Strategy {

    public:
        virtual ~Strategy() = default;

        virtual bool checkCollision(std::shared_ptr<MyEngine::Component> bc1, std::shared_ptr<MyEngine::Component> bc2) const = 0;
        virtual bool checkCollisionAABB(std::shared_ptr<MyEngine::BoxColliderComponent> bc1, std::shared_ptr<MyEngine::BoxColliderComponent> bc2) const = 0;

    private:

    };
}