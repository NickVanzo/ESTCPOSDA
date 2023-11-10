//
// Created by Nicolò Vanzo on 25/09/23.
//

#include "FishUpdateComponent.h"
#include "../Enums/FishSpawnerPositions.h"
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/rotate_vector.hpp>


#pragma once
namespace Fishes {
    using namespace glm;
    FishUpdateComponent::FishUpdateComponent(std::weak_ptr<MyEngine::GameObject> p) {
        _gameObject = p;
    }
    void FishUpdateComponent::SetDirection(int direction) {
        this->direction = direction;
    }
    void FishUpdateComponent::Update(float deltaTime) {
        std::weak_ptr<MyEngine::GameObject> parent = GetGameObject();
        parent.lock().get()->position += glm::rotate(originDirection, glm::radians(parent.lock().get()->rotation))*speed;
    }
}