#include "Component.h"

namespace  MyEngine {
    class CollisionContext {

    public:
        explicit CollisionContext(std::unique_ptr<Strategy>&& strategy = {}) : strategy_(std::move(strategy));

        void SetStrategy(std::unique_ptr<Strategy>&& strategy);

        void CheckAABBCollisions();
        void CheckAABBCollision(std::shared_ptr<BoxCollider> bc1, std::shared_ptr<BoxCollider> bc2) const;

        void CheckGJKCollisions();
        void CheckGJKCollision(std::shared_ptr<BoxCollider> bc1, std::shared_ptr<BoxCollider> bc2) const;

    private:
        std::unique_ptr<Strategy> strategy_;
    };
}