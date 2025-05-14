#include "GameScene.h"

GameScene::~GameScene() {
	delete modelParticle_; 
	delete particle_;
}

void GameScene::Initialize() { 
	modelParticle_ = Model::CreateSphere(4, 4);
	camera_.Initialize();

	particle_ = new Particle();

	particle_->Initialize(modelParticle_);
}

void GameScene::Update() {
	particle_->Update(); 
}

void GameScene::Draw() {
	DirectXCommon* dxCommon = DirectXCommon::GetInstance();

	Model::PreDraw(dxCommon->GetCommandList());
	particle_->Draw(camera_); 
	Model::PostDraw();
}
