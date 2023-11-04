#include "CollisionContext.h"
#include "BoxColliderComponent.h"
#include "CollisionContext.h"
#include "FishColliderComponent.h"
namespace MyEngine {
    using namespace MyEngine;

    void CollisionContext::SetStrategy(std::unique_ptr<Strategy>&& strategy)
    {
        strategy_ = std::move(strategy);
    }

    void CollisionContext::CheckAABBCollisions()
    {
        // get list of collision objects and check each object
        // against each other with checkCollision function
    }

    void CollisionContext::CheckAABBCollision(std::shared_ptr<BoxColliderComponent> bc1, std::shared_ptr<BoxColliderComponent> bc2) const
    {
        if (strategy_) 
        {
           std::string result = strategy_->checkCollision(bc1, bc2);
        }
        else 
        {
            std::cout << "CollisionContext-AABB: Strategy isn't set\n";
        }
    }

    void CollisionContext::CheckGJKCollisions()
    {
        // get list of collision objects and check each object
        // against each other with checkCollision function
    }

    void CollisionContext::CheckGJKCollision(std::shared_ptr<FishColliderComponent> bc1, std::shared_ptr<FishColliderComponent> bc2) const
    {
        if (strategy_) 
        {
            std::string result = strategy_->checkCollision(bc1, bc2);
        }
        else 
        {
            std::cout << "CollisionContext-GJK: Strategy isn't set\n";
        }
    }

}
