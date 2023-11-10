//
// Created by Nicolò Vanzo on 25/09/23.
//

#include "FishUpdateComponent.h"
#include "../Enums/FishSpawnerPositions.h"
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/rotate_vector.hpp>
#include "MyEngine.h"


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

        if (swayTimer < 0) {
            swayTimer = (rand() % 3) + 1;
            swayDir = int (rand() % 3) - 1;
            while (swayDir == 0) {
                swayDir = int(rand() % 2) - 1;
            }
            swayCount = 0;
            parent.lock().get()->rotation += (swayDir);

        } 
        else if (swayCount < swayAmount) {
            parent.lock().get()->rotation += (swayDir);
            parent.lock().get()->position += glm::rotate(
                originDirection,
                glm::radians(parent.lock().get()->rotation)
            ) * speed;
            swayCount += abs(swayDir);

        }
        else {
            parent.lock().get()->position += glm::rotate(
                originDirection, 
                glm::radians(parent.lock().get()->rotation)
            ) * speed;
            swayTimer -= deltaTime;
        }

        
        CheckWrap();


    }

    void FishUpdateComponent::CheckWrap() {
        std::weak_ptr<MyEngine::GameObject> parent = GetGameObject();

        glm::vec2 screenSize = MyEngine::Engine::GetInstance()->GetScreenSize();

        float _x = parent.lock().get()->position.x;
        float _y = parent.lock().get()->position.y;

        if (_x < 0) {
            parent.lock().get()->position.x = screenSize.x;
        } 
        else if (screenSize.x < _x) {
            parent.lock().get()->position.x = 0;
        }
        if (_y < 0) {
            parent.lock().get()->position.y = screenSize.y;
        }
        else if (screenSize.y < _y) {
            parent.lock().get()->position.y = 0;
        }
    }
}