#pragma once
#include "IScene.h"
#include"KamataEngine.h"
class TitleScene : public IScene {
public:
	void Initialize()override;

	void Update() override;

	void Draw() override;

	~TitleScene();

private:
	uint32_t bgGH = 0u;
	uint32_t titleFontGH = 0u;
	uint32_t hitFontGH = 0u;

	KamataEngine::Sprite* bgSprite_ = nullptr;
	KamataEngine::Sprite* titleFontSprite_ = nullptr;
	KamataEngine::Sprite* hitFontSprite_ = nullptr;

	KamataEngine::Input* input_ = nullptr;
};
