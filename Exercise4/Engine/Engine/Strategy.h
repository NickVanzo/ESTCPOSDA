#include "Component.h"

namespace  MyEngine {
    class Strategy {

    public:
        virtual ~Strategy() = default;

        virtual std::string checkCollision(std::shared_ptr<BoxCollider> bc1, std::shared_ptr<BoxCollider> bc2) const = 0;

    private:

    };
}