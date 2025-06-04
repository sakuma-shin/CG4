#pragma once
#include "KamataEngine.h"
#include"Model2.h"

class GameScene {
public:
	~GameScene();

	void Initialize();
	void Update();
	void Draw();

private:
	KamataEngine::Camera camera_;
	KamataEngine::WorldTransform worldTransform_;

	KamataEngine::Model2* model_ = nullptr;
};
