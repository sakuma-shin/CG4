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
	KamataEngine::Model* modelEffect_ = nullptr;
	KamataEngine::Camera camera_;

	Model2* model_ = nullptr;
};
