//
// Created by Nicolò Vanzo on 25/09/23.
//

#include "FishUpdateComponent.h"
#include "../Enums/FishSpawnerPositions.h"
#pragma once
namespace Simulation {
    using namespace glm;
    FishUpdateComponent::FishUpdateComponent(std::weak_ptr<MyEngine::GameObject> p) {
        _gameObject = p;
    }
    void FishUpdateComponent::SetDirection(int direction) {
        this->direction = direction;
    }
    void FishUpdateComponent::Update(float deltaTime) {
        std::weak_ptr<MyEngine::GameObject> parent = GetGameObject();
        if(direction == LOWER) {
            parent.lock().get()->position += velocity;
        } else if(direction == UPPER) {
            parent.lock().get()->position -= velocity;
        } else {}
        parent.lock().get()->rotation += + 1 * speed;
    }
}