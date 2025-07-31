#pragma once
#include <2d/Sprite.h>
#include <KamataEngine.h>

class Guraf {

public:
	Guraf();

	~Guraf();

	void Initialize();

	void Update();

	void Draw();

private:
	std::vector<KamataEngine::Sprite*> GurafSprite_;

	uint32_t textureHandle_;

	int red = 0;
	int Green = 1;

	const int maxHP = 2;
	const KamataEngine::Vector2 startPos = {50, 50}; 
	const KamataEngine::Vector2 size = {100, 20};    
};

