#pragma once

#include <KamataEngine.h>


class WorldTransfirmEx :

    public KamataEngine::WorldTransform {

public:
	void UpdateMatrix();

	KamataEngine::Matrix4x4 MakeAffineMatrix();


};



