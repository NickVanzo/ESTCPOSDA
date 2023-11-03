//
// Created by Nicolò Vanzo on 25/09/23.
//

#include "GameObject.h"
#include "Component.h"

#pragma once
namespace Fishes {
    class FishSpawner: public MyEngine::Component {
    public:
        FishSpawner(int, std::shared_ptr<MyEngine::GameObject> player, std::weak_ptr<MyEngine::GameObject> parent);
        void Update(float deltaTime);
        void SpawnAsteroid();
        std::vector<std::shared_ptr<MyEngine::GameObject>> CheckAsteroidCollisionWithBounderiesOrPlayer();
        std::vector<std::shared_ptr<MyEngine::GameObject>> ChecksAsteroidCollisionsWithLasers();
    private:
        std::shared_ptr<MyEngine::GameObject> player;
        float TIME_TO_SPAWN_ASTEROID = 1;
        float timeCounter = 0;
        int direction;
        float asteroidsRadius = 120.0f;
    };
}


