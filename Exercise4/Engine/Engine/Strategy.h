#include "Component.h"

namespace  MyEngine {
    class Strategy {

    public:
        virtual ~Strategy() = default;

        virtual std::string checkCollision(std::shared_ptr<Component> bc1, std::shared_ptr<Component> bc2) const = 0;
    private:

    };
}