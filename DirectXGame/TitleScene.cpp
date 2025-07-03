#include "TitleScene.h"
using namespace KamataEngine;

void TitleScene::Initialize() {
	bgGH = TextureManager::Load("titleScene.png");
	titleFontGH = TextureManager::Load("titleFont.png");
	hitFontGH = TextureManager::Load("titleFont2.png");

	bgSprite_ = Sprite::Create(bgGH, {0,0});
	titleFontSprite_ = Sprite::Create(titleFontGH, {0, 120.0f});
	hitFontSprite_= Sprite::Create(hitFontGH, {0, 600.0f});

	input_=Input::GetInstance();

}

void TitleScene::Update() {
	if (input_->TriggerKey(DIK_RETURN)) {
		sceneNo = STAGE;
	}
}

void TitleScene::Draw() {
	DirectXCommon* dxCommon = DirectXCommon::GetInstance();

	Sprite::PreDraw(dxCommon->GetCommandList());
	bgSprite_->Draw();
	titleFontSprite_->Draw();
	hitFontSprite_->Draw();
	Sprite::PostDraw();
}

TitleScene::~TitleScene() {
	delete bgSprite_; 
	delete titleFontSprite_;
	delete hitFontSprite_;
}
