#pragma once

#include <KamataEngine.h>

using namespace KamataEngine;

class Particle{

	public:
	void Intialize(Model* model);

	void Update();

	void Draw(Camera& camera);

private:

	WorldTransform worldtransform_;

	Model* model_ = nullptr;
};
