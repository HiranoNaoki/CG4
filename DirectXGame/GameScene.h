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

	void ParticleBorn(Vector3 position);

		Camera camera_;

		std::list<Particle*> particles_;

	private:

	Model* modelParticle_ = nullptr;



	Particle* particle_ = nullptr;

	

};