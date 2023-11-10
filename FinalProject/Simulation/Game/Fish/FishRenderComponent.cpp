//
// Created by Nicolò Vanzo on 25/09/23.
//
#include "FishRenderComponent.h"
namespace Fishes {
    using namespace std;
    FishRenderComponent::FishRenderComponent(std::weak_ptr<MyEngine::GameObject> p) {
        _gameObject = p;
    }
    void FishRenderComponent::Render(sre::SpriteBatch::SpriteBatchBuilder & builder) {
        std::weak_ptr<MyEngine::GameObject> parent = GetGameObject();
        sprite.setPosition(parent.lock().get()->position);
        sprite.setRotation(parent.lock().get()->rotation);
        sprite.setScale(glm::vec2(0.1, 0.1));
        builder.addSprite(sprite);
    }
}
