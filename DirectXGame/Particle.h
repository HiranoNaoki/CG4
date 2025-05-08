#pragma once

#include <KamataEngine.h>

using namespace KamataEngine;

class Particle{

	public:
	void Intialize(Model* model, Vector3 position);

	void Update();

	void Draw(Camera& camera);

private:

	WorldTransform worldtransform_;

	Model* model_ = nullptr;

	ObjectColor objectcolor_;

	Vector4 color_;
};
