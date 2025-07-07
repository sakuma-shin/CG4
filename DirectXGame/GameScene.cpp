#include "GameScene.h"
using namespace KamataEngine;

GameScene::~GameScene() { 
	Model2::StaticFinalize();
}

void GameScene::Initialize() {
	
	Model2::StaticInitialize();

	worldTransform_.Initialize();

	camera_.Initialize();

	input_ = Input::GetInstance();   
}

void GameScene::Update() {
	if (input_->TriggerKey(DIK_RETURN)) {
		sceneNo = RESULT;
	}
}

void GameScene::Draw() { 
	DirectXCommon* dxCommon = DirectXCommon::GetInstance();

	Sprite::PreDraw(dxCommon->GetCommandList());

	Sprite::PostDraw();

	dxCommon->ClearDepthBuffer();

	Model2::PreDraw(dxCommon->GetCommandList());

	Model2::PostDraw();

	Sprite::PreDraw(dxCommon->GetCommandList());

	Sprite::PostDraw();
}
