//
// Created by Nicolò Vanzo on 27/09/23.
//
#include "sre/SDLRenderer.hpp"
#include "sre/SpriteAtlas.hpp"
#include "Engine/MyEngine.h"
#include "../Enums/FishSpawnerPositions.h"
GameManager::~GameManager() {
    std::cout << "Distruttore game manager" << std::endl;
}
void GameManager::StartGame() {
    CreateFishSpawner();
}

void GameManager::CreateFishSpawner() {
    MyEngine::Engine* engine = MyEngine::Engine::GetInstance();
    lowerSpawner = engine->CreateGameObject("fishSpawner");
    auto lowerSpawnerUpdateComponent =std::make_shared<Simulation::FishSpawner>(Simulation::LOWER, player, lowerSpawner);
    lowerSpawner->AddComponent(lowerSpawnerUpdateComponent);

    upperSpawner = engine->CreateGameObject("fishSpawner");
    auto upperSpawnerUpdateComponent = std::make_shared<Simulation::FishSpawner>(Simulation::UPPER, player, upperSpawner);
    upperSpawner->AddComponent(upperSpawnerUpdateComponent);
}