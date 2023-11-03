//
// Created by Nicolò Vanzo on 27/09/23.
//
#include "sre/SDLRenderer.hpp"
#include "sre/SpriteAtlas.hpp"
#include "Engine/MyEngine.h"
#include "../Enums/AsteroidSpawnerPositions.h"
GameManager::~GameManager() {
    std::cout << "Distruttore game manager" << std::endl;
}
void GameManager::StartGame() {
    CreateAsteroidSpawner();
}

void GameManager::CreateAsteroidSpawner() {
    MyEngine::Engine* engine = MyEngine::Engine::GetInstance();
    lowerSpawner = engine->CreateGameObject("asteroidSpawner");
    auto lowerSpawnerUpdateComponent =std::make_shared<Asteroids::AsteroidSpawner>(Asteroids::LOWER, player, lowerSpawner);
    lowerSpawner->AddComponent(lowerSpawnerUpdateComponent);

    upperSpawner = engine->CreateGameObject("asteroidSpawner");
    auto upperSpawnerUpdateComponent = std::make_shared<Asteroids::AsteroidSpawner>(Asteroids::UPPER, player, upperSpawner);
    upperSpawner->AddComponent(upperSpawnerUpdateComponent);
}