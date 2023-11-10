//
// Created by Nicolò Vanzo on 25/09/23.
//

#include "GameObject.h"
#include "Component.h"

#pragma once
namespace Fishes {
    class FishSpawner: public MyEngine::Component {
    public:
        FishSpawner(int direction, std::weak_ptr<MyEngine::GameObject> parent);
        void Update(float deltaTime);
        void SpawnFish();

    private:
        float TIME_TO_SPAWN_FISH = 1;
        float timeCounter = 0;
        int direction;
        float fishRadius = 120.0f;
    };
}


