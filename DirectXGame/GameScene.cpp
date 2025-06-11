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

	model_ = new Model2();
	model_=Model2::CreateRing(32);
}

void GameScene::Update() {
}

void GameScene::Draw() { 
	DirectXCommon* dxCommon = DirectXCommon::GetInstance();

	Model2::PreDraw(dxCommon->GetCommandList());
	model_->Draw(worldTransform_,camera_); 
	Model2::PostDraw();
}
