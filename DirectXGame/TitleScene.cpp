#include "TitleScene.h"
using namespace KamataEngine;

void TitleScene::Initialize() {
	Model2::StaticInitialize();

	worldTransform_.Initialize();

	camera_.Initialize();

	input_=Input::GetInstance();
	textureHandle_ = TextureManager::Load("white1x1.png");

	sprite_=Sprite::Create(textureHandle_, {0, 0});
	sprite_->SetSize({1280.0f, 720.0f});
}

void TitleScene::Update() {
	if (input_->TriggerKey(DIK_RETURN)) {
		sceneNo = STAGE;
	}
}

void TitleScene::Draw() {
	DirectXCommon* dxCommon = DirectXCommon::GetInstance();

	Sprite::PreDraw(dxCommon->GetCommandList());

	sprite_->Draw();

	Sprite::PostDraw();

	dxCommon->ClearDepthBuffer();

	Model2::PreDraw(dxCommon->GetCommandList());

	Model2::PostDraw();

	Sprite::PreDraw(dxCommon->GetCommandList());

	Sprite::PostDraw();
}

TitleScene::~TitleScene() {
	Model2::StaticFinalize(); 
	delete sprite_;
}
