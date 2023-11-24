#include "BoxColliderComponent.h"
#include "Strategy.h"

#pragma oncew
namespace  MyEngine {
    class ConcreteStrategyAABB : public MyEngine::Strategy {
    public:
        bool checkCollision(std::shared_ptr<Component> bc1, std::shared_ptr<Component> bc2) const;
    private:

    };
}