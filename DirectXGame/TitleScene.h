#pragma once
#include "IScene.h"
#include"KamataEngine.h"
#include "Model2.h"

class TitleScene : public IScene {
public:
	void Initialize()override;

	void Update() override;

	void Draw() override;

	~TitleScene();

private:
	KamataEngine::Camera camera_;
	KamataEngine::WorldTransform worldTransform_;

	uint32_t textureHandle_ = 0u;
	KamataEngine::Sprite* sprite_ = nullptr;

	KamataEngine::Input* input_ = nullptr;
};
