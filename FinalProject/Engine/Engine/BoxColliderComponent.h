#include "Component.h"
#include "../../Simulation/Game/Fish/FishUpdateComponent.h"

#pragma once
namespace  MyEngine  {
    class BoxColliderComponent : public MyEngine::Component {

    public:
        void Update(float deltaTime) override;

        void setFish(Fishes::FishUpdateComponent _fish);

        bool getIsColliding();
        void setIsColliding(bool _isColliding);

        int getVerticalOffset();
        void setVerticalOffset(int _verticalOffset);

        int getHorizontalOffset();
        void setHorizontalOffset(int _horizontalOffset);

        glm::vec2 getCenter();
        void setCenter(glm::vec2 _center);

        void Collision(std::string _type);

        Fishes::FishUpdateComponent fish;
    
    private:
        bool isColliding = false;
        int verticalOffset = 1;
        int horizontalOffset = 1;
        glm::vec2 center = glm::vec2(0, 1);
    };
}