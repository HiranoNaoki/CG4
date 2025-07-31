#pragma once
#include <KamataEngine.h>

class Num {

public:
	Num();
	~Num();

	void Initialize();

	void Update();

	void Draw();

	void SetNum(int value);

private:
	uint32_t textureHandle_;
	std::vector<KamataEngine::Sprite*> NumSprite_;

	const KamataEngine::Vector2 size = {32.0f, 64.0f}; // 各数字のサイズ
	const KamataEngine::Vector2 startPos = {1200, 50}; // 表示開始位置（右から左）

	int number_ = 0;       
	int frameCounter_ = 0; 
};