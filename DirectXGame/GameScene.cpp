#include "GameScene.h"


void GameScene::Initialize() { 
	dxCommon_ = DirectXCommon::GetInstance();
	
	input_ = Input::GetInstance();
	
	audio_ = Audio::GetInstance();

	
	modelEffect_ = Model::CreateFromOBJ("Plane");
	
	effect_ = new Effect();
	effect_->Initialize(modelEffect_);

	camera_.Initialize();
}


void GameScene::Update() { effect_->Update(); }

void GameScene::Draw() { 
	ID3D12GraphicsCommandList* commandList = dxCommon_->GetCommandList();


	Sprite::PreDraw(commandList);

	
	Sprite::PostDraw();
	
	dxCommon_->ClearDepthBuffer();

	
	Model::PreDraw(commandList);

	

	effect_->Draw(camera_);

	
	Model::PostDraw();

	
	Sprite::PreDraw(commandList);

	Sprite::PostDraw();

#
}

