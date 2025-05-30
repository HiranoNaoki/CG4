#pragma once
#include <KamataEngine.h>

using namespace KamataEngine;
using namespace MathUtility;

class Effect {
public:

	void Initialize(KamataEngine::Model* model);

	
	void Update();

	
	void Draw(KamataEngine::Camera& camera);

private:
	KamataEngine::WorldTransform worldTransform_;
	
	KamataEngine::Model* model_ = nullptr;
	
	KamataEngine::ObjectColor objectColor_;
	
	KamataEngine::Vector4 color_;

	

	KamataEngine::Vector3 startScale_; 
	KamataEngine::Vector3 targetScale_; 
};
