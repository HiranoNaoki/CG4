#include "GameScene.h"
#include <random>

using namespace KamataEngine;
using namespace MathUtility;


std::random_device seedGenerator;
std::mt19937 randomEngine(seedGenerator());
std::uniform_real_distribution<float> RandomSize(0.0f, 1.0f);
std::uniform_real_distribution<float> RandomRotation(-1.0f, 1.0f);
std::uniform_real_distribution<float> distribution(-1.0f, 1.0f);


void GameScene::Initialize() {
	modelEffect_ = Model::CreateFromOBJ("Hishigata", true);

	
	camera_.Initialize();

	//Vector3 position = {0.0f, 0.0f, 0.0f};

	srand((unsigned)time(NULL));
	
	//EffectBorn(position);
	
	
	//effect_->Initialize(modelEffect_);

	
}

void GameScene::Update() { 

	if (rand() % 20 == 0) {
		
		Vector3 position = {distribution(randomEngine) * 30.0f, distribution(randomEngine) * 20.0f, 0};
		
		EffectBorn(position);
	}

	for (Effect* effect : effectes_) {
	effect->Update(); 
	}
	effectes_.remove_if([](Effect* effect) {
		if (effect->IsFinished()) 
		{
			delete effect;
			return true;
		}
		return false;
	});
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

void GameScene::EffectBorn(Vector3 position) {
	for (int i = 0; i < 10; i++) {
		
		Effect* effect = new Effect();
		
		Vector3 pos = position;
		
		float size =RandomSize(randomEngine)* 10.0f ;


	   float rotate =RandomRotation(randomEngine)*20.0f ;


		effect->Initialize(modelEffect_, pos,size,rotate);
		
		effectes_.push_back(effect);
	}
}