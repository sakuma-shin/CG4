#pragma once
#include "KamataEngine.h"
#include "Effect.h"

class GameScene {
public:
	~GameScene();

	void Initialize();
	void Update();
	void Draw();

private:
	KamataEngine::Model* modelEffect_ = nullptr;
	KamataEngine::Camera camera_;

	Effect* effect_ = nullptr;

};
