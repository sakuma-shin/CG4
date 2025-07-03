#include "GameScene.h"
using namespace KamataEngine;

GameScene::~GameScene() { 
	Model2::StaticFinalize();
	delete model_; 
}

void GameScene::Initialize() {
	
	Model2::StaticInitialize();

	worldTransform_.Initialize();
	worldTransform_.rotation_ = {0.0f, 0.8f, 0.5f};

	camera_.Initialize();

	model_ = new Model2();
	model_ = Model2::CreateRing(64, "ring.png");
}

void GameScene::Update() {
	worldTransform_.scale_.x *= 1.1f;
	worldTransform_.scale_.y *= 1.1f;
	worldTransform_.scale_.z *= 1.1f;

	worldTransform_.UpdateMatrix();

}

void GameScene::Draw() { 
	DirectXCommon* dxCommon = DirectXCommon::GetInstance();

	Model2::PreDraw(dxCommon->GetCommandList());
	model_->Draw(worldTransform_,camera_); 
	Model2::PostDraw();
}
