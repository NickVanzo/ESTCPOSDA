//
// Created by Nicolò Vanzo on 27/09/23.
//
#include "MyEngine.h"
#include "../FishSpawner/FishSpawner.h"
#pragma once

class GameManager: public MyEngine::Component {
public:
    ~GameManager();
    void Init();
    void CreateFishSpawner();
    float points = 0;
    void Update(float);
    std::shared_ptr<MyEngine::GameObject> player;
    std::shared_ptr<MyEngine::GameObject> upperSpawner;
    std::shared_ptr<MyEngine::GameObject> lowerSpawner;
    std::shared_ptr<MyEngine::CollisionContext> ctx;
    std::vector< std::shared_ptr<MyEngine::GameObject>> fishes;

};
