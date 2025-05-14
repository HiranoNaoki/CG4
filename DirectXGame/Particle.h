#pragma once

#include <KamataEngine.h>

using namespace KamataEngine;

class Particle{

	public:
	void Intialize(Model* model, Vector3 position, Vector3 velocity);

	void Update();

	void Draw(Camera& camera);

private:

	WorldTransform worldtransform_;

	Model* model_ = nullptr;

	ObjectColor objectcolor_;

	Vector4 color_;

	Vector3 velocity_;
};
