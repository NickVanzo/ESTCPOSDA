#include "CollisionContext.h"
#include "BoxColliderComponent.h"
#include "CollisionContext.h"
#include "FishColliderComponent.h"
#include "../../Simulation/Game/Fish/FishUpdateComponent.h"
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

    void CollisionContext::CheckAABBCollision(std::shared_ptr<Component> bc1, std::shared_ptr<Component> bc2) const
    {
        if (strategy_) 
        {
           bool result = strategy_->checkCollision(bc1, bc2);

           if (result) 
           {
               //(BoxColliderComponent)bc1->fish;

               BoxColliderComponent* collider1 = dynamic_cast<BoxColliderComponent*>(bc1.get());
               auto fish1 = collider1->fish;
               std::string type1 = fish1.fishType;

               BoxColliderComponent* collider2 = dynamic_cast<BoxColliderComponent*>(bc2.get());
               auto fish2 = collider2->fish;
               std::string type2 = fish2.fishType;

               if ((type1 == "predator" || type2 == "predator") && (type1 != type2))
               {
                   glm::vec2 pos1 = collider1->getCenter;
                   glm::vec2 pos2 = collider2->getCenter;

                   float Distance = sqrt(())

                   if (type1 == "predator")
                   {

                   }
                   else
                   {

                   }
               }

           }
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

    void CollisionContext::CheckGJKCollision(std::shared_ptr<Component> bc1, std::shared_ptr<Component> bc2) const
    {
        if (strategy_) 
        {
            bool result = strategy_->checkCollision(bc1, bc2);
        }
        else 
        {
            std::cout << "CollisionContext-GJK: Strategy isn't set\n";
        }
    }

}
