#include "Component.h"

namespace  MyEngine  {
    class FishColliderComponent : public MyEngine::Component {

    public:
        bool getIsColliding();
        void setIsColliding(bool _isColliding);

        std::list<glm::vec2> getNodes();
        void setNodes(std::list<glm::vec2> _nodes);

        glm::vec2 getCenter();
        void setCenter(glm::vec2 _center);

    private:
        bool isColliding = false;

        std::list<glm::vec2> nodes = 0;
        glm::vec2 center = glm::vec2(0, 1);
    };
}