#include "Effect.h"

using namespace KamataEngine;
using namespace MathUtility;

void Effect::Initialize(KamataEngine::Model* model, Vector3 position) {
	assert(model);

	model_ = model;
	
	worldTransform_.Initialize();
	
	objectColor_.Initialize();
	color_ = {1, 1, 0, 1};

	worldTransform_.translation_ = position;

}

void Effect::Update() {

	
	worldTransform_.TransferMatrix();
	
	objectColor_.SetColor(color_);
}

void Effect::Draw(KamataEngine::Camera& camera) {
	
	model_->Draw(worldTransform_, camera, &objectColor_);
}