#include "GameScene.h"

GameScene::~GameScene() {
	delete modelParticle_;
	for (Particle* particle : particles_) {
		delete particle;
	}
	particles_.clear();
}

void GameScene::Initialize() {

	modelParticle_ = Model::CreateSphere(4, 4);
	camera_.Initialize();

	for (int i = 0; i < 150; i++) {

		Particle* particle = new Particle();

		// 位置
		Vector3 position = {0.5f * i, 0.0f, 0.0f};

		particle->Initialize(modelParticle_, position);
		// リストに追加
		particles_.push_back(particle);
	}
}

void GameScene::Update() {
	for (Particle* particle : particles_) {
		particle->Update();
	}
}

void GameScene::Draw() {
	DirectXCommon* dxCommon = DirectXCommon::GetInstance();

	Model::PreDraw(dxCommon->GetCommandList());
	for (Particle* particle : particles_) {
		particle->Draw(camera_);
	}
	Model::PostDraw();
}
