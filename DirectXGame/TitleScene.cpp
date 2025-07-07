#include "TitleScene.h"
using namespace KamataEngine;

void TitleScene::Initialize() {
	Model2::StaticInitialize();

	worldTransform_.Initialize();

	camera_.Initialize();

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


	Sprite::PostDraw();

	dxCommon->ClearDepthBuffer();

	Model2::PreDraw(dxCommon->GetCommandList());

	Model2::PostDraw();

	Sprite::PreDraw(dxCommon->GetCommandList());

	Sprite::PostDraw();
}

TitleScene::~TitleScene() {
	Model2::StaticFinalize(); 
}
