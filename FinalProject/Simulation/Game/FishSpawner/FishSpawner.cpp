//
// Created by Nicolò Vanzo on 25/09/23.
//
#include "FishSpawner.h"
#include "../Fish/FishRenderComponent.h"
#include "../Fish/FishUpdateComponent.h"
#include "MyEngine.h"
#include "../Enums/FishSpawnerPositions.h"
#include <cstdlib>
#include "../Constants/Engine.h"
#include "../GameManager/GameManager.h"

namespace Fishes {
    using namespace glm;
    using namespace std;
    FishSpawner::FishSpawner(int direction, std::weak_ptr<MyEngine::GameObject> parent):
    direction(direction){
        _gameObject = parent;
    }

    void FishSpawner::Update(float deltaTime) {
        timeCounter -= deltaTime;
        if((timeCounter < 0) && (fishCount < maxFishCount)) {
            ++fishCount;
            std::cout << fishCount << std::endl;
            SpawnFish();
            timeCounter = TIME_TO_SPAWN_FISH;
        }

        ///////////////////////////////////////////// COLLISION CHECK EXAMPLE //////////////////////////////////////////////
        /*auto objectsCollidingWithLasers = ChecksFishCollisionsWithLasers();
        if(!objectsCollidingWithLasers.empty()) {
            for(const auto & i : objectsCollidingWithLasers) {
                MyEngine::Engine::GetInstance()->RemoveObject(i);
            }
        }*/
    }

    void FishSpawner::SpawnFish() {
        MyEngine::Engine* engine = MyEngine::Engine::GetInstance();
        auto gameObject = engine->CreateGameObject("fish");
        std::weak_ptr<MyEngine::GameObject> obj = gameObject;
        auto fishRenderComponent = std::make_shared<Fishes::FishRenderComponent>(obj);
        auto fishUpdateComponent = std::make_shared<Fishes::FishUpdateComponent>(obj);

        fishRenderComponent->sprite = engine->atlas->get("clown-fish.png");
        gameObject->rotation = rand() % 360 - 180;

        float randX = 0;
        float randY = 0;

        /////////////////////////////////////// CHANGE WHEN FISHUPDATECOMPONENT HAS BEEN CAHNGED//////////////////////////////////
        if(direction == LOWER) {
            //spawn only along the lower part of the screen
            randX = rand() % (int) CUSTOM_WINDOW_WIDTH;
            randY = 10;
            fishUpdateComponent->SetDirection(LOWER);
        } else if(direction == UPPER) {
            //spawn only along the upper part of the screen
            randY = CUSTOM_WINDOW_HEIGHT + 100;
            randX = rand() % (int) CUSTOM_WINDOW_WIDTH;
            fishUpdateComponent->SetDirection(UPPER);
        }
        gameObject->position = glm::vec2(randX,randY);
        gameObject->AddComponent(fishRenderComponent);
        gameObject->AddComponent(fishUpdateComponent);

    }

    void FishSpawner::SetMaxFishCount(int _maxFishCount) {
        maxFishCount = _maxFishCount;
    }

    void FishSpawner::SetFishType(std::string _type) {
        fish = _type;
    }

    ///////////////////////////////////////////// COLLISION CHECK EXAMPLE //////////////////////////////////////////////
    /*std::vector<std::shared_ptr<MyEngine::GameObject>> FishSpawner::ChecksFishCollisionsWithLasers() {
        MyEngine::Engine* engine = MyEngine::Engine::GetInstance();
        std::vector<std::shared_ptr<MyEngine::GameObject>> objectsToRemove = {};
        auto gameManager = engine->GetGameManager();
        for(int i = 0; i < engine->gameObjects.size(); i++) {
            auto fishGameObject = engine->gameObjects[i];
            if(fishGameObject == nullptr) continue;
            if(fishGameObject->GetName() == "fish") {
                for(int j = 0; j < engine->gameObjects.size(); j++) {
                    if(engine->gameObjects[j]->GetName() == "bullet") {
                        auto bulletGameObject = engine->gameObjects[j];
                        float distanceBetweenLaserAndfish = pow(fishGameObject->position.y - bulletGameObject->position.y, 2) + pow(fishGameObject->position.x - bulletGameObject->position.x, 2);
                        bool areTwoObjectsColliding = distanceBetweenLaserAndfish <= pow(fishRadius + bulletGameObject->radius, 2);
                        if(areTwoObjectsColliding) {
                            gameManager->points++;
                            std::cout << gameManager->points << std::endl;
                            objectsToRemove.push_back(bulletGameObject);
                            objectsToRemove.push_back(fishGameObject);
                        }
                        if(!areTwoObjectsColliding && bulletGameObject->timeAlive > 1) {
                            objectsToRemove.push_back(bulletGameObject);
                        }
                    }
                }
            }
        }
        return objectsToRemove;
    }*/

}