#pragma once
#include "KamataEngine.h"
#include"Model2.h"
#include "IScene.h"

class GameScene:public IScene{
public:
	~GameScene();

	void Initialize() override;
	void Update() override;
	void Draw() override;

private:
	KamataEngine::Camera camera_;
	KamataEngine::WorldTransform worldTransform_;

	KamataEngine::Input* input_ = nullptr;
};
