#include "GameScene.h"
#include <cmath>

using namespace KamataEngine;

void GameScene::Initialize() {

	textureHandle = TextureManager::Load("start.png");

	sprite_ = Sprite::Create(textureHandle, {0, 0});
	sprite_2 = Sprite::Create(textureHandle, {0, 0});
}

void GameScene::Update() { frame++;

float y = 45 * sin(frame * 0.05f);

move--;

float x = 0.0f + move;

sprite_->SetPosition({x, y});
sprite_2->SetPosition({1280 + x, y});
if (x <= -1280) {
	move = 0;
}
}

void GameScene::Draw() { 
	
	DirectXCommon* dxCommon = DirectXCommon::GetInstance();
	Sprite::PreDraw(dxCommon->GetCommandList());


	//if (frame %60 >=30) {
		sprite_->Draw();
	sprite_2->Draw();
	//}
	
	Sprite::PostDraw(); 
}
GameScene::GameScene() {}

GameScene::~GameScene() {}