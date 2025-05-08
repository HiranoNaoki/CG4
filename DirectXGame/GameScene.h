#pragma once
#include "KamataEngine.h"
#include "Particle.h"

using namespace KamataEngine;

class GameScene {
public:
	~GameScene();

	void Initialize();

	void Update();

	void Draw();

	Model* modelParticle_ = nullptr;

	Camera camera_;

	Particle* particle_ = nullptr;

	std::list<Particle*> particles_;

};