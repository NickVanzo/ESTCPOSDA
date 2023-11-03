//
// Created by Nicolò Vanzo on 27/09/23.
//
#include "MyEngine.h"
#include "../AsteroidSpawner/FishSpawner.h"
#pragma once

class GameManager {
public:
    ~GameManager();
    void StartGame();
    void CreateAsteroidSpawner();
    float points = 0;
    std::shared_ptr<MyEngine::GameObject> player;
    std::shared_ptr<MyEngine::GameObject> upperSpawner;
    std::shared_ptr<MyEngine::GameObject> lowerSpawner;
};
