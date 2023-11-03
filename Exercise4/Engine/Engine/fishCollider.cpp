#include "fishCollider.h"

namespace MyEngine {
    using namespace MyEngine;
    

    bool getIsColliding()
    {
        return isColliding;
    }


    void setIsColliding(bool _isColliding)
    {
        isColliding = _isColliding;
    }


    std::list<glm::vec2> getNodes()
    {
        if (nodes)
        {
            return nodes;
        }
        else
        {
            std::cout << "fishCollider: No nodes in collision object\n";
        }
    }


    void setNodes(std::list<glm::vec2> _nodes)
    {
        nodes = _nodes;
    }


    glm::vec2 getCenter()
    {
        return center;
    }


    void setCenter(glm::vec2 _center)
    {
        center = _center;
    }
}
