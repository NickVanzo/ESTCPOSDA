//
// Created by Nicolò Vanzo on 24/11/23.
//
#include "ConcreteStrategyAABB.h"
#include "Component.h"
namespace MyEngine {
    bool ConcreteStrategyAABB::checkCollision(const std::shared_ptr<MyEngine::Component> bc1,
                                              const std::shared_ptr<MyEngine::Component> bc2) {

        return false;
    }
    bool ConcreteStrategyAABB::checkCollisionAABB(const std::shared_ptr<MyEngine::BoxColliderComponent> bc1,
                                                  const std::shared_ptr<MyEngine::BoxColliderComponent> bc2) {
        if (bc1 && bc2) {
            auto bc1Center = bc1->getCenter();
            auto bc2Center = bc2->getCenter();
            auto bc1Width = bc1->getHorizontalOffset() * 2;
            auto bc2Width = bc2->getHorizontalOffset() * 2;
            auto bc1Height = bc1->getVerticalOffset() * 2;
            auto bc2Height = bc2->getVerticalOffset() * 2;
            return bc1Center.x < bc2Center.x + bc2Width && bc1Center.x + bc1Width > bc2Center.x &&
                   bc1Center.y < bc2Center.y + bc2Height && bc1Height + bc1Center.y > bc2Center.y;
        } else {
            return false;
        }
    }
}