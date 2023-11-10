#include "Component.h"

namespace  BoxCollider  {
    class BoxColliderComponent : public MyEngine::Component {

    public:
        bool getIsColliding();
        void setIsColliding(bool _isColliding);

        int getVerticalOffset();
        void setVerticalOffset(int _verticalOffset);

        int getHorizontalOffset();
        void setHorizontalOffset(int _horizontalOffset);

        glm::vec2 getCenter();
        void setCenter(glm::vec2 _center);

    private:
        bool isColliding = false;
        int verticalOffset = 1;
        int horizontalOffset = 1;
        glm::vec2 center = glm::vec2(0, 1);
    };
}