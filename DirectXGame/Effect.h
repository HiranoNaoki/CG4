#pragma once
#include <KamataEngine.h>

class Effect {
public:
	void Initialize(KamataEngine::Model* model);
	
	void Update();
	
	void Draw(KamataEngine::Camera& camera);

private:
	
	KamataEngine::WorldTransform worldTransform_;
	
	KamataEngine::Model* model_ = nullptr;

};
