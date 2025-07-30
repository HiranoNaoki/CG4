#pragma once
#include "KamataEngine.h"

class GameScene {
public:
	GameScene();
	~GameScene();

	void Initialize();

	void Update();

	void Draw();

private:
	uint32_t textureHandle = 0;

	KamataEngine::Sprite* sprite_ = nullptr;

	
	KamataEngine::Sprite* sprite_2 = nullptr;

	float move = 3;

	int frame = 0;
};