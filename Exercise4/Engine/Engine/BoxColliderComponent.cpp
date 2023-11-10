#include "BoxColliderComponent.h"

namespace MyEngine {
    using namespace MyEngine;
    
    /*
    Returns true if BoxCollider has collided with another collision object.
    */
    bool BoxColliderComponent::getIsColliding()
    {
        return isColliding;
    }
    
    /*
    _isColliding -> true if collision, false if not.
    */
    void BoxColliderComponent::setIsColliding(bool _isColliding)
    {
        isColliding = _isColliding;
    }

    /*
    returns the vertical offset of the BoxCollider.

    --------------------------------------------
    |                     |                     |
    |                     | <- offset           |
    |                     |                     |
    |                     c                     |
    |                     |                     |
    |                     | <- offset           |
    |                     |                     |
    --------------------------------------------

    */
    int BoxColliderComponent::getVerticalOffset()
    {
        return verticalOffset;
    }

    /*
    sets the vertical offset of the BoxCollider.

    --------------------------------------------
    |                     |                     |
    |                     | <- offset           |
    |                     |                     |
    |                     c                     |
    |                     |                     |
    |                     | <- offset           |
    |                     |                     |
    --------------------------------------------

    */
    void BoxColliderComponent::setVerticalOffset(int _verticalOffset)
    {
        verticalOffset = _verticalOffset;
    }

    /*
    returns the Horizontal offset of the BoxCollider.

    --------------------------------------------
    |                                           |
    |                                           |
    |                                           |
    | ------------------- c ------------------- |
    |          ^                     ^          |
    |        offset                offset       |
    |                                           |
    --------------------------------------------

    */
    int BoxColliderComponent::getHorizontalOffset()
    {
        return 1;
    }
    
    /*
    returns the Horizontal offset of the BoxCollider.

    --------------------------------------------
    |                                           |
    |                                           |
    |                                           |
    | ------------------- c ------------------- |
    |          ^                     ^          |
    |        offset                offset       |
    |                                           |
    --------------------------------------------

    */
    void BoxColliderComponent::setHorizontalOffset(int _horizontalOffset)
    {
        horizontalOffset = _horizontalOffset;
    }

    /*
    returns the Center of the BoxCollider.
    
    --------------------------------------------
    |                                           |
    |                                           |
    |                                           |
    |                     c  <- Center          |
    |                                           |
    |                                           |
    |                                           |
    --------------------------------------------
    */
    glm::vec2 BoxColliderComponent::getCenter()
    {
        return center;
    }
    
    /*
    sets the Center of the BoxCollider.

    --------------------------------------------
    |                                           |
    |                                           |
    |                                           |
    |                     c  <- Center          |
    |                                           |
    |                                           |
    |                                           |
    --------------------------------------------
    */
    void BoxColliderComponent::setCenter(glm::vec2 _center)
    {
        center = _center;
    }
}
