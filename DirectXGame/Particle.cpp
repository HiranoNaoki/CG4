#include "Particle.h"


using namespace KamataEngine;

void Particle::Intialize(Model2* model) {
	assert(model);

	model_ = model;

	worldtransform_.Initialize();
}

void Particle::Update() { 


	worldtransform_.TransferMatrix();



}

void Particle::Draw(Camera& camera) {


	model_->Draw(worldtransform_, camera);

}

