#include "BoxColliderComponent.h"
#include "Strategy.h"

namespace  MyEngine {
    class ConcreteStrategyGJK : public MyEngine::Strategy {

    public:
        bool checkCollision(std::shared_ptr<Component> bc1, std::shared_ptr<Component> bc2) const override;
    private:

    };
}