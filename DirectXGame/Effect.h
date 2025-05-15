#pragma once
#include "KamataEngine.h"

class Effect {
public:
	void Initialize(KamataEngine::Model* model,KamataEngine::Vector3 scale,KamataEngine::Vector3 rotation);
	void Update();
	void Draw(KamataEngine::Camera& camera);

private:
	KamataEngine::Model* model_ = nullptr;
	KamataEngine::WorldTransform worldTransform_;
};
