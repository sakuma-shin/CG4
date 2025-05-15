#include "GameScene.h"
#include <random>

using namespace KamataEngine;

using namespace MathUtility;

std::random_device seedGenerator;
std::mt19937 randomEngine(seedGenerator());
std::uniform_real_distribution<float> distribution(-1.0f, 1.0f);


GameScene::~GameScene() {
	delete modelEffect_;
	for (Effect* effect : effects_) {
		delete effect;
	}
}

void GameScene::Initialize() {
	modelEffect_ = Model::CreateFromOBJ("effect");
	camera_.Initialize();
	// 乱数の初期化
	srand((unsigned)time(NULL));
}

void GameScene::Update() {

	effects_.remove_if([](Effect* effect) {
		if (effect->IsFinished()) {
			delete effect;
			return true;
		}
		return false;
	});

	// 確率で発生
	if (rand() % 20 == 0) {
		// 位置
		Vector3 position = {distribution(randomEngine) * 30.0f, distribution(randomEngine) * 20.0f, 0};
		EffectBorn(position);
	}

	for (Effect* effect : effects_) {
		effect->Update();
	}
}

void GameScene::Draw() {
	DirectXCommon* dxCommon = DirectXCommon::GetInstance();

	Model::PreDraw(dxCommon->GetCommandList());
	for (Effect* effect : effects_) {
		effect->Draw(camera_);
	}
	Model::PostDraw();
}

void GameScene::EffectBorn(KamataEngine::Vector3 position) {
	Vector4 color = {abs(distribution(randomEngine)), abs(distribution(randomEngine)), abs(distribution(randomEngine)), 1.0f};
	for (int i = 0; i < 15; i++) {
		Vector3 scale = {0.05f, abs(distribution(randomEngine)) * 8.0f, 0.1f};
		float pi = 3.14f;
		Vector3 rotation = {0.0f, 0.0f, distribution(randomEngine) * pi};

		Effect* newEffect_ = new Effect();
		newEffect_->Initialize(modelEffect_, scale, rotation,position,color);
		effects_.push_back(newEffect_);
	}
}
