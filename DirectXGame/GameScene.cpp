#include "GameScene.h"
using namespace KamataEngine;

GameScene::~GameScene() { 
	Model2::StaticFinalize();
	delete model_; 
}

void GameScene::Initialize() {
	
	Model2::StaticInitialize();

	worldTransform_.Initialize();

	camera_.Initialize();
}

void GameScene::Update() {

}

void GameScene::Draw() { 
	DirectXCommon* dxCommon = DirectXCommon::GetInstance();

	Model2::PreDraw(dxCommon->GetCommandList());

	Model2::PostDraw();
}
