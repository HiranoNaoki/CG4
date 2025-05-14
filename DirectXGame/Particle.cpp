#include "Particle.h"

using namespace KamataEngine;

using namespace MathUtility;

void Particle::Intialize(Model* model, Vector3 position, Vector3 velocity) {
	assert(model);

	

	model_ = model;

	worldtransform_.Initialize();

	objectcolor_.Initialize();

	color_ = {1, 1, 0, 1};

	worldtransform_.translation_ = position;

	velocity_ = velocity;

	
}

void Particle::Update() { 
	worldtransform_.translation_ += velocity_;

	worldtransform_.UpdateMatrix();

	objectcolor_.SetColor(color_);

}

void Particle::Draw(Camera& camera) {


	model_->Draw(worldtransform_, camera, &objectcolor_);
	;

}

