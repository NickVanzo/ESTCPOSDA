#include "BoxColliderComponent.h"
#include "Strategy.h"

#pragma oncew
namespace  MyEngine {
    class ConcreteStrategyAABB : public MyEngine::Strategy {
    public:
        std::string checkCollision(std::shared_ptr<BoxColliderComponent> bc1, std::shared_ptr<BoxColliderComponent> bc2) const override;
    private:

    };
}