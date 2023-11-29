//
// Created by Nicolò Vanzo on 27/09/23.
//
#include "sre/SDLRenderer.hpp"
#include "sre/SpriteAtlas.hpp"
#include "Engine/MyEngine.h"
#include "../Enums/FishSpawnerPositions.h"
#include "GameManager.h"
#include "ConcreteStrategyAABB.h"

GameManager::~GameManager() {
    std::cout << "Distruttore game manager" << std::endl;
}
void GameManager::Init() {
    CreateFishSpawner();
    ctx = std::make_shared<MyEngine::CollisionContext>();
    ctx->SetStrategy(std::make_unique<MyEngine::ConcreteStrategyAABB>());
}

void GameManager::Update(float deltaTime) {

}

void GameManager::CreateFishSpawner() {
    MyEngine::Engine* engine = MyEngine::Engine::GetInstance();

    lowerSpawner = engine->CreateGameObject("FishSpawner");
    auto lowerSpawnerUpdateComponent = std::make_shared<Fishes::FishSpawner>(Fishes::LOWER, lowerSpawner);
    lowerSpawnerUpdateComponent->SetFishType("predator");
    lowerSpawnerUpdateComponent->SetMaxFishCount(5);
    lowerSpawner->AddComponent(lowerSpawnerUpdateComponent);

    upperSpawner = engine->CreateGameObject("FishSpawner");
    auto upperSpawnerUpdateComponent = std::make_shared<Fishes::FishSpawner>(Fishes::UPPER, upperSpawner);
    upperSpawnerUpdateComponent->SetMaxFishCount(5);
    upperSpawner->AddComponent(upperSpawnerUpdateComponent);
}