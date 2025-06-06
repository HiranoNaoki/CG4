#include "GameScene.h"
#include <random>

using namespace KamataEngine;
using namespace MathUtility;




void GameScene::Initialize() {
	modelEffect_ = Model::CreateFromOBJ("Hishigata", true);

	
	camera_.Initialize();

	//Vector3 position = {0.0f, 0.0f, 0.0f};

	
	
	
	
	//effect_->Initialize(modelEffect_);

	for (int i = 0; i < 10; i++) {
		
		Effect* effect = new Effect();
		
		Vector3 pos = Vector3(0.0f, 0.0f, 0.0f);
		
		effect->Initialize(modelEffect_, pos);
		
		effectes_.push_back(effect);
	}
}

void GameScene::Update() { 

	for (Effect* effect : effectes_) {
	effect->Update(); 
	}
	
}

void GameScene::Draw() {
	DirectXCommon* dxCommon = DirectXCommon::GetInstance();
	
	Model::PreDraw(dxCommon->GetCommandList());
	
	

	for (Effect* effect : effectes_) {
	 effect->Draw(camera_);
	}
	
	Model::PostDraw();
}

GameScene::~GameScene() { 
	delete modelEffect_;
	for (Effect* effect : effectes_) {
	delete effect;
	}
	
}