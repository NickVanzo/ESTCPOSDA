#include "Component.h"

namespace  BoxCollider  {
    class BoxColliderComponent : public MyEngine::Component {

    public:
        void setIsColliding(bool _isColliding);
        bool getIsColliding();
        int getVerticalOffset();
        void setVerticalOffset();
        int getHorizontalOffset();
        void setHorizontalOffset();
        glm::vec2 getCenter();
        void setCenter();

    private:
        bool isColliding = false;

        int verticalOffset = 1;
        int horizontalOffset = 1;
        glm::vec2 center = glm::vec2(0, 1);
    };
}