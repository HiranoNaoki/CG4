#include "Effect.h"
#include <random>

using namespace KamataEngine;
using namespace MathUtility;


void Effect::Initialize(KamataEngine::Model* model,KamataEngine::Vector3 pos ,float size,float rotate) {
	assert(model);

	model_ = model;
	
	worldTransform_.Initialize();

	//worldTransform_.translation_ = position;
	
	worldTransform_.scale_.y = size;


	worldTransform_.rotation_.z =rotate;

	
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
	
	objectColor_.SetColor(color_);
}

void Effect::Draw(KamataEngine::Camera& camera) {
	
	model_->Draw(worldTransform_, camera, &objectColor_);
}