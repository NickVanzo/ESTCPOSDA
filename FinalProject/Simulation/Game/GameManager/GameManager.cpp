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
    auto fishes = lowerSpawner->FindComponent<Fishes::FishSpawner>().lock()->fishes;
    auto fishes2 = upperSpawner->FindComponent<Fishes::FishSpawner>().lock()->fishes;
    fishes.insert(fishes.end(), fishes2.begin(), fishes2.end());

    for(int i = 0; i < fishes.size(); i++) {
        auto bx1 = fishes[i]->FindComponent<MyEngine::BoxColliderComponent>();
        for(int j = i + 1; j < fishes.size() - 1; j++) {
            auto bx2 = fishes[j]->FindComponent<MyEngine::BoxColliderComponent>();
            ctx->CheckAABBCollision(std::dynamic_pointer_cast<MyEngine::Component>(bx1.lock()), std::dynamic_pointer_cast<MyEngine::Component>(bx2.lock()));
        }
    }
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