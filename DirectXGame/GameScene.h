#pragma once
#include "KamataEngine.h"
#include"Model2.h"
#include "IScene.h"
#include<vector>

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

	uint32_t bgGH = 0u;
	std::vector<KamataEngine::Sprite*> bgSprite_;
	std::vector<KamataEngine::Vector2> bgPos_;
};
