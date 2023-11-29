//
// Created by Nicolò Vanzo on 25/09/23.
//

#include "GameObject.h"
#include "Component.h"
#include "CollisionContext.h"
#pragma once
namespace Fishes {
    class FishSpawner: public MyEngine::Component {
    public:
        FishSpawner(int direction, std::weak_ptr<MyEngine::GameObject> parent);
        void Update(float deltaTime);
        void SpawnFish();
        void SetMaxFishCount(int _maxFishCount);
        void SetFishType(std::string _type);


    private:
        std::shared_ptr<MyEngine::CollisionContext> ctx;
        std::vector< std::shared_ptr<MyEngine::GameObject>> fishes;
        float TIME_TO_SPAWN_FISH = 1;
        int fishCount = 0;
        int maxFishCount = 5;
        float timeCounter = 0;
        int direction;
        float fishRadius = 120.0f;
        std::string fish;
    };
}


