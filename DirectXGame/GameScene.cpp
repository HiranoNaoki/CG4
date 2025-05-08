#include "GameScene.h"

using namespace KamataEngine;

void GameScene::Initialize() { 
	modelParticle_ = Model::CreateSphere(4, 4);
	camera_.Initialize();

	for (int i = 0; i < 150; i++) {

		particle_ = new Particle();

		Vector3 position = {0.5f* i, 0.0f, 0.0f};

		particle_->Intialize(modelParticle_, position);

		particles_.push_back(particle_);
	}
}


void GameScene::Update() { 
	for (  Particle* particle : particles_) {
	particle->Update();
	}
	
}

void GameScene::Draw() { 
	DirectXCommon* dxcommon = DirectXCommon::GetInstance();

	Model::PreDraw(dxcommon->GetCommandList());


	for (  Particle* particle : particles_) {
       particle->Draw(camera_);
	}
	

	Model::PostDraw();
}

GameScene::~GameScene() { 

	     delete modelParticle_;
	for (  Particle* particle : particles_) {

	delete particle;
	}
	
	particles_.clear();
}