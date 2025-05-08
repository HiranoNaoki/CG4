#include "Particle.h"

using namespace KamataEngine;

using namespace MathUtility;

void Particle::Intialize(Model* model, Vector3 position) {
	assert(model);

	

	model_ = model;

	worldtransform_.Initialize();

	objectcolor_.Initialize();

	color_ = {1, 1, 0, 1};

	worldtransform_.translation_ = position;

	
}

void Particle::Update() { 
	worldtransform_.translation_ += {0.0f, 0.1f, 0.0f};

	worldtransform_.UpdateMatrix();

	objectcolor_.SetColor(color_);

}

void Particle::Draw(Camera& camera) {


	model_->Draw(worldtransform_, camera, &objectcolor_);
	;

}

