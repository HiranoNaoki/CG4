#pragma once

#include <KamataEngine.h>

using namespace KamataEngine;

class Particle{

	public:
	void Intialize();

	void Update();

	void Draw();

	

private:

	WorldTransform worldtransform_;

	Model* model_ = nullptr;

};
