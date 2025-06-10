#pragma once
#include <KamataEngine.h>

using namespace KamataEngine;
using namespace MathUtility;

class Effect {
public:

	void Initialize(KamataEngine::Model* model,KamataEngine::Vector3 pos,float size,float rotate);

	
	void Update();

	
	void Draw(KamataEngine::Camera& camera);

	bool IsFinished() { return isFinished_; }



private:
	KamataEngine::WorldTransform worldTransform_;
	
	KamataEngine::Model* model_ = nullptr;
	
	KamataEngine::ObjectColor objectColor_;
	
	KamataEngine::Vector4 color_;

	

	KamataEngine::Vector3 startScale_; 
	KamataEngine::Vector3 targetScale_; 

	bool isFinished_ = false;

	float counter_ = 0.0f;

	const float kDuration = 1.0f;
};
