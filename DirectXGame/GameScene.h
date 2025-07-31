#pragma once
#include "KamataEngine.h"
#include "Particle.h"
#include "Model2.h"
#include "Guraf.h"
#include "num.h"

using namespace KamataEngine;

class GameScene {
public:
	~GameScene();

	void Initialize();

	void Update();

	void Draw();

private:
	Model2* modelParticle_ = nullptr;

	Camera camera_;

	Particle* particle_ = nullptr;
	uint32_t textureHandle = 0;

	KamataEngine::Sprite* sprite_ = nullptr;

	
	KamataEngine::Sprite* sprite_2 = nullptr;

	float move = 3;

	int frame = 0;

	Guraf* guraf_ = nullptr;

	Num* number_ = nullptr;


};