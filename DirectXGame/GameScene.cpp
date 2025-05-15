#include "GameScene.h"
#include <random>

using namespace KamataEngine;

using namespace MathUtility;

std::random_device seedGenerator;
std::mt19937 randomEngine(seedGenerator());
std::uniform_real_distribution<float> distribution(-1.0f, 1.0f);


GameScene::~GameScene() {
	delete modelEffect_;
	delete effect_;
}

void GameScene::Initialize() {
	modelEffect_ = Model::CreateFromOBJ("effect");
	camera_.Initialize();
	// 乱数の初期化
	srand((unsigned)time(NULL));

	
	Vector3 scale = {1.0f, abs(distribution(randomEngine)), 1.0f};
	float pi = 3.14f;
	Vector3 rotation = {0.0f, 0.0f, pi * distribution(randomEngine)};

	effect_ = new Effect();
	effect_->Initialize(modelEffect_,scale,rotation);
}

void GameScene::Update() { effect_->Update(); }

void GameScene::Draw() {
	DirectXCommon* dxCommon = DirectXCommon::GetInstance();

	Model::PreDraw(dxCommon->GetCommandList());
	effect_->Draw(camera_);
	Model::PostDraw();
}
