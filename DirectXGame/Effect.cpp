#include "Effect.h"
#include <random>

using namespace KamataEngine;
using namespace MathUtility;


std::random_device seedGenerator;
std::mt19937 randomEngine(seedGenerator());
std::uniform_real_distribution<float> RandomSize(0.0f, 1.0f);
std::uniform_real_distribution<float> RandomRotation(-1.0f, 1.0f);

void Effect::Initialize(KamataEngine::Model* model) {
	assert(model);

	model_ = model;
	
	worldTransform_.Initialize();

	//worldTransform_.translation_ = position;
	
	worldTransform_.scale_.y =RandomSize(randomEngine)* 10.0f ;


	worldTransform_.rotation_.z =RandomRotation(randomEngine)*20.0f ;

	
	objectColor_.Initialize();
	color_ = {1, 1, 0, 1};

	
	

}

void Effect::Update() {

	
	worldTransform_.UpdateMatrix();
	
	objectColor_.SetColor(color_);
}

void Effect::Draw(KamataEngine::Camera& camera) {
	
	model_->Draw(worldTransform_, camera, &objectColor_);
}