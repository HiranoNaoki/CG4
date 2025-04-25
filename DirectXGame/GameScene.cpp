#include "GameScene.h"

using namespace KamataEngine;

void GameScene::Initialize() { 
	modelParticle_ = Model::CreateSphere(4, 4);
	camera_.Initialize();

	particle_ = new Particle();

	particle_->Intialize(modelParticle_);
}


void GameScene::Update() { 
	
	particle_->Update();
}

void GameScene::Draw() { 
	DirectXCommon* dxcommon = DirectXCommon::GetInstance();

	Model::PreDraw(dxcommon->GetCommandList());

	particle_->Draw(camera_);

	Model::PostDraw();
}

GameScene::~GameScene() { 
	delete modelParticle_;
	delete particle_;
}