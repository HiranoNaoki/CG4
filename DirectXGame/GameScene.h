#pragma once
#include "KamataEngine.h"
#include"Effect.h"
#include "Particle.h"

//using namespace KamataEngine;

class GameScene {
public:
	GameScene();

	~GameScene();

	void Initialize();

	void Update();

	void Draw();

	

	private:
		
	
	Camera camera_;

	Model* modelEffect_;

	Effect* effect_ = nullptr;
};