#include "Component.h"
#include "Strategy.h"
#include "BoxColliderComponent.h"
#include "FishColliderComponent.h"
#pragma once
namespace  MyEngine {
    class CollisionContext {

    public:
        explicit CollisionContext(std::unique_ptr<Strategy>&& strategy = {}) : strategy_(std::move(strategy)) {}

        void SetStrategy(std::unique_ptr<Strategy>&& strategy);

        void CheckAABBCollisions();
        void CheckAABBCollision(std::shared_ptr<BoxColliderComponent> bc1, std::shared_ptr<BoxColliderComponent> bc2) const;

        void CheckGJKCollisions();
        void CheckGJKCollision(std::shared_ptr<FishColliderComponent> bc1, std::shared_ptr<FishColliderComponent> bc2) const;

    private:
        std::unique_ptr<Strategy> strategy_;
    };
}