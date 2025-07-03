#pragma once

#include <KamataEngine.h>
#include "Model2.h"

using namespace KamataEngine;

class Particle{

	public:
	void Intialize(Model2* model);

	void Update();

	void Draw(Camera& camera);

private:

	WorldTransform worldtransform_;

	Model2* model_ = nullptr;
};
