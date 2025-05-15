#pragma once
#include "KamataEngine.h"

class GameScene {
public:
	~GameScene();

	void Initialize();
	void Update();
	void Draw();

private:
	KamataEngine::Model* modelEffect_ = nullptr;
	KamataEngine::Camera camera_;
};
