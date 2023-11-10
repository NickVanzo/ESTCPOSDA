//
// Created by Nicolò Vanzo on 27/09/23.
//
#include "sre/SDLRenderer.hpp"
#include "sre/SpriteAtlas.hpp"
#include "Engine/MyEngine.h"
#include "../Enums/FishSpawnerPositions.h"
#include "GameManager.h"

GameManager::~GameManager() {
    std::cout << "Distruttore game manager" << std::endl;
}
void GameManager::StartGame() {
    CreateFishSpawner();
}

void GameManager::CreateFishSpawner() {
    MyEngine::Engine* engine = MyEngine::Engine::GetInstance();

    lowerSpawner = engine->CreateGameObject("FishSpawner");
    auto lowerSpawnerUpdateComponent = std::make_shared<Fishes::FishSpawner>(Fishes::LOWER, lowerSpawner);
    lowerSpawner->AddComponent(lowerSpawnerUpdateComponent);

    upperSpawner = engine->CreateGameObject("FishSpawner");
    auto upperSpawnerUpdateComponent = std::make_shared<Fishes::FishSpawner>(Fishes::UPPER, upperSpawner);
    upperSpawner->AddComponent(upperSpawnerUpdateComponent);
}