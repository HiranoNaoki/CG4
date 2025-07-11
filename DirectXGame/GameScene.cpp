#include "GameScene.h"
#include <cmath>

using namespace KamataEngine;

void GameScene::Initialize() {

	textureHandle = TextureManager::Load("start.png");

	sprite_ = Sprite::Create(textureHandle, {0, 0});
}

void GameScene::Update() { frame++;

float y = 45 * sin(frame * 0.05f);

sprite_->SetPosition({0.0f, y});
}

void GameScene::Draw() { 
	
	DirectXCommon* dxCommon = DirectXCommon::GetInstance();
	Sprite::PreDraw(dxCommon->GetCommandList());


	//if (frame %60 >=30) {
		sprite_->Draw();
	//}
	
	Sprite::PostDraw(); 
}
GameScene::GameScene() {}

GameScene::~GameScene() {}