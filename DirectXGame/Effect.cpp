#include "Effect.h"
#include <random>

using namespace KamataEngine;
using namespace MathUtility;


std::random_device seedGenerator;
std::mt19937 randomEngine(seedGenerator());
std::uniform_real_distribution<float> RandomSize(0.0f, 1.0f);
std::uniform_real_distribution<float> RandomRotation(-1.0f, 1.0f);

void Effect::Initialize(KamataEngine::Model* model,KamataEngine::Vector3 pos) {
	assert(model);

	model_ = model;
	
	worldTransform_.Initialize();

	//worldTransform_.translation_ = position;
	
	worldTransform_.scale_.y =RandomSize(randomEngine)* 10.0f ;


	worldTransform_.rotation_.z =RandomRotation(randomEngine)*20.0f ;

	
	objectColor_.Initialize();
	color_ = {1, 1, 0, 1};

	worldTransform_.translation_ = pos;
	

}

void Effect::Update() {

	
	if (isFinished_) {
		return;
	}

	counter_ += 1.0f / 60.0f;

	if (counter_ >= kDuration) {
		counter_ = kDuration;

		    isFinished_ = true;
	}

	color_.w = std::clamp(1.0f -counter_ / kDuration,0.0f,1.0f);

	
	worldTransform_.TransferMatrix();

	worldTransform_.UpdateMatrix();
	
	//objectColor_.SetColor(color_);
}

void Effect::Draw(KamataEngine::Camera& camera) {
	
	model_->Draw(worldTransform_, camera, &objectColor_);
}