#include "BoxColliderComponent.h"
#include "Strategy.h"

#pragma oncew
namespace  MyEngine {
    struct BoxColliderPoints {
        glm::vec2 upLeft;
        glm::vec2 upRight;
        glm::vec2 downLeft;
        glm::vec2 downRight;
    };
    class ConcreteStrategyAABB : public MyEngine::Strategy {
    public:
        bool checkCollision(std::shared_ptr<MyEngine::Component> bc1, std::shared_ptr<MyEngine::Component> bc2);
    private:
        std::shared_ptr<BoxColliderPoints> buildColliderPoints(std::shared_ptr<MyEngine::BoxColliderComponent>);
    };
}