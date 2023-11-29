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
        bool checkCollision(const std::shared_ptr<MyEngine::Component> bc1, const  std::shared_ptr<MyEngine::Component> bc2);
        bool checkCollisionAABB(const std::shared_ptr<MyEngine::BoxColliderComponent> bc1, const std::shared_ptr<MyEngine::BoxColliderComponent> bc2);
    private:
        std::shared_ptr<BoxColliderPoints> buildColliderPoints(std::shared_ptr<MyEngine::BoxColliderComponent>);
    };
}