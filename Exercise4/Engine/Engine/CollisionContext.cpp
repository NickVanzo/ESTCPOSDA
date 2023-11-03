#include "CollisionContext.h"

namespace MyEngine {
    using namespace MyEngine;

    explicit CollisionContext::CollisionContext(std::unique_ptr<Strategy>&& strategy = {}) : strategy_(std::move(strategy))
    {
        // Should be empty
    }

    void CollisionContext::setStrategy(std::unique_ptr<Strategy>&& strategy)
    {
        strategy_ = std::move(strategy);
    }

    void checkAABBCollisions()
    {
        // get list of collision objects and chack each object
        // against each other with checkCollision function
    }

    void CollisionContext::checkAABBCollision(std::shared_ptr<BoxCollider> bc1, std::shared_ptr<BoxCollider> bc2) const
    {
        if (strategy_) {
}           std::string result = strategy_->checkCollision(bc1, bc2);
        }
        else {
            std::cout << "CollisionContext: Strategy isn't set\n";
        }
    }

}
