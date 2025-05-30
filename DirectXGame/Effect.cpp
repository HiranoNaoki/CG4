#include "Effect.h"
using namespace KamataEngine;
void Effect::Initialize(Model* model) {
	
	assert(model);
	model_ = model;

	worldTransform_.Initialize();
}

void Effect::Update() { worldTransform_.TransferMatrix(); }

void Effect::Draw(Camera& camera) { model_->Draw(worldTransform_, camera); }
