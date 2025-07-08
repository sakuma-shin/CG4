#pragma once
#include "KamataEngine.h"
#include"Model2.h"
class Player {
public:
	void Initialize(KamataEngine::Model2 *model);

	void Update();

	void Draw(KamataEngine::Camera &camera);

private:

	KamataEngine::Input *input_ = nullptr;
	KamataEngine::WorldTransform worldTransform_;

	KamataEngine::Model2 *model_ = nullptr;

	const float pi = 3.14f;

};
