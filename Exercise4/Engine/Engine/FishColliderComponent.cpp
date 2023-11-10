#include "FishColliderComponent.h"

namespace MyEngine {
    using namespace MyEngine;
    

    bool FishColliderComponent::getIsColliding() {
        return isColliding;
    }

    void FishColliderComponent::setIsColliding(bool _isColliding)
    {
        isColliding = _isColliding;
    }


    std::list<glm::vec2> FishColliderComponent::getNodes()
    {
        return nodes;
    }


    void FishColliderComponent::setNodes(std::list<glm::vec2> _nodes)
    {
        nodes = _nodes;
    }


    glm::vec2 FishColliderComponent::getCenter()
    {
        return center;
    }


    void FishColliderComponent::setCenter(glm::vec2 _center)
    {
        center = _center;
    }
}
