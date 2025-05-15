#pragma once
#include "KamataEngine.h"

class Effect {
public:
	void Initialize(KamataEngine::Model* model);
	void Update();
	void Draw(KamataEngine::Camera& camera);

private:
	KamataEngine::Model* model_ = nullptr;
	KamataEngine::WorldTransform worldTransform_;
};
