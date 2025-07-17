#pragma once
#include "KamataEngine.h"
#include"Model2.h"
#include "IScene.h"
#include<vector>
#include"Player.h"

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

	Player* player_ = nullptr;

	uint32_t bgGH = 0u;
	std::vector<KamataEngine::Sprite*> bgSprite_;
	std::vector<KamataEngine::Vector2> bgPos_;

	uint32_t hpGH = 0u;
	KamataEngine::Sprite* hpGreenSprite_ = nullptr;
	KamataEngine::Sprite* hpRedSprite_ = nullptr;

	KamataEngine::Model2* playerModel_ = nullptr;

	uint32_t numGH = 0u;
	KamataEngine::Sprite* numSprite_[5] = {};
	KamataEngine::Vector2 numSize = {32.0f, 64.0f};

	int32_t number = 0;

};
