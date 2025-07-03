#include "GameScene.h"

using namespace KamataEngine;

void GameScene::Initialize() { 
	modelParticle_ = Model2::CreateSphere(4, 4);
	camera_.Initialize();

	particle_ = new Particle();

	particle_->Intialize(modelParticle_);
	Model2::StaticInitialize();
}


void GameScene::Update() { 
	
	particle_->Update();
}

void GameScene::Draw() { 
	DirectXCommon* dxcommon = DirectXCommon::GetInstance();

	Model2::PreDraw(dxcommon->GetCommandList());

	particle_->Draw(camera_);

	Model2::PostDraw();
}

GameScene::~GameScene() { 
	delete modelParticle_;
	delete particle_;
	Model2::StaticFinalize();
}