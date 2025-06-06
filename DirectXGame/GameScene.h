#pragma once
#include "KamataEngine.h"
#include "Effect.h"

class GameScene {
public:

	void Initialize();

	void Update();

	void Draw();

	~GameScene();

private:
	Model* modelEffect_ = nullptr;

	Camera camera_;

	

	std::list<Effect*> effectes_;
};