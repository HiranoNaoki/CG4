#include "GameScene.h"

using namespace KamataEngine;

void GameScene::Initialize() {
	modelEffect_ = Model::CreateFromOBJ("Hishigata", true);

	
	camera_.Initialize();

	Vector3 position = {0.0f, 0.0f, 0.0f};

	
	effect_ = new Effect();
	
	effect_->Initialize(modelEffect_, position);
}

void GameScene::Update() { 
	effect_->Update(); 
}

void GameScene::Draw() {
	DirectXCommon* dxCommon = DirectXCommon::GetInstance();
	
	Model::PreDraw(dxCommon->GetCommandList());
	
	effect_->Draw(camera_);

	
	Model::PostDraw();
}

GameScene::~GameScene() { 
	delete modelEffect_;
	delete effect_;
}