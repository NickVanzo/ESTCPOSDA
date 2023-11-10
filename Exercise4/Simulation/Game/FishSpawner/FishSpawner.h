//
// Created by Nicolò Vanzo on 25/09/23.
//

#include "GameObject.h"
#include "Component.h"

#pragma once
namespace Simulation {
    class FishSpawner: public MyEngine::Component {
    public:
        FishSpawner(int, std::shared_ptr<MyEngine::GameObject> player, std::weak_ptr<MyEngine::GameObject> parent);
        void Update(float deltaTime);
        void SpawnFish();
        std::vector<std::shared_ptr<MyEngine::GameObject>> CheckFishCollisionWithBounderiesOrPlayer();
        std::vector<std::shared_ptr<MyEngine::GameObject>> ChecksFishCollisionsWithLasers();
    private:
        std::shared_ptr<MyEngine::GameObject> player;
        float TIME_TO_SPAWN_FISH = 1;
        float timeCounter = 0;
        int direction;
        float fishRadius = 120.0f;
    };
}


