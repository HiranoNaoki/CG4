#include "GameScene.h"
#include <random>

using namespace KamataEngine;
using namespace MathUtility;




void GameScene::Initialize() {
	modelEffect_ = Model::CreateFromOBJ("Hishigata", true);

	
	camera_.Initialize();

	//Vector3 position = {0.0f, 0.0f, 0.0f};

	
	
	effect_ = new Effect();
	
	//effect_->Initialize(modelEffect_);

	for (int i = 0; i < 10; i++) {
		
		Effect* effect = new Effect();
		
		Vector3 pos = Vector3(0.0f, 0.0f, 0.0f);
		
		effect->Initialize(modelEffect_, pos);
		
		effectes_.push_back(effect);
	}
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