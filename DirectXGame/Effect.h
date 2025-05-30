#pragma once
#include <KamataEngine.h>

using namespace KamataEngine;
using namespace MathUtility;

class Effect {
public:

	void Initialize(KamataEngine::Model* model, Vector3 position);

	
	void Update();

	
	void Draw(KamataEngine::Camera& camera);

private:
	KamataEngine::WorldTransform worldTransform_;
	
	KamataEngine::Model* model_ = nullptr;
	
	KamataEngine::ObjectColor objectColor_;
	
	KamataEngine::Vector4 color_;

};
