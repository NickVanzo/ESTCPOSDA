

namespace  MyEngine {
    class ConcreteStrategyAABB : public MyEngine::Strategy {

    public:
        std::string checkCollision(std::shared_ptr<BoxCollider> bc1, std::shared_ptr<BoxCollider> bc2) const override;

    private:

    };
}