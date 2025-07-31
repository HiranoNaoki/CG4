#include "GameScene.h"
#include <cmath>

using namespace KamataEngine;

void GameScene::Initialize() { 
	modelParticle_ = Model2::CreateSquare();
	camera_.Initialize();

	particle_ = new Particle();

	particle_->Intialize(modelParticle_);
	Model2::StaticInitialize();

	textureHandle = TextureManager::Load("start.png");

	sprite_ = Sprite::Create(textureHandle, {0, 0});
	sprite_2 = Sprite::Create(textureHandle, {0, 0});

	guraf_ = new Guraf();
	guraf_->Initialize();

	number_ = new Num();
	number_-> Initialize();
}



void GameScene::Update() { 
	
	particle_->Update();


	frame++;

float y = 45 * sin(frame * 0.05f);

move--;

float x = 0.0f + move;

sprite_->SetPosition({x, y});
sprite_2->SetPosition({1280 + x, y});
if (x <= -1280) {
	move = 0;
}

guraf_->Update();

number_->Update();
}

void GameScene::Draw() { 
	DirectXCommon* dxcommon = DirectXCommon::GetInstance();

	

	Sprite::PreDraw(dxcommon->GetCommandList());


	//if (frame %60 >=30) {
		sprite_->Draw();
	sprite_2->Draw();


	//}
	
	Sprite::PostDraw(); 

	dxcommon->ClearDepthBuffer();

	Model2::PreDraw(dxcommon->GetCommandList());

	particle_->Draw(camera_);


	Model2::PostDraw();

	Sprite::PreDraw(dxcommon->GetCommandList());

	
	guraf_->Draw();

	number_->Draw();

	Sprite::PostDraw();
}

GameScene::~GameScene() { 
	delete modelParticle_;
	delete particle_;
	Model2::StaticFinalize();
}